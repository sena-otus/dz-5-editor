#pragma once

#include <utility>
#include <vector>
#include <string>
#include <functional>

/**
 * @brief Menu widget
 *  */
class Menu
{
public:
  using CB = std::function<void(void)>;

    /**
     *  Add a menu item with the callback that can be lamda or function
     *  @param itemtext menu item text
     *  @param callback to be called if item is activated
     *  @return menu item number
     *  */
  unsigned addItem(std::string &&itemtext, const CB &callback);

    /**
     * @brief display menu
     * */
  void show();


    /**
     * @brief process user input
     * @param userInput str with user input
     * */
  void processUserInput(const std::string &userInput);
private:
  std::vector<std::pair<std::string, CB>> m_item; ///! list of menu items and corresponding callbacks
};
