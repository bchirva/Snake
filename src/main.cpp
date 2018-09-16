#include "Window.hpp"

std::string AppLocation;

int main(int argc, char** argv)
{
    (void)(argc);

    AppLocation = argv[0];
    char delim {};
#ifdef _WIN32
    delim = '\\';
#endif
#ifdef __linux__
    delim = '/';
#endif
    AppLocation = AppLocation.substr(0, AppLocation.find_last_of(delim));
    
    Window window;
    window.open();

    return 0;
}
