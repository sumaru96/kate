// building.cpp

// This file contains the implementations of function by building and running project wight Gradle compiler

#include "../main-header.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// ----------------FUNCTIONS---------------------

    // This function running app (if jar is exist) and no rebuild project

int unrebuild(const int argc, char* argv[]) {

    const string toml = "kate.toml";
    const string source = read_file(toml);
    string args;

    if (argc >= 4) {

        if(const string flag = argv[3]; (flag == "--args" && argc > 4 )||(flag == "-a" && argc > 4)) {
            args = " " + string(argv[4]);
        }
    }

    if (!source.empty()) {
        const vector<string> values = get_values({"jar-path"}, source);
        const string command = "java -jar " + split(values[0], '"')[0] + args;
        system(command.c_str());
        return 0;
    }

    return -1;
}


    // This function building and running app by utilize Gradle

int run(const string& args){
    #if _WIN32
        const string command = "cmd /c gradlew.bat assemble run" + args;
        system(command.c_str());
    #else
        const string command = "./gradlew.sh assemble run" + args;
        system("chmod +x gradlew.sh");
        system(command.c_str());
    #endif
    return 0;
}

    // This function building project by utilize Gradle

int command_build(){
    #if _WIN32
        system("cmd /c gradlew.bat build");
    #else
        system("chmod +x gradlew.sh");
        system("./gradlew.sh build");
    #endif
    return 0;
}

    
    // This function checking flag and call correct function
int command_run(const int argc, char* argv[]){

    string args;

    if(argc >= 3){

        if(const string flag = argv[2]; flag == "--args" || flag == "-a"){
            if(argc > 3)
                args = " --args=\"" + string(argv[3]) + "\""; 
            else{
                cerr << RED << "No argument passed" << RESET << endl;
            }
        }else if (flag == "--unrebuild" || flag == "-u") {
            unrebuild(argc, argv);
            return 0;
        }else if (flag == "--rebuild" || flag == "-r") {
            run(args);
            return 0;
        }else {
           cout << RED <<"Invalid flag. Use --args to pass arguments to the application."<< RESET << endl;
           return 1;
        }
    }
    run(args);

    return 0;
}