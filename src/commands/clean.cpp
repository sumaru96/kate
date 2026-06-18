// clean.cpp

// This file contains the implementation of function by cleaning Gradle project caches and build directories

#include "../main-header.hpp"

int command_clean() {
    executeCommand("clean");
    return 0;
}