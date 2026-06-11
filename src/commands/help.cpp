// help.cpp

#include "../main-header.hpp"
#include <iostream>

using namespace std;

int command_help() {
    cout << CYAN << "==============================================================" << RESET << endl;
    cout << GREEN << "                    KATE CLI TOOL v1.0.1" << RESET << endl;
    cout << CYAN << "==============================================================" << RESET << endl;

    cout << YELLOW << "About project:" << RESET << endl;
    cout << "  Kate is a lightweight, fast CLI utility for creating," << endl;
    cout << "  building, and running Java and Kotlin projects without IDEs." << endl;
    cout << "  It automatically embeds and manages the Gradle Wrapper." << endl;
    cout << endl;

    cout << YELLOW << "License:" << RESET << endl;
    cout << "  Distributed under the " << RED << "GPL-3.0 License" << RESET << "." << endl;
    cout << "  You are free to use, modify, and share this software!" << endl;
    cout << endl;

    cout << YELLOW << "Main Commands:" << RESET << endl;

    cout << GREEN << "  new [project_path] [flag]" << RESET << endl;
    cout << "\tCreates a new workspace with all Gradle files." << endl;
    cout << "\tFlags for 'new':" << endl;
    cout << "\t  " << MAGENTA << "--kotlin" << RESET << " : Sets up a Kotlin project (Default)" << endl;
    cout << "\t  " << MAGENTA << "--java" << RESET << "   : Sets up a Java project" << endl;
    cout << endl;

    cout << GREEN << "  run [flag] [argument]" << RESET << endl;
    cout << "\tRuns your application. By default, it builds and runs via Gradle." << endl;
    cout << "\tFlags for 'run':" << endl;
    cout << "\t  " << MAGENTA << "-u, --unrebuild" << RESET << " : Instant run. Launches the compiled .jar directly" << endl;
    cout << "\t                     (Skips Gradle to save time)." << endl;
    cout << "\t                     Supports passing a single argument next." << endl;
    cout << "\t  " << MAGENTA << "-r, --rebuild" << RESET << "   : Forces Gradle to re-assemble and run." << endl;
    cout << "\t  " << MAGENTA << "-a, --args" << RESET << "      : Passes ONE argument directly to your application." << endl;
    cout << "\t                     Example: kate run -a hello" << endl;
    cout << "\t                     Example: kate run -u -a fast" << endl;
    cout << endl;
    cout << RED << "  [ATTENTION!] Pass only ONE argument WITHOUT quotes or brackets." << RESET << endl;
    cout << RED << "               Multiple arguments or quotes will cause an error." << RESET << endl;
    cout << endl;

    cout << GREEN << "  build" << RESET << endl;
    cout << "\tCompiles the project and creates a production-ready package." << endl;
    cout << endl;

    cout << GREEN << "  clean" << RESET << endl;
    cout << "\tCleans the Gradle build directory and caches." << endl;
    cout << endl;

    cout << GREEN << "  help, -h, --help" << RESET << endl;
    cout << "\tShows this help menu." << endl;

    cout << CYAN << "==============================================================" << RESET << endl;
    
    return 0;
}