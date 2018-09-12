#include <algorithm>
#include "TopScoreHolder.hpp"
#include "FileDataAgent.hpp"

std::shared_ptr<TopScoreHolder> TopScoreHolder::g_Instance = nullptr;
std::mutex TopScoreHolder::g_InstanceMutex;

void TopScoreHolder::loadRecords()
{
    FileDataAgent file;
    auto topScore = file.read("score.txt");
    m_Records.fill(Record());
    int i = 0;
    for (auto item: topScore)
    {
        m_Records[i] = std::make_pair(item.first, item.second);
        i++;
    }
    std::sort(m_Records.rbegin(), m_Records.rend());
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
            g_Instance->loadRecords();
        }
    }
    return g_Instance;
}

const std::array<Record, 3> &TopScoreHolder::getRecords() const
{
    return m_Records;
}

bool TopScoreHolder::isNewRecord(int AScore) const
{
    return AScore > m_Records.at(m_Records.size() - 1).second;
}

void TopScoreHolder::reset()
{
    m_Records.fill(Record());
    saveRecords();
}

void TopScoreHolder::insertRecord(std::pair<std::string, int> ANewRecord)
{
    m_Records[m_Records.size() - 1] = Record(ANewRecord);
    std::sort(m_Records.rbegin(), m_Records.rend());
    saveRecords();
}

Record::Record()
    : std::pair<std::string, int>("", 0)
{}

Record::Record(const std::pair<std::string, int>& APair)
    : std::pair<std::string, int>(APair)
{}

bool operator==(const Record& lhs, const Record& rhs)
{
    return lhs.second == rhs.second;
}

bool operator>(const Record& lhs, const Record& rhs)
{
    return lhs.second > rhs.second;
}

bool operator<(const Record& lhs, const Record& rhs)
{
    return lhs.second < rhs.second;
}
