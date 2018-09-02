#include "FileDataAgent.hpp"

void FileDataAgent::write(const std::string &AFileName, const std::vector<std::string> &AData)
{
    std::ofstream WriteStream (AFileName);
    if(WriteStream.is_open())
    {
        for (auto str: AData)
        {
            WriteStream << str;
        }
        WriteStream.close();
    }
}

std::vector<std::string> FileDataAgent::read(const std::string &AFileName)
{
    std::vector<std::string> FileContent {};
    std::string buff {};
    std::ifstream ReadStream(AFileName);

    if (ReadStream.is_open())
    {
        while (!ReadStream.eof())
        {
            std::getline(ReadStream, buff);
            FileContent.push_back(buff);
            buff.clear();
        }
    }
    ReadStream.close();
    return FileContent;
}
