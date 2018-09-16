#ifndef TOPSCOREHOLDER_HPP
#define TOPSCOREHOLDER_HPP

#include <memory>
#include <mutex>
#include <list>
#include <array>

extern std::string AppLocation;

class Record : public std::pair<std::string, int>
{
public:
    Record();
    Record(const std::pair<std::string, int>& APair);
    friend bool operator== (const Record& lhs, const Record& rhs);
    friend bool operator> (const Record& lhs, const Record& rhs);
    friend bool operator< (const Record& lhs, const Record& rhs);
};

class TopScoreHolder
{
public:
    ~TopScoreHolder() = default;
    static std::shared_ptr<TopScoreHolder> getInstance();
    void insertRecord(std::pair<std::string, int> ANewRecord);
    const std::array<Record, 3>& getRecords() const;
    bool isNewRecord(int AScore) const;
    void reset();

private:
    static std::shared_ptr<TopScoreHolder> g_Instance;
    static std::mutex g_InstanceMutex;

    std::array<Record, 3> m_Records {};

    TopScoreHolder() = default;
    void loadRecords();
    void saveRecords();
};

#endif // TOPSCOREHOLDER_HPP
