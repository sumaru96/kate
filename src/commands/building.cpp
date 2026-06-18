// building.cpp

// This file contains the implementations of function by building and running project wight Gradle compiler

#include "../main-header.hpp"
#include <cstdlib>

#include <string>

using namespace std;

// ----------------FUNCTIONS---------------------

    // This function running app (if jar is exist) and no rebuild project

int unrebuild(const int argc,const char* argv[]) {

    const string toml = "kate.toml";
    const string source = read_file(toml);
    const string args = " " + getConsoleArguments(argc,argv,3);

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
    executeCommand("assemble run" + args);
    return 0;
}
    // This function building project by utilize Gradle

int command_build(){
    executeCommand("build");
    return 0;
}

    
    // This function checking flag and call correct function
int command_run(const int argc,const char* argv[]){

    const string args = " --args=\"" + getConsoleArguments(argc,argv,2) + "\"";

    if(argc >= 3){
        if(const string flag = argv[2]; flag == "--unrebuild" || flag == "-u") {
            unrebuild(argc, argv);
            return 0;
        }else if (flag == "--rebuild" || flag == "-r") {
            run(args);
            return 0;
        }
    }
    run(args);

    return 0;
}