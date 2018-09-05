#include "Scene.hpp"
#include "Base.hpp"

void Scene::show(sf::RenderWindow &ATargetWindow)
{
    sf::RectangleShape field(sf::Vector2f(FIELD_SIZE * 16, FIELD_SIZE * 16));
    field.setFillColor(sf::Color(160, 160, 0));
    sf::RectangleShape footer(sf::Vector2f(FIELD_SIZE * 16, 24));
    footer.setFillColor(sf::Color(32, 32, 32));
    footer.setPosition(0, FIELD_SIZE * 16);

    while (ATargetWindow.isOpen())
    {
        sf::Event event;
        while (ATargetWindow.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                processInput(event.key.code);
            }
        }
        ATargetWindow.clear();
        ATargetWindow.draw(field);
        ATargetWindow.draw(footer);
        draw(ATargetWindow);
        ATargetWindow.display();
    }
}
