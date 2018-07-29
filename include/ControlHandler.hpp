#ifndef CONTROLHANDLER_HPP
#define CONTROLHANDLER_HPP

#include <map>
#include <SFML/Window/Keyboard.hpp>

#include <boost/filesystem.hpp>
#include <boost/property_tree/json_parser.hpp>

class ControlHandler
{
public:
    enum class Action
    {
        Up,
        Down,
        Left,
        Right,
        Pause,
        Quit
    };

    ControlHandler() = delete;
    ~ControlHandler() = delete;

    static void loadKeyMap();
    static void saveKeyMap();

    static sf::Keyboard::Key getPrimaryKey(ControlHandler::Action AAction);
    static sf::Keyboard::Key getSecondaryKey(ControlHandler::Action AAction);

private:
    static std::map<ControlHandler::Action, sf::Keyboard::Key> g_PrimaryKeys;
    static std::map<ControlHandler::Action, sf::Keyboard::Key> g_SecondaryKeys;

    static void configureDefault();
};

#endif // CONTROLHANDLER_HPP
