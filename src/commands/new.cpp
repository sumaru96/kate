// new.cpp

// This file contains the implementations of function by creating global path and call other function for creating unique files for language

#include "../main-header.hpp"
#include "assets/gradlew.h"
#include "assets/gradlew_bat.h"
#include "assets/wrapper.h"
#include <filesystem>
#include <iostream>

using namespace std;

// -------------GLOBAL-CONSTANT-----------------

const string SOURCE_WRAPPER_PROPERTIES = R"(distributionBase=GRADLE_USER_HOME
distributionPath=wrapper/dists
distributionUrl=https://services.gradle.org/distributions/gradle-8.5-bin.zip
zipStoreBase=GRADLE_USER_HOME
zipStorePath=wrapper/dists
)";

    // This function create path and call function

int command_new(const int argc,const char* argv[]){

    if(argc < 3){
        return 0;
    }

        // Global path

    const filesystem::path root_path = argv[2];
    const filesystem::path wrapper_path = root_path / "gradle" / "wrapper";
    const filesystem::path gradlew_sh_path = root_path / "gradlew.sh";
    const filesystem::path gradlew_bat_path = root_path / "gradlew.bat";
    const filesystem::path gradlew_wrapper_path = wrapper_path / "gradle-wrapper.jar";
    const filesystem::path gradlew_wrapper_properties_path = wrapper_path / "gradle-wrapper.properties";

        // Creating directories and files

    if(!is_not_error(create_dir(wrapper_path))) return -1;
    if(!is_not_error(create_file_and_write(gradlew_wrapper_properties_path, SOURCE_WRAPPER_PROPERTIES))) return -1;
    if(!is_not_error(binary_to_file(gradlew_sh_path, gradlew, gradlew_len))) return -1;
    if(!is_not_error(binary_to_file(gradlew_bat_path, gradlew_bat, gradlew_bat_len))) return -1;
    if(!is_not_error(binary_to_file(gradlew_wrapper_path, gradle_wrapper_jar, gradle_wrapper_jar_len))) return -1;
    if(!is_not_error(create_toml_file(root_path))) return -1;

        // calling function for selected language

    if(argc >= 4 && string(argv[3]) == "--kotlin"){
        create_directory(root_path, "kotlin"s);
    }else if(argc >= 4 && string(argv[3]) == "--java"){
        create_directory(root_path, "java"s);
    }else{
        create_directory(root_path, string("kotlin"));
    }
    
        // print if not problem and Kate creating project by not error

    cout << GREEN << "Project " << MAGENTA << root_path << GREEN << " successfully created" << RESET << endl;
    cout << endl << GREEN << "Next step:" << RESET << endl; 
    cout << MAGENTA << "\tcd " << root_path << RESET << endl;
    cout << MAGENTA << "\tkate run" << RESET << endl;
    return 0;
}

int command_init() {
    const string name = filesystem::current_path().filename().string();
    const filesystem::path toml_path =  "./kate.toml";
    if (filesystem::exists(toml_path)) {
        return 0;
    }
    const string source = "[project]\nname = \"" + name + "\"\n" + "[run.unrebuild]\n"
                    + "jar-path = \"build/libs/" + name + ".jar\"\n" ;
    return create_file_and_write(toml_path, source);
}

