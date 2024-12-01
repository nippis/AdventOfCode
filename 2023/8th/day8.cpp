#include "../solutions.hh"

int node_to_int(const std::string& nodecode)
{
  if (nodecode.size() == 1) return nodecode.at(0);
  else return nodecode.at(2)*pow(128, 0) + nodecode.at(1)*pow(128,1) + nodecode.at(0)*pow(128,2);
}

std::string int_to_node(int nodecode)
{
  std::string node;
  char b = nodecode%128;
  int a = nodecode/128;
  node.push_back(b);
  b = a%128;
  a = a/128;
  node.push_back(b);
  b = a%128;
  a = a/128;
  node.push_back(b);
  std::reverse(node.begin(), node.end());
  return node;
}

struct Node
{
  int code;
  Node* left;
  Node* right;
};

std::pair<std::string, std::string> day8::solve(std::ifstream f)
{
  std::unordered_map<int, std::pair<int, int>> nodes;
  std::unordered_map<int, Node> nodesb;

  std::string instructions;
  getline(f, instructions);
  
  std::string line;
  while (getline(f, line))
  {
    if (line.empty()) continue;
    std::string start, left, right;
    std::string* node_input = &start;
    for (char a : line)
    {
      if (a != ' ' && a != '=' && a != '(' && a != ',' && a != ')')
        node_input->push_back(a);
      else if (a == ' ' && !node_input->empty())
        node_input = &left;
      else if (a == ',' && !node_input->empty())
        node_input = &right;
    }
    nodes.insert({node_to_int(start), {node_to_int(left), node_to_int(right)}});
    nodesb.insert({node_to_int(start), {node_to_int(start), nullptr, nullptr}});
  }


  // Part A
  int steps = 0;
  int i = 0;
  int goal = node_to_int("ZZZ");
  int node = node_to_int("AAA");

  while (node != goal)
  {
    if (i == instructions.size()) i = 0;
    if (instructions.at(i) == 'L') node = nodes.at(node).first;
    else if (instructions.at(i) == 'R') node = nodes.at(node).second;
    i++;
    steps++;
  }

   return {std::to_string(steps), ""};

  // Part B
  for (auto& [key, value] : nodes)
  {
    nodesb.at(key).left = &nodesb.at(value.first);
    nodesb.at(key).right = &nodesb.at(value.second);
  }

  std::vector<Node*> curr_nodes;

  for (auto& [key, value]: nodesb)
  {
    if ((key&127) == 'A') 
    {
      curr_nodes.push_back(&value);
      std::cout << int_to_node(key) << " ";
    }
  }
  std::cout << std::endl;

  long long stepsb = 0;
  i = 0;
  std::vector<bool> instr;
  for (auto a : instructions) 
  {
    if (a == 'L') instr.push_back(true);
    else if (a == 'R') instr.push_back(false);
  }

  while (!std::all_of(curr_nodes.begin(), curr_nodes.end(), 
    [](Node* x) {return ((x->code)&127) == 'Z';}))
  {
    if (i == instructions.size()) i = 0;
    for (Node* node : curr_nodes)
    {
      if (instr[i]) node = node->left;
      else node = node->right;
    }
    i++;
    stepsb++;
    if (stepsb % 1000000000 == 0) std::cout << stepsb << std::endl;
  }

  /*std::vector<long long> s_to_f;
  std::vector<long long> cycles;
  for (Node* node : curr_nodes)
  {
    int nodesteps = 0;
    int i = 0;
    while (((node->code)&127) != 'Z')
    {
      if (i == instructions.size()) i = 0;
      if (instructions.at(i) == 'L') node = node->left;
      else if (instructions.at(i) == 'R') node = node->right;
      i++;
      nodesteps++;
    }
    std::cout << nodesteps << " ";
    s_to_f.push_back(nodesteps);
    std::cout << std::endl;

    nodesteps = 0;
    do 
    {
      if (i == instructions.size()) i = 0;
      if (instructions.at(i) == 'L') node = node->left;
      else if (instructions.at(i) == 'R') node = node->right;
      i++;
      nodesteps++;
    }
    while (((node->code)&127) != 'Z');
    std::cout << nodesteps << " ";
    cycles.push_back(nodesteps);
    std::cout << std::endl;
  }
  while ( stepsb % cycles.at(0) != 0 ||
          stepsb % cycles.at(1) != 0 ||
          stepsb % cycles.at(2) != 0 ||
          stepsb % cycles.at(3) != 0 ||
          stepsb % cycles.at(4) != 0 )
    {
      stepsb++;
      if (stepsb % 1000000000 == 0) std::cout << stepsb << std::endl;
    }*/


  return {std::to_string(steps), std::to_string(stepsb)};
}