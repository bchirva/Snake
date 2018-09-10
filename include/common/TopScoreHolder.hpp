#ifndef TOPSCOREHOLDER_HPP
#define TOPSCOREHOLDER_HPP

#include <memory>
#include <mutex>

class TopScoreHolder
{
private:
    static std::shared_ptr<TopScoreHolder> g_Instance;
    static std::mutex g_InstanceMutex;


    TopScoreHolder();

public:
    ~TopScoreHolder() = default;
    static std::shared_ptr<TopScoreHolder> getInstance();
};

#endif // TOPSCOREHOLDER_HPP
