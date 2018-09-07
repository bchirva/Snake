#include "ControlHandler.hpp"
#include <iostream>

std::shared_ptr<ControlHandler> ControlHandler::g_Instance = nullptr;
std::mutex ControlHandler::g_InstanceMutex;

void ControlHandler::loadKeyMap()
{
    FileDataAgent file;
    auto content = file.read("settings.conf");

    if (content.empty())
    {
        configureDefault();
        saveKeyMap();
    }
    else
    {
        m_Keys.clear();
        m_Keys[Action::Up]      = static_cast<sf::Keyboard::Key>(content.at("Up"));
        m_Keys[Action::Down]    = static_cast<sf::Keyboard::Key>(content.at("Down"));
        m_Keys[Action::Left]    = static_cast<sf::Keyboard::Key>(content.at("Left"));
        m_Keys[Action::Right]   = static_cast<sf::Keyboard::Key>(content.at("Right"));
        m_Keys[Action::Pause]   = static_cast<sf::Keyboard::Key>(content.at("Pause"));
        m_Keys[Action::Quit]    = static_cast<sf::Keyboard::Key>(content.at("Quit"));
    }
}

void ControlHandler::saveKeyMap()
{
    std::map<std::string, int> keyMap;
    keyMap["Up"]    = static_cast<int>(m_Keys.at(Action::Up));
    keyMap["Down"]  = static_cast<int>(m_Keys.at(Action::Down));
    keyMap["Left"]  = static_cast<int>(m_Keys.at(Action::Left));
    keyMap["Right"] = static_cast<int>(m_Keys.at(Action::Right));
    keyMap["Pause"] = static_cast<int>(m_Keys.at(Action::Pause));
    keyMap["Quit"]  = static_cast<int>(m_Keys.at(Action::Quit));
    FileDataAgent file;
    file.write("settings.conf", keyMap);
}

std::shared_ptr<ControlHandler> ControlHandler::getInstance()
{
    if(!g_Instance)
    {
        std::lock_guard<std::mutex> lock(g_InstanceMutex);
        if(!g_Instance)
        {
            g_Instance.reset(new ControlHandler());
            g_Instance->loadKeyMap();
        }
    }
    return g_Instance;
}

void ControlHandler::setKey(ControlHandler::Action AAction, sf::Keyboard::Key AKey)
{
    m_Keys.at(AAction) = AKey;
}

sf::Keyboard::Key ControlHandler::getKey(ControlHandler::Action AAction)
{
    auto record = m_Keys.find(AAction);
    if (record != m_Keys.cend())
        return record->second;
    else
        return sf::Keyboard::Unknown;
}

std::string ControlHandler::getKeyStr(ControlHandler::Action AAction)
{
    return getString(getKey(AAction));
}

void ControlHandler::configureDefault()
{
    m_Keys.clear();
    m_Keys[Action::Up]       = sf::Keyboard::W;
    m_Keys[Action::Down]     = sf::Keyboard::S;
    m_Keys[Action::Left]     = sf::Keyboard::A;
    m_Keys[Action::Right]    = sf::Keyboard::D;
    m_Keys[Action::Pause]    = sf::Keyboard::Space;
    m_Keys[Action::Quit]     = sf::Keyboard::Escape;
    saveKeyMap();
}

