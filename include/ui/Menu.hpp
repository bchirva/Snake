#ifndef MENU_HPP
#define MENU_HPP

#include <functional>
#include <string>
#include <list>

#include "Scene.hpp"

class MenuItem
{
private:
    std::string m_Label {};
    std::function<void()> m_Action = nullptr;

public:
    MenuItem(std::string&& ALabel, std::function<void()> AAction);
    std::string getLabel() const;
    void setLabel(const std::string& ALabel);
    void action();
    bool isActive() const;

    static constexpr uint8_t ITEM_HEIGHT = 32;
};

class Menu : public Scene
{
protected:
    std::list<MenuItem> m_Items;
    decltype(m_Items.begin()) m_CurrentItem;
    bool m_IsActive = true;

    void draw(sf::RenderWindow& ADrawingWindow) const override;
    void processInput(sf::Keyboard::Key AKey) override;
public:
    Menu() = default;
    Menu(std::list<MenuItem>&& AList);

    void next();
    void prev();
    decltype(m_Items.begin()) getCurrent() const;
};

#endif
