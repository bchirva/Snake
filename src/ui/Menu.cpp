#include <iostream>
#include "Menu.hpp"

MenuItem::MenuItem(std::string&& ALabel, std::function<void()> AAction)
    : m_Label(ALabel), m_Action(AAction)
{}

Menu::Menu(std::list<MenuItem>&& AList)
    : m_Items(AList)
{
    m_CurrentItem = m_Items.begin();
}

std::string MenuItem::getLabel() const
{
    return m_Label;
}

void MenuItem::action()
{
    m_Action();
}

bool MenuItem::isActive() const
{
    return !(m_Action == nullptr);
}

void Menu::next()
{
    auto nextItem = m_CurrentItem;
    do
    {
        if (nextItem == --m_Items.cend())
            nextItem = m_Items.begin();
        else
            ++nextItem;
    }
    while (!nextItem->isActive() || nextItem == m_CurrentItem);
    m_CurrentItem = nextItem;
}

void Menu::prev()
{
    auto prevItem = m_CurrentItem;
    do
    {
        if (prevItem == m_Items.begin())
            prevItem = --m_Items.end();
        else
            --prevItem;
    }
    while (!prevItem->isActive() || prevItem == m_CurrentItem);
    m_CurrentItem = prevItem;
}

decltype(Menu::m_Items.begin()) Menu::getCurrent() const
{
    return m_CurrentItem;
}

void Menu::draw(sf::RenderWindow& ADrawingWindow) const
{
    sf::Text label;
    label.setFont(TextureLoader::getInstance()->getFont());
    label.setCharacterSize(24);

    sf::RectangleShape active;
    active.setFillColor(sf::Color::Green);
    active.setOutlineThickness(2.0);
    active.setOutlineColor(sf::Color::Black);

//    while (m_IsActive)
//    {
        uint32_t top = (ADrawingWindow.getSize().y - m_Items.size() * MenuItem::ITEM_HEIGHT) / 2;

        for (auto item = m_Items.cbegin(); item != m_Items.cend(); ++item)
        {
            label.setFillColor(sf::Color::Green);
            label.setString(item->getLabel());
            label.setPosition((ADrawingWindow.getSize().x - label.getLocalBounds().width) / 2, top + 4);

            if (getCurrent() == item)
            {
                active.setPosition(label.getPosition().x - 4, label.getPosition().y);
                active.setSize(sf::Vector2f(label.getLocalBounds().width + 8, MenuItem::ITEM_HEIGHT));
                label.setFillColor(sf::Color::Black);
                ADrawingWindow.draw(active);
            }

            if (!item->isActive())
            {
                label.setFillColor(sf::Color::Black);
            }

            ADrawingWindow.draw(label);
            top += MenuItem::ITEM_HEIGHT;
        }
//    }
}

void Menu::processEvent(sf::Keyboard::Key AKey)
{
    switch (AKey)
    {
    case sf::Keyboard::Up:
    {
        prev();
        break;
    }
    case sf::Keyboard::Down:
    {
        next();
        break;
    }
    case sf::Keyboard::Escape:
        m_IsActive = false;
        break;
    case sf::Keyboard::Enter:
        getCurrent()->action();
        break;
    default: break;
    }
}