std::string ControlHandler::getString(sf::Keyboard::Key AKey)
{
    std::string str;
    switch(AKey)
    {
    case sf::Keyboard::Up:          str = "Up";         break;
    case sf::Keyboard::Down:        str = "Down";       break;
    case sf::Keyboard::Left:        str = "Left";       break;
    case sf::Keyboard::Right:       str = "Right";      break;
    
    case sf::Keyboard::Space:       str = "Space";      break;
    case sf::Keyboard::Tab:         str = "Tab";        break;
    case sf::Keyboard::Enter:       str = "Enter";      break;
    case sf::Keyboard::Escape:      str = "Esc";        break;
    case sf::Keyboard::Backspace:   str = "Backspace";  break;
    case sf::Keyboard::Pause:       str = "Pause";      break;

    case sf::Keyboard::Q:           str = "Q"; break;
    case sf::Keyboard::W:           str = "W"; break;
    case sf::Keyboard::E:           str = "E"; break;
    case sf::Keyboard::R:           str = "R"; break;
    case sf::Keyboard::T:           str = "T"; break;
    case sf::Keyboard::Y:           str = "Y"; break;
    case sf::Keyboard::U:           str = "U"; break;
    case sf::Keyboard::I:           str = "I"; break;
    case sf::Keyboard::O:           str = "O"; break;
    case sf::Keyboard::P:           str = "P"; break;
    case sf::Keyboard::LBracket:    str = "["; break;
    case sf::Keyboard::RBracket:    str = "]"; break;
    
    case sf::Keyboard::A:           str = "A"; break;
    case sf::Keyboard::S:           str = "S"; break;
    case sf::Keyboard::D:           str = "D"; break;
    case sf::Keyboard::F:           str = "F"; break;
    case sf::Keyboard::G:           str = "G"; break;
    case sf::Keyboard::H:           str = "H"; break;
    case sf::Keyboard::J:           str = "J"; break;
    case sf::Keyboard::K:           str = "K"; break;
    case sf::Keyboard::L:           str = "L"; break;
    case sf::Keyboard::Semicolon:   str = ";"; break;
    case sf::Keyboard::Quote:       str = "'"; break;

    case sf::Keyboard::Z:           str = "Z"; break;
    case sf::Keyboard::X:           str = "X"; break;
    case sf::Keyboard::C:           str = "C"; break;
    case sf::Keyboard::V:           str = "V"; break;
    case sf::Keyboard::B:           str = "B"; break;
    case sf::Keyboard::N:           str = "N"; break;
    case sf::Keyboard::M:           str = "M"; break;
    case sf::Keyboard::Comma:       str = ","; break;
    case sf::Keyboard::Period:      str = "."; break;
    case sf::Keyboard::Slash:       str = "/"; break;

    case sf::Keyboard::Tilde:       str = "~"; break;
    case sf::Keyboard::Num1:        str = "1"; break;
    case sf::Keyboard::Num2:        str = "2"; break;
    case sf::Keyboard::Num3:        str = "3"; break;
    case sf::Keyboard::Num4:        str = "4"; break;
    case sf::Keyboard::Num5:        str = "5"; break;
    case sf::Keyboard::Num6:        str = "6"; break;
    case sf::Keyboard::Num7:        str = "7"; break;
    case sf::Keyboard::Num8:        str = "8"; break;
    case sf::Keyboard::Num9:        str = "9"; break;
    case sf::Keyboard::Num0:        str = "0"; break;
    case sf::Keyboard::Hyphen:      str = "-"; break;
    case sf::Keyboard::Equal:       str = "="; break;
    case sf::Keyboard::Backslash:   str = "\\"; break;

    case sf::Keyboard::Numpad0:     str = "Num0"; break;
    case sf::Keyboard::Numpad1:     str = "Num1"; break;
    case sf::Keyboard::Numpad2:     str = "Num2"; break;
    case sf::Keyboard::Numpad3:     str = "Num3"; break;
    case sf::Keyboard::Numpad4:     str = "Num4"; break;
    case sf::Keyboard::Numpad5:     str = "Num5"; break;
    case sf::Keyboard::Numpad6:     str = "Num6"; break;
    case sf::Keyboard::Numpad7:     str = "Num7"; break;
    case sf::Keyboard::Numpad8:     str = "Num8"; break;
    case sf::Keyboard::Numpad9:     str = "Num9"; break;
    case sf::Keyboard::Add:         str = "+";    break;
    case sf::Keyboard::Subtract:    str = "-";    break;
    case sf::Keyboard::Multiply:    str = "*";    break;
    case sf::Keyboard::Divide:      str = "/";    break;

    case sf::Keyboard::LControl:    str = "LCtrl";  break;
    case sf::Keyboard::RControl:    str = "RCtrl";  break;
    case sf::Keyboard::LAlt:        str = "LAlt";   break;
    case sf::Keyboard::RAlt:        str = "RAlt";   break;
    case sf::Keyboard::LShift:      str = "LShift"; break;
    case sf::Keyboard::RShift:      str = "RShift"; break;

    case sf::Keyboard::PageUp:      str = "PageUp";     break;
    case sf::Keyboard::PageDown:    str = "PageDown";   break;
    case sf::Keyboard::Home:        str = "Home";       break;
    case sf::Keyboard::End:         str = "End";        break;
    case sf::Keyboard::Insert:      str = "Insert";     break;
    case sf::Keyboard::Delete:      str = "Delete";     break;

    default:                        str = "Unknown"; break;
    }
    return str;
}
