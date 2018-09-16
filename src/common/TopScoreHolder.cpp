#include "TopScoreHolder.hpp"
#include "Base.hpp"
#include <algorithm>
#include <fstream>
#include <yaml-cpp/yaml.h>

#include <iostream>

std::shared_ptr<TopScoreHolder> TopScoreHolder::g_Instance = nullptr;
std::mutex TopScoreHolder::g_InstanceMutex;

void TopScoreHolder::loadRecords()
{
    YAML::Node root;
    try
    {
        root = YAML::LoadFile(AppLocation + "/resources/records.yaml");
    }
    catch(YAML::BadFile&)
    {
        m_Records.fill(Record());
        return;
    }

    YAML::Node records = root["Records"];
    for (size_t i = 0; i < records.size(); i++)
    {
        std::string name {};
        int score {0};
        try
        {
            name = records[i]["PlayerName"].as<std::string>();
            score = records[i]["Score"].as<int>();
        }
        catch (YAML::BadConversion&){}
        m_Records[i] = std::make_pair(name, score);
    }

    std::sort(m_Records.rbegin(), m_Records.rend());
}

void TopScoreHolder::saveRecords()
{
    YAML::Node root;
    root["Records"];
    for (size_t i = 0; i < m_Records.size(); i++)
    {
        root["Records"][i]["PlayerName"] = m_Records[i].first;
        root["Records"][i]["Score"] = m_Records[i].second;
    }
    std::ofstream out (AppLocation + "/resources/records.yaml");
    if (out.is_open())
    {
        out << root;
        out.close();
    }
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
