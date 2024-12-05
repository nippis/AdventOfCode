#include "../solutions.hh"

using namespace std;
pair<string, string> day05::solve(ifstream f)
{
  vector<pair<int, int>> rs;
  string l;
  while (getline(f, l) && !l.empty())
    rs.push_back({stoi(l.substr(0, 2)), stoi(l.substr(3, 2))});
  int s1 = 0, s2 = 0;
  while (getline(f, l))
  {
    string u;
    for (int i = 0; i < l.size(); i += 3) u.push_back(stoi(l.substr(i, 2)));
    auto c = [=](int a, int b)
    {
      return any_of(rs.begin(), rs.end(), 
      [=](auto r) {return r.first == a && r.second == b;});
    };
    if (is_sorted(u.begin(), u.end(), c) && (s1 += u.at(u.size()/2))) continue;
    sort(u.begin(), u.end(), c);
    s2 += u.at(u.size()/2);
  }
  return {to_string(s1), to_string(s2)};
}