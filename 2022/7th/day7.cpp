#include <memory>
#include "../solutions.hh"

struct file_tree_node
{
  file_tree_node(std::string name) : m_name(name) {};
  int findChild(const std::string& name) 
  {
    for (int i=0; i<m_children.size(); i++) if (m_children.at(i)->m_name == name) return i;
    return -1;
  }

  std::string m_name;
  std::shared_ptr<file_tree_node> m_parent;
  std::vector<std::shared_ptr<file_tree_node>> m_children;
  int m_size = 0;
};

using ftn = file_tree_node;
using ftnp = std::shared_ptr<ftn>;

ftnp construct_tree(std::ifstream& file)
{
  std::string row;
  ftnp node; 
  while (getline(file, row))
  {
    if (row.find("$ cd") == 0)
    {
      if (row.at(5) == '/') node = std::make_shared<ftn>("/");
      else if (row.find("..") == 5) node = node->m_parent;
      else node = node->m_children.at(node->findChild(row.substr(5)));
    }
    if (row.find("dir") == 0) 
    {
      node->m_children.push_back(std::make_shared<ftn>(row.substr(4)));
      node->m_children.back()->m_parent = node;
    }
    else if (isdigit(row.front())) 
    {
      node->m_size += stoi(row.substr(0, row.find(' ')));
    }
  }
  while (node->m_name != "/") node = node->m_parent;
  return node;
}

int calc_sizes(ftnp node)
{
  if (node->m_children.size() == 0) return node->m_size;
  else for (auto child : node->m_children) 
  {
    node->m_size += calc_sizes(child);
  }
  return node->m_size;
}

int part1(ftnp node)
{
  int sum = 0;
  if (node->m_children.size() == 0) return node->m_size<100000?node->m_size:0;
  else for (auto child : node->m_children) 
  {
    sum += part1(child);
  }
  return sum + (node->m_size<100000?node->m_size:0);
}

int part2(ftnp node, int minToDelete)
{
  if (node->m_children.size() == 0) return node->m_size;
  int min = node->m_size;
  for (auto child : node->m_children)
  {
    int x = part2(child, minToDelete);
    if (x < min && x > minToDelete) min = x;
  }
  return min;
}

std::pair<std::string, std::string> day7(std::ifstream file)
{
  std::string row;
  ftnp node = construct_tree(file);
  int sum1 = 0;
  node->m_size = calc_sizes(node);

  int totalSpace = 70000000;
  int reqSpace = 30000000;
  int minToDelete = reqSpace - (totalSpace - node->m_size);

  return {std::to_string(part1(node)), std::to_string(part2(node, minToDelete))};
}