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
    return g_PrimaryKeys.find(AAction)->second;
}

sf::Keyboard::Key ControlHandler::getSecondaryKey(ControlHandler::Action AAction)
{
    return g_SecondaryKeys.find(AAction)->second;
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
