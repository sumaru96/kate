// CommandManager.cpp

#include "../main-header.hpp"

int executeCommand(const std::string& args) {
#if _WIN32
    const std::string command = "cmd /c gradlew.bat " + args;
    system(command.c_str());
#else
    const std::string command = "./gradlew.sh " + args;
    system("chmod +x gradlew.sh");
    system(command.c_str());
#endif
    return 0;
}

std::string getConsoleArguments(
    const int argc,
    const char* argv[],
    const int id
) {
    std::string args;

    if (const std::string flag = lowercase(argv[id]);
        (flag == "--args" || flag == "-a") && argc > (id+1))
    {
        args = split(std::string(argv[id + 1]), '"')[0];
    }

    return args;
}


