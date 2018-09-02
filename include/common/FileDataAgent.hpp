#ifndef FILEDATAAGENT_HPP
#define FILEDATAAGENT_HPP

#include <fstream>
#include <vector>
#include <string>

class FileDataAgent
{
public:
    FileDataAgent() = default;
    ~FileDataAgent() = default;

    void write(const std::string& AFileName, const std::vector<std::string>& AData);
    std::vector<std::string> read(const std::string& AFileName);
};

#endif
