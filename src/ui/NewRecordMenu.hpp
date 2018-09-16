#ifndef NEWRECORDMENU_HPP
#define NEWRECORDMENU_HPP

#include "Menu.hpp"

class NewRecordMenu : public Menu
{
public:
    NewRecordMenu();
    ~NewRecordMenu() = default;
    std::string getPlayerName() const;

private:
    std::string m_PlayerName {};

    void processInput(sf::Keyboard::Key AKey) override;
};

#endif // NEWRECORDMENU_HPP
