#include <memory>
#include "../solutions.hh"

struct vec2
{
  vec2(int a, int b) : x(a), y(b){}
  int x;
  int y;
  int len() {return abs(x)+abs(y);}
};

inline bool operator==(const vec2& lhs, const vec2& rhs) {return lhs.x==rhs.x && lhs.y==rhs.y;}

struct Hash
{
  size_t operator()(const vec2& vec) const { return (vec.x<<12)+vec.y;}
};

vec2 diff(vec2 a, vec2 b) {return vec2(b.x-a.x, b.y-a.y);}

struct knot
{
  knot(int size, knot* next=nullptr) :
    m_loc(0,0), m_next(next), m_prev(nullptr)
  {
    if (size > 1) m_prev = new knot(size-1, this);
  }

  ~knot()
  {
    knot* tail = get_tail();
    while(tail->m_next != nullptr)
    {
      tail = tail->m_next;
      delete tail->m_prev;
    }
  }

  // Moves the knot and all following knots respectively
  vec2 move(char cmd)
  {
      if (cmd == 'U')      ++m_loc.y;
      else if (cmd == 'D') --m_loc.y;
      else if (cmd == 'R') ++m_loc.x;
      else if (cmd == 'L') --m_loc.x;

      knot* prev = m_prev;
      while (prev != nullptr)
      {
        prev->close_gap();
        prev = prev->m_prev;
      }
      return m_loc;
  }

  vec2 close_gap()
  {
    vec2 gap = diff(m_loc, m_next->m_loc);
    if (gap.len() >= 3 )
    {
      m_loc.x += gap.x/abs(gap.x);
      m_loc.y += gap.y/abs(gap.y);
      gap.x -= gap.x/abs(gap.x);
      gap.y -= gap.y/abs(gap.y);
    }
    else if (abs(gap.x) == 2)
    {
      m_loc.x += gap.x/abs(gap.x);
      gap.x -= gap.x/abs(gap.x);
    }
    else if (abs(gap.y) == 2)
    {
      m_loc.y += gap.y/abs(gap.y);
      gap.y -= gap.y/abs(gap.y);
    }
    return m_loc;
  }
  
  knot* get_tail()
  {
    if (m_prev == nullptr) return this;
    else return m_prev->get_tail();
  }

  vec2 m_loc;
  knot* m_next; // Towards head
  knot* m_prev; // Towards tail
};

std::pair<std::string, std::string> day9(std::ifstream file)
{
  std::string row;
  std::unordered_set<vec2, Hash> history;
  knot* rope = new knot(2);
  std::unordered_set<vec2, Hash> history2;
  knot* rope2 = new knot(10);
  while (getline(file, row))
  {
    for (int i = 0; i < std::stoi(row.substr(2)); ++i)
    {    
      rope->move(row.at(0));
      history.insert(rope->get_tail()->m_loc);
      rope2->move(row.at(0));
      history2.insert(rope2->get_tail()->m_loc);
    }
  }
  // delete rope / commented because this is somehow broken;
  return {std::to_string(history.size()), std::to_string(history2.size())};
}