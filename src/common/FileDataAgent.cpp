#include "FileDataAgent.hpp"

void FileDataAgent::write(const std::string& AFileName, const std::multimap<std::string, int>& AData)
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

std::multimap<std::string, int> FileDataAgent::read(const std::string& AFileName)
{
    std::multimap<std::string, int> FileContent {};
    std::string buff {};
    std::ifstream ReadStream(AFileName);

    if (ReadStream.is_open())
    {
        while (std::getline(ReadStream, buff))
        {
            size_t delim = buff.find('=');
            //FileContent[buff.substr(0, delim)] = std::stoi(buff.substr(delim + 1));
            //FileContent.insert(std::pair<std::string, int>(buff.substr(0, delim), std::stoi(buff.substr(delim + 1))));
            FileContent.insert(std::make_pair(buff.substr(0, delim), std::stoi(buff.substr(delim + 1))));
            buff.clear();
        }
        ReadStream.close();
    }
    return FileContent;
}
