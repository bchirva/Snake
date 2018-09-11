#ifndef TOPSCOREHOLDER_HPP
#define TOPSCOREHOLDER_HPP

#include <memory>
#include <mutex>
#include <list>
#include <array>

class TopScoreHolder
{
private:
    static std::shared_ptr<TopScoreHolder> g_Instance;
    static std::mutex g_InstanceMutex;
    std::array<std::pair<std::string, int>, 3> m_Records {};

    TopScoreHolder() = default;
    void loadRecords();
    void saveRecords();

public:
    ~TopScoreHolder() = default;
    static std::shared_ptr<TopScoreHolder> getInstance();
    void insertRecord(std::pair<std::string, int> ANewRecord);
    const std::array<std::pair<std::string, int>, 3>& getRecords() const;
    bool isNewRecord(int AScore) const;
};

#endif // TOPSCOREHOLDER_HPP
