// clean.cpp

// This file contains the implementation of function by cleaning Gradle project caches and build directories

#include "../main-header.hpp"
#include <cstdlib>

int command_clean() {
    #if _WIN32
        system("cmd /c gradlew.bat clean");
    #else
        system("chmod +x gradlew.sh");
        system("./gradlew.sh clean");
    #endif
    return 0;
}