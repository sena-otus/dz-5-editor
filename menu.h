#pragma once

#include <utility>
#include <vector>
#include <string>
#include <functional>


class Menu
{
public:
  using CB = std::function<void(void)>;

  unsigned addItem(std::string &&itemtext, const CB &callback);
  void show();

private:
  std::vector<std::pair<std::string, CB>> m_item;
};
