#include "../solutions.hh"

int get_value(const char& card)
{
  if (card == 'A') return 14;
  else if (card == 'K') return 13;
  else if (card == 'Q') return 12;
  else if (card == 'J') return 11;
  else if (card == 'T') return 10;
  else return card-48;
}

int get_value_b(const char& card)
{
  if (card == 'A') return 14;
  else if (card == 'K') return 13;
  else if (card == 'Q') return 12;
  else if (card == 'J') return 1;
  else if (card == 'T') return 10;
  else return card-48;
}

enum HandType
{
  high = 0,
  pair = 1,
  two_pairs = 2,
  three = 3,
  full_house = 4,
  four = 5,
  five = 6
};

class Hand
{
  public:
  Hand(std::array<int, 5>& hand, int bet);
  virtual ~Hand();

  bool operator <(const Hand& r) const
  {
    if (m_type < r.m_type) return true;
    else if (m_type > r.m_type) return false;
    else
    {
      for (int i = 0; i < this->m_hand.size(); i++)
      {
        if (m_hand.at(i) < r.m_hand.at(i)) return true;
        else if (m_hand.at(i) > r.m_hand.at(i)) return false;
      }
      return false;
    }
  }

  int get_bet() {return m_bet;}
  std::array<int, 5> get_hand() {return m_hand;}

  private:
  HandType find_type();

  std::array<int, 5> m_hand;
  HandType m_type;
  int m_bet;
};

Hand::Hand(std::array<int, 5>& hand, int bet) : m_hand(hand), m_bet(bet)
{
  m_type = find_type();
}

Hand::~Hand() {}

HandType Hand::find_type()
{
  for (int x = 2; x < 15; x++)
  {
    int count = std::count(m_hand.begin(), m_hand.end(), x);
    if (count == 5) return HandType::five;
    else if (count == 4) return HandType::four;
    else if (count == 3)
    {
      for (int y = 2; y < 15; y++)
      {
        int count2 = std::count(m_hand.begin(), m_hand.end(), y);
        if (count2 == 2) return HandType::full_house;
      }
      return HandType::three;
    }
    else if (count == 2)
    {
      for (int y = 2; y < 15; y++)
      {
        if (y == x) continue;
        int count2 = std::count(m_hand.begin(), m_hand.end(), y);
        if (count2 == 2) return HandType::two_pairs;
        else if (count2 == 3) return HandType::full_house;
      }
      return HandType::pair;
    }
  }
  return HandType::high;
}

std::pair<std::string, std::string> day7::solve(std::ifstream f)
{
  std::set<Hand> hands;
  std::set<Hand> hands_b;

  std::string line;
  while (getline(f, line))
  {
    std::stringstream line_stream(line);
    char a;
    std::array<int, 5> cards;
    std::array<int, 5> cards_b;
    int i = 0;
    while (true)
    {
      line_stream.get(a);
      if (a == ' ') break;
      else
      {
        cards.at(i) = get_value(a);
        cards_b.at(i) = get_value_b(a);
      }
      i++;
    }
    std::string betstr;
    while (line_stream.get(a)) betstr.push_back(a);
    int bet = stoi(betstr);
    hands.insert(Hand(cards, bet));
    hands_b.insert(Hand(cards_b, bet));
  }

  long long sum = 0;
  int i = 1;

  for (auto hand : hands)
  {
    sum += hand.get_bet()*i;
    std::cout << "Rank: " << i << " Bet: " << hand.get_bet() << " Hand: ";
    for (int card : hand.get_hand()) std::cout << card << " ";
    std::cout << std::endl;
    i++;
  }
  return {std::to_string(sum),""};
}