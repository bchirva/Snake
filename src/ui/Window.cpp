#include "Window.hpp"

Window::Window()
{
}

void Window::drawGame()
{
    Game game;
    game.start();
    game.show(m_Window);
    game.shutDown();
}

void Window::showRecords()
{
    FileDataAgent agent;
    auto savedScores = agent.read("top_scores.txt");
    std::vector<std::pair<std::string, int>> top;
    size_t recordCout = top.size();

    for (size_t i = 0; i < (3 - recordCout); i++)
        top.push_back(std::make_pair<std::string, int>("", 0));

    Menu RecordsMenu ({{std::string(top.at(0).first + std::to_string(top.at(0).second)), nullptr},
                       {std::string(top.at(1).first + std::to_string(top.at(1).second)), nullptr},
                       {std::string(top.at(2).first + std::to_string(top.at(2).second)), nullptr},
                       {"\t", nullptr},
                       {"Back", [&](){RecordsMenu.quit();}},
                       {"Reset", nullptr},
                      });

    RecordsMenu.next();
    RecordsMenu.show(m_Window);
}

void Window::showSettingsMenu()
{
    Menu SettingsMenu;
    auto handler = ControlHandler::getInstance();

    auto newKey = [&](ControlHandler::Action AAction){
        sf::Event event;

        do
        {
            m_Window.waitEvent(event);
            if (event.type == sf::Event::KeyPressed)
            {
                if (!handler->isBusy(event.key.code))
                {
                    handler->setKey(AAction, event.key.code);
                    std::string oldLabel = SettingsMenu.getCurrent()->getLabel();
                    oldLabel = oldLabel.substr(0, oldLabel.find('\t'));
                    SettingsMenu.getCurrent()->setLabel(oldLabel + '\t' + handler->getKeyStr(AAction));
                    break;
                }
            }
        }
        while (true);
    };

    SettingsMenu = Menu({{std::string("UP\t"   + handler->getKeyStr(ControlHandler::Action::Up)),
                          std::bind(newKey, ControlHandler::Action::Up)},
                         {std::string("DOWN\t"  + handler->getKeyStr(ControlHandler::Action::Down)),
                          std::bind(newKey, ControlHandler::Action::Down)},
                         {std::string("LEFT\t"  + handler->getKeyStr(ControlHandler::Action::Left)),
                          std::bind(newKey, ControlHandler::Action::Left)},
                         {std::string("RIGHT\t" + handler->getKeyStr(ControlHandler::Action::Right)),
                          std::bind(newKey, ControlHandler::Action::Right)},
                         {std::string("Pause\t" + handler->getKeyStr(ControlHandler::Action::Pause)),
                          std::bind(newKey, ControlHandler::Action::Pause)},
                         {std::string("Quit\t"  + handler->getKeyStr(ControlHandler::Action::Quit)),
                          std::bind(newKey, ControlHandler::Action::Quit)},
                         {"\t", nullptr},
                         {"Back", [&](){
                             handler->loadKeyMap();
                             SettingsMenu.quit();}},
                         {"Reset", [&](){
                              handler->configureDefault();
                              handler->saveKeyMap();
                              SettingsMenu.quit();
                         }},
                         {"Apply", [&](){
                              handler->saveKeyMap();
                              SettingsMenu.quit();
                          }}
                       });
    SettingsMenu.show(m_Window);
}

void Window::showMainMenu()
{
    Menu MainMenu ({{"New Game", std::bind(&Window::drawGame,         this)},
                   {"Settings",  std::bind(&Window::showSettingsMenu, this)},
                   {"Records",   std::bind(&Window::showRecords,      this)},
                   {"Quit", [this](){m_Window.close();}}
                   });

    MainMenu.show(m_Window);
}

void Window::open()
{
    m_Window.create(sf::VideoMode(FIELD_SIZE * 16, (FIELD_SIZE * 16) + 24),
                    "Snake",
                    sf::Style::Titlebar | sf::Style::Close);
    showMainMenu();
}
