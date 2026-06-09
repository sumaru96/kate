// building.cpp

// This file contains the implementations of function by building and runing project wight Gradle compiler

#include "../main-header.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

// ----------------FUNCTIONS---------------------

    // This function runing app (if jar is exist) and no rebuild project

int unrebuild(){
    const filesystem::path toml = "kate.toml";
    if (filesystem::exists(toml)) {
        vector<string> values;
        ifstream file(toml);
        string content((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());
        values = get_values({"name"}, content);
        values = split(values[0], '"');
        const string name = values[0];

    
        filesystem::path path = "build/libs/" + name + ".jar";
        if(!filesystem::exists(path)){
            cerr << RED << "[ERROR] file: " << MAGENTA << path.string() << RED << " dont exist" << RESET << endl;
            return -1;
        }
        string command = "java -jar " + path.string() ;
        system(command.c_str());
        return 0;
    }
    cerr << RED << "[ERROR] file: " << MAGENTA << toml << RED << " dont exist" << RESET << endl;
    return -1;
}
    // This function building and runing app by utilise Gradle
int run(const string& args){
    #if _WIN32
        string command = "cmd /c gradlew.bat assemble run" + args;
        system(command.c_str());
    #else
        string command = "./gradlew assemble run" + args;
        system("chmod +x gradlew.sh");
        system(command.c_str());
    #endif
    return 0;
}

    // This function building project by utilise Gradle

int command_build(){
    #if _WIN32
        system("cmd /c gradlew.bat build");
    #else
        system("chmod +x gradlew.sh");
        system("./gradlew build");
    #endif
    return 0;
}

    
    // This function checking flag and call corect function 
int command_run(int argc, char* argv[]){

    string args = "";

    if(argc >= 3){
        string flag = argv[2];
        if(flag == "--args" || flag == "-a"){
            if(argc > 3)
                args = " --args=\"" + string(argv[3]) + "\""; 
            else{
                cerr << RED << "No argument passed" << RESET << endl;
            }
        }else if (flag == "--unrebuild" || flag == "-u") {
            unrebuild();
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