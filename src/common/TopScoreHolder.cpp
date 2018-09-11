#include "TopScoreHolder.hpp"
#include "FileDataAgent.hpp"

std::shared_ptr<TopScoreHolder> TopScoreHolder::g_Instance = nullptr;
std::mutex TopScoreHolder::g_InstanceMutex;

void TopScoreHolder::loadRecords()
{
    FileDataAgent file;
    auto topScore = file.read("score.txt");
    m_Records.fill(std::make_pair("",0));
}

void TopScoreHolder::saveRecords()
{
    std::multimap<std::string, int> topScore {};
    for (auto item: m_Records)
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

const std::array<std::pair<std::string, int>, 3>& TopScoreHolder::getRecords() const
{
    return m_Records;
}

bool TopScoreHolder::isNewRecord(int AScore) const
{
    return AScore > m_Records.at(m_Records.size() - 1).second;
}

void TopScoreHolder::insertRecord(std::pair<std::string, int> ANewRecord)
{

}
