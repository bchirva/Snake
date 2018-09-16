#ifndef CONTROLHANDLER_HPP
#define CONTROLHANDLER_HPP

#include <map>
#include <memory>
#include <mutex>

#include <SFML/Window/Keyboard.hpp>
#include <yaml-cpp/yaml.h>

//#include "FileDataAgent.hpp"

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

    void setKey(ControlHandler::Action AAction, sf::Keyboard::Key AKey);
    sf::Keyboard::Key getKey(ControlHandler::Action AAction);

    std::string getKeyStr(ControlHandler::Action AAction);
    std::string getKeyStr(sf::Keyboard::Key AKey);

    void configureDefault();
    void loadKeyMap();
    void saveKeyMap();
    bool isBusy(sf::Keyboard::Key AKey);

private:
    std::map<ControlHandler::Action, sf::Keyboard::Key> m_Keys {};
    static std::shared_ptr<ControlHandler> g_Instance;
    static std::mutex g_InstanceMutex;

    ControlHandler() = default;
    std::string getString(sf::Keyboard::Key AKey);
    void readKey(const YAML::Node& ANode, sf::Keyboard::Key& AKey);
};

#endif // CONTROLHANDLER_HPP
