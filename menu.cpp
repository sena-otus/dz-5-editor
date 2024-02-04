#include "menu.h"

#include <algorithm>
#include <iostream>
#include <sstream>


unsigned Menu::addItem(std::string &&itemtext, const CB &callback)
{
  m_item.emplace_back(std::forward<std::string>(itemtext), callback);
  return m_item.size()-1;
}

void Menu::show()
{
  std::cout << "\nMenu\n";
  std::cout << "****\n";
  for(unsigned ii = 0; ii < m_item.size(); ++ii)
  {
    std::cout << ii << ": " << m_item[ii].first << "\n";
  }
  std::cout << "Input number: ";
}

void Menu::processUserInput(const std::string &userInput)
{
  unsigned itemNum = m_item.size();
  std::istringstream ss(userInput);
  ss >> itemNum;
  if(!ss || itemNum >= m_item.size())
  {
    std::cout << "Bad input" << std::endl;
    return;
  }
  m_item[itemNum].second();
}
