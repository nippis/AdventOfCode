#include "solutions.hh"

std::string whitespace(std::size_t length)
{
  std::string space = "";
  for (std::size_t i = 0; i < length; i++)
    space += " ";
  return space;
}

std::string whitespace(int length)
{
  if (length <= 0) return {};
  return whitespace(static_cast<std::size_t>(length));
}