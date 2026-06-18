// functions.cpp

// This file contains the implementations of the important functions used in most files


#include "../main-header.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;


// ----------------FUNCTIONS---------------------


    // This function returns the original file from .h (headers) made via xxd

int binary_to_file(const filesystem::path& path,const unsigned char binary[],const unsigned int length){
    if (filesystem::exists(path)) {
       return 0; 
    }

    if(ofstream file(path,ios::binary); file.is_open()){
        file.write(reinterpret_cast<const char*>(binary),length);
        file.close();
    }else{
        cerr << RED << "[ERROR] Failed to create file: " << MAGENTA << path << RESET << endl;
        return -1;
    }

    cout << GREEN << "\tCreated file " << MAGENTA << path << RESET << endl;
    return 0;
}

    // This function safely creating new file and writing text if his not exist

int create_file_and_write(const filesystem::path& path,const string &source){
    if (filesystem::exists(path)) {
        return 0; 
    }

    if (ofstream file(path); file.is_open()) {
        file << source;
        file.close();
    }else{
        cerr << RED << "[ERROR] Failed to open or create file: " << MAGENTA << path << RESET << endl;
        return -1;
    }
    cout << GREEN << "\tCreated file " << MAGENTA << path << RESET << endl;
    return 0;
}

    // This function safely creating new directories if her not exist

int create_dir(const filesystem::path& path){
    if (filesystem::exists(path)) {
        return 0; 
    }

    if(!filesystem::create_directories(path)){
        cerr << RED << "[ERROR] Failed to creating directories : " << MAGENTA << path << RESET << endl;
        return -1;
    }
    cout << GREEN << "\tDirectory created " << CYAN << path << RESET << endl;
    return 0;
}

    // This function checking is are there not any error 

bool is_not_error(const int& x){
    if(x < 0){
        return false;
    }
    return true;
}

    // This function create TOML file for Kate parameters

int create_toml_file(const filesystem::path& path){
    const filesystem::path toml_path = path / "kate.toml";
    if (filesystem::exists(toml_path)) {
        return 0;
    }
    const string name = path.string();
    const string source = "[project]\nname = \"" + name + "\"\n" + "[run.unrebuild]\n"
                    + "jar-path = \"build/libs/" + name + ".jar\"\n" ;
    return create_file_and_write(toml_path, source);
}

    // This function reading file to one string and return his

string read_file(const filesystem::path& path) {
    if (filesystem::exists(path)) {
        ifstream file(path);
        string content((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());
        return content;
    }
    cerr << RED << "[ERROR] Failed to reading file : " << MAGENTA << path << RESET << endl;
    return "";
}




int create_project_file(const filesystem::path& source_directories_path,
                        const filesystem::path& gradle_build_file_path,
                        const string& SOURCE_GRADLE_BUILD,
                        const filesystem::path& source_main_file_path,
                        const string& SOURCE_CODE,
                        const filesystem::path& gradle_settings_file_path,
                        const string& SOURCE_SETTINGS) {
    if(!is_not_error(create_dir(source_directories_path))) return -1;
    if(!is_not_error(create_file_and_write(gradle_build_file_path, SOURCE_GRADLE_BUILD))) return -1;
    if(!is_not_error(create_file_and_write(source_main_file_path, SOURCE_CODE))) return -1;
    if(!is_not_error(create_file_and_write(gradle_settings_file_path, SOURCE_SETTINGS))) return -1;
    return 0;
}