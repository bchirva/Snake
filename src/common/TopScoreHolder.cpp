#include "TopScoreHolder.hpp"
#include "FileDataAgent.hpp"

std::shared_ptr<TopScoreHolder> TopScoreHolder::g_Instance = nullptr;
std::mutex TopScoreHolder::g_InstanceMutex;

TopScoreHolder::TopScoreHolder()
{

}

std::shared_ptr<TopScoreHolder> TopScoreHolder::getInstance()
{
    if(!g_Instance)
    {
        std::lock_guard<std::mutex> lock(g_InstanceMutex);
        if(!g_Instance)
        {
            g_Instance.reset(new TopScoreHolder());
        }
    }
    return g_Instance;
}
