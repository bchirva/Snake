#ifndef INPUTPROCESSOR_HPP
#define INPUTPROCESSOR_HPP

#include <SFML/Window/Event.hpp>

class IInputProcessor
{
public:
    virtual ~IInputProcessor() = default;
    virtual void processEvent(const sf::Keyboard::Key& AKey) = 0;
};

#endif
