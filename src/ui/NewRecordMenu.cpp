#include "NewRecordMenu.hpp"
#include "ControlHandler.hpp"

NewRecordMenu::NewRecordMenu()
    : Menu ({{"PLAYER NAME", nullptr},
             {"", [](){}}
            })
{
    next();
}

std::string NewRecordMenu::getPlayerName() const
{
    return m_PlayerName;
}

void NewRecordMenu::processInput(sf::Keyboard::Key AKey)
{
    if (static_cast<int16_t>(AKey) >= 0 && static_cast<int16_t>(AKey) <= 25)
    {
        if (m_PlayerName.length() < 6)
        {
            auto handler = ControlHandler::getInstance();
            m_PlayerName.append(handler->getKeyStr(AKey));
            m_Items.back().setLabel(m_PlayerName);
        }
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
        m_Items.back().setLabel(m_PlayerName);
    }
}
