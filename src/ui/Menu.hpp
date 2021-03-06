#ifndef MENU_HPP
#define MENU_HPP

#include <functional>
#include <string>
#include <list>

#include "Scene.hpp"

class MenuItem
{
public:
    MenuItem(std::string ALabel, std::function<void()> AAction);
    std::string getLabel() const;
    void setLabel(const std::string& ALabel);
    void action();
    bool isActive() const;

    static constexpr uint8_t ITEM_HEIGHT = 32;

private:
    std::string m_Label {};
    std::function<void()> m_Action = nullptr;
};

class Menu : public Scene
{
public:
    Menu() = default;
    Menu(std::list<MenuItem>&& AList);

    void next();
    void prev();
    std::list<MenuItem>::iterator getCurrent() const;

protected:
    std::list<MenuItem> m_Items;
    decltype(m_Items.begin()) m_CurrentItem;
    bool m_IsActive = true;

    void draw(sf::RenderWindow& ADrawingWindow) const override;
    void processInput(sf::Keyboard::Key AKey) override;
};

#endif
