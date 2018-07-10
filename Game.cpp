#include "Game.hpp"

int Game::exec()
{
    m_Window.addDrawable(m_Apple);
    m_Window.addDrawable(m_Snake);
    m_Window.addDrawable(m_Wall);

    m_GraphicThread = std::thread(std::bind(&Window::drawLoop, &m_Window));
    

    m_GraphicThread.join();
    return 1;
}
