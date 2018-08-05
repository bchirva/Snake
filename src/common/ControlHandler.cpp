#include "ControlHandler.hpp"

std::map<ControlHandler::Action, sf::Keyboard::Key> ControlHandler::g_PrimaryKeys {};
std::map<ControlHandler::Action, sf::Keyboard::Key> ControlHandler::g_SecondaryKeys {};

void ControlHandler::loadKeyMap()
{
    if (!boost::filesystem::exists("./resources/settings.json"))
    {
        configureDefault();
        return;
    }
    boost::property_tree::ptree root;
    boost::property_tree::read_json("./resources/settings.json", root);

    g_PrimaryKeys.clear();
    g_SecondaryKeys.clear();

    g_PrimaryKeys[Action::Up]    = static_cast<sf::Keyboard::Key>(root.get<int>("PrimaryKeys.Up"));
    g_PrimaryKeys[Action::Down]  = static_cast<sf::Keyboard::Key>(root.get<int>("PrimaryKeys.Down"));
    g_PrimaryKeys[Action::Left]  = static_cast<sf::Keyboard::Key>(root.get<int>("PrimaryKeys.Left"));
    g_PrimaryKeys[Action::Right] = static_cast<sf::Keyboard::Key>(root.get<int>("PrimaryKeys.Right"));
    g_PrimaryKeys[Action::Pause] = static_cast<sf::Keyboard::Key>(root.get<int>("PrimaryKeys.Pause"));
    g_PrimaryKeys[Action::Quit]  = static_cast<sf::Keyboard::Key>(root.get<int>("PrimaryKeys.Quit"));

    g_SecondaryKeys[Action::Up]    = static_cast<sf::Keyboard::Key>(root.get<int>("SecondaryKeys.Up"));
    g_SecondaryKeys[Action::Down]  = static_cast<sf::Keyboard::Key>(root.get<int>("SecondaryKeys.Down"));
    g_SecondaryKeys[Action::Left]  = static_cast<sf::Keyboard::Key>(root.get<int>("SecondaryKeys.Left"));
    g_SecondaryKeys[Action::Right] = static_cast<sf::Keyboard::Key>(root.get<int>("SecondaryKeys.Right"));
    g_SecondaryKeys[Action::Pause] = static_cast<sf::Keyboard::Key>(root.get<int>("SecondaryKeys.Pause"));
    g_SecondaryKeys[Action::Quit]  = static_cast<sf::Keyboard::Key>(root.get<int>("SecondaryKeys.Quit"));

}

void ControlHandler::saveKeyMap()
{

}

sf::Keyboard::Key ControlHandler::getPrimaryKey(ControlHandler::Action AAction)
{
    auto record = g_PrimaryKeys.find(AAction);
    if (record != g_PrimaryKeys.cend())
        return record->second;
    else
        return sf::Keyboard::Unknown;
}

sf::Keyboard::Key ControlHandler::getSecondaryKey(ControlHandler::Action AAction)
{
    auto record = g_SecondaryKeys.find(AAction);
    if (record != g_PrimaryKeys.cend())
        return record->second;
    else
        return sf::Keyboard::Unknown;
}

std::string ControlHandler::getPrimaryKeyStr(ControlHandler::Action AAction)
{
    return getString(getPrimaryKey(AAction));
}

std::string ControlHandler::getSecondaryKeyStr(ControlHandler::Action AAction)
{
    return getString(getSecondaryKey(AAction));
}

void ControlHandler::configureDefault()
{
    g_PrimaryKeys.clear();
    g_SecondaryKeys.clear();

    g_PrimaryKeys[Action::Up]       = sf::Keyboard::W;
    g_SecondaryKeys[Action::Up]     = sf::Keyboard::Up;

    g_PrimaryKeys[Action::Down]     = sf::Keyboard::S;
    g_SecondaryKeys[Action::Down]   = sf::Keyboard::Down;

    g_PrimaryKeys[Action::Left]     = sf::Keyboard::A;
    g_SecondaryKeys[Action::Left]   = sf::Keyboard::Left;

    g_PrimaryKeys[Action::Right]    = sf::Keyboard::D;
    g_SecondaryKeys[Action::Right]  = sf::Keyboard::Right;

    g_PrimaryKeys[Action::Pause]    = sf::Keyboard::Space;
    g_SecondaryKeys[Action::Pause]  = sf::Keyboard::P;

    g_PrimaryKeys[Action::Quit]     = sf::Keyboard::Escape;
    g_SecondaryKeys[Action::Quit]   = sf::Keyboard::Q;

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
