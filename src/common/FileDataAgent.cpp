#include "FileDataAgent.hpp"

void FileDataAgent::write(const std::string& AFileName, const std::map<std::string, int>& AData)
{
    std::ofstream WriteStream (AFileName);
    if(WriteStream.is_open())
    {
        for (auto item: AData)
        {
            WriteStream << item.first << "=" << item.second << '\n';
        }
        WriteStream.close();
    }
}

std::map<std::string, int> FileDataAgent::read(const std::string& AFileName)
{
    std::map<std::string, int> FileContent {};
    std::string buff {};
    std::ifstream ReadStream(AFileName);

    if (ReadStream.is_open())
    {
        while (std::getline(ReadStream, buff))
        {
            size_t delim = buff.find('=');
            FileContent[buff.substr(0, delim)] = std::stoi(buff.substr(delim + 1));
            buff.clear();
        }
        ReadStream.close();
    }
    return FileContent;
}
