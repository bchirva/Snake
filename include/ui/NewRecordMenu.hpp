#ifndef NEWRECORDMENU_HPP
#define NEWRECORDMENU_HPP

#include "Scene.hpp"

class NewRecordMenu : public Scene
{
public:
    NewRecordMenu() = default;
    ~NewRecordMenu() = default;
    std::string getPlayerName() const;

private:
    std::string m_PlayerName {};

    void processInput(sf::Keyboard::Key AKey) override;
    void draw(sf::RenderWindow& ATargetWindow) const override;
};

#endif // NEWRECORDMENU_HPP
