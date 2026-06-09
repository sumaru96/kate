// main.cpp

// This is main file , his get arguments and set his a other functions

#include "./main-header.hpp"

using namespace std;

int main(int argc, char* argv[]){
    
    if(argc <= 1){
        command_help();
        return 0;
    }

    string command = argv[1];

    if(command == "new"){
        command_new(argc,argv);
    }else if(command == "run"){
       command_run(argc,argv);
    }else if(command == "build"){
        command_build();
    }else if(command == "help" || command == "--help" || command == "-h"){
        command_help();
    }else {
        command_help();
    }
    return 0;
}