#ifndef TOPSCOREHOLDER_HPP
#define TOPSCOREHOLDER_HPP

#include <memory>
#include <mutex>
#include <list>

class TopScoreHolder
{
private:
    static std::shared_ptr<TopScoreHolder> g_Instance;
    static std::mutex g_InstanceMutex;
    std::list<std::pair<std::string, int>> m_Scores {};

    TopScoreHolder();
    void loadRecords();
    void saveRecords();

public:
    ~TopScoreHolder() = default;
    static std::shared_ptr<TopScoreHolder> getInstance();
    const std::list<std::pair<std::string, int>>& getTopScore() const;
    void insertRecord(std::pair<std::string, int>);
};

#endif // TOPSCOREHOLDER_HPP
