#include "Game.hpp"

int Game::exec()
{
    m_GraphicThread = std::thread(std::bind(&Window::drawLoop, &m_Window));
    //m_Window.drawLoop();
    

    m_GraphicThread.join();
    return 1;
}
