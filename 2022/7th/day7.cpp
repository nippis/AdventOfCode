#include "../solutions.hh"

typedef struct file_tree_node
{
  file_tree_node(const std::string& name, file_tree_node* parent = nullptr) : m_name(name), m_parent(parent) {};
  ~file_tree_node() {for (auto child : m_children) delete child;}
  file_tree_node* findChild(const std::string& name) 
  {
    for (auto child : m_children) if (child->m_name == name) return child;
    return nullptr;
  }

  std::string m_name;
  file_tree_node* m_parent;
  std::vector<file_tree_node*> m_children;
  int m_size = 0;
} ftn;

ftn* construct_tree(std::ifstream& file)
{
  std::string row;
  ftn* node; 
  while (getline(file, row))
  {
    if (!row.find("$ cd"))
    {
      if (row.at(5) == '/') node = new ftn("/");
      else if (row.find("..") == 5) node = node->m_parent;
      else node = node->findChild(row.substr(5));
    }
    else if (!row.find("dir")) node->m_children.push_back(new ftn(row.substr(4), node));
    else if (isdigit(row.front())) node->m_size += stoi(row.substr(0, row.find(' ')));
  }
  while (node->m_name != "/") node = node->m_parent;
  return node;
}

int calc_sizes(ftn* node)
{
  if (!node->m_children.size()) return node->m_size;
  else for (auto child : node->m_children) node->m_size += calc_sizes(child);
  return node->m_size;
}

int part1(ftn* node)
{
  int sum = 0;
  if (!node->m_children.size()) return node->m_size<100000?node->m_size:0;
  else for (auto child : node->m_children) sum += part1(child);
  return sum + (node->m_size<100000?node->m_size:0);
}

int part2(ftn* node, int minToDelete)
{
  if (!node->m_children.size()) return node->m_size;
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
  ftn* rootNode = construct_tree(file);
  int minToDelete = 30000000 - 70000000 + calc_sizes(rootNode);
  std::pair<std::string, std::string> result = 
    {std::to_string(part1(rootNode)), std::to_string(part2(rootNode, minToDelete))};
  delete rootNode;
  return result;
}