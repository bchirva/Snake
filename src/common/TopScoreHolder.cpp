#include "TopScoreHolder.hpp"
#include "FileDataAgent.hpp"

std::shared_ptr<TopScoreHolder> TopScoreHolder::g_Instance = nullptr;
std::mutex TopScoreHolder::g_InstanceMutex;

TopScoreHolder::TopScoreHolder()
{

}

void TopScoreHolder::loadRecords()
{
    FileDataAgent file;
    auto topScore = file.read("score.txt");
    m_Scores.clear();
}

void TopScoreHolder::saveRecords()
{
    std::multimap<std::string, int> topScore {};
    for (auto item: m_Scores)
    {
        topScore.insert(std::make_pair(item.first, item.second));
    }
    FileDataAgent file;
    file.write("score.txt", topScore);
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

const std::list<std::pair<std::string, int> > &TopScoreHolder::getTopScore() const
{
    return m_Scores;
}

void TopScoreHolder::insertRecord(std::pair<std::string, int>)
{

}
