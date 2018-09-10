#include "NewRecordMenu.hpp"
#include "ControlHandler.hpp"

void NewRecordMenu::processInput(sf::Keyboard::Key AKey)
{
    if (m_PlayerName.length() < 6)
    {
        if (static_cast<int16_t>(AKey) >= 0 && static_cast<int16_t>(AKey) <= 25)
        {
            auto handler = ControlHandler::getInstance();
            m_PlayerName.append(handler->getKeyStr(AKey));
        }
        else if (AKey == sf::Keyboard::Escape)
        {
            m_PlayerName.clear();
            quit();
        }
        else if (AKey == sf::Keyboard::Enter)
        {
            quit();
        }
        else if (AKey == sf::Keyboard::Backspace)
        {
            if (m_PlayerName.length() > 0)
            {
                m_PlayerName.erase(--m_PlayerName.cend());
            }
        }
    }
}

void NewRecordMenu::draw(sf::RenderWindow& ATargetWindow) const
{
    (void)(ATargetWindow);
}
