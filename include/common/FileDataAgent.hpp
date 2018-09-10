#ifndef FILEDATAAGENT_HPP
#define FILEDATAAGENT_HPP

#include <fstream>
#include <map>
#include <string>

class FileDataAgent
{
public:
    FileDataAgent() = default;
    ~FileDataAgent() = default;

    void write(const std::string& AFileName, const std::multimap<std::string, int> &AData);
    std::multimap<std::string, int> read(const std::string& AFileName);
};

#endif
