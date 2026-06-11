// main.cpp

// This is main file , his get arguments and set his another functions

#include <iostream>
#include "main-header.hpp"

using namespace std;

int main(const int argc, char* argv[]){
    
    if(argc <= 1){
        command_help();
        return 0;
    }

    const string command = argv[1];

    if(command == "new"){
        command_new(argc,argv);
    }else if(command == "run"){
       command_run(argc,argv);
    }else if(command == "build"){
        command_build();
    }else if(command == "help" || command == "--help" || command == "-h"){
        command_help();
    }else if (command == "clean"){
        command_clean();
    }else {
        cout << RED << "Unknown command: " << command << RESET << endl;
    }
    return 0;
}
