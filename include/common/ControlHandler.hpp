#ifndef CONTROLHANDLER_HPP
#define CONTROLHANDLER_HPP

#include <map>
#include <memory>
#include <mutex>

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

    static std::shared_ptr<ControlHandler> getInstance();
    sf::Keyboard::Key getKey(ControlHandler::Action AAction);
    std::string getKeyStr(ControlHandler::Action AAction);
    void loadKeyMap();
    void saveKeyMap();

private:
    std::map<ControlHandler::Action, sf::Keyboard::Key> m_Keys {};
    static std::shared_ptr<ControlHandler> g_Instance;
    static std::mutex g_InstanceMutex;

    ControlHandler() = default;
    void configureDefault();
    std::string getString(sf::Keyboard::Key AKey);
};

#endif // CONTROLHANDLER_HPP
