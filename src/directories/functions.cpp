// functions.cpp

// This file contains the implementations of the important functions used in most files


#include "../main-header.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;


// ----------------FUNCTIONS---------------------


    // This function returns the original file from .h (headers) made via xxd

int binary_to_file(filesystem::path& path,unsigned char binary[],unsigned int length){
    if (filesystem::exists(path)) {
       return 0; 
    }
    ofstream file(path,ios::binary);
    if(file.is_open()){
        file.write(reinterpret_cast<const char*>(binary),length);
        file.close();
    }else{
        cerr << RED << "[ERROR] Failed to create file: " << path << RESET << endl;
        cerr << RED << "Check if you have write permissions in this directory." << RESET << endl;
        return -1;
    }
    return 0;
}

    // This function safely creating new file and writing text if his not exist

int create_file_and_write(filesystem::path& path,const string &source){
    if (filesystem::exists(path)) {
        return 0; 
    }

    ofstream file(path);
    if (file.is_open()) {
        file << source;
        file.close();
    }else{
        cerr << RED << "[ERROR] Failed to open or create file: " << path << RESET << endl;
        cerr << RED << "Check if you have write permissions in this directory." << RESET << endl;
        return -1;
    }
    return 0;
}

    // This function safely creating new directories if her not exist

int create_dir(filesystem::path& path){
    if (filesystem::exists(path)) {
        return 0; 
    }

    if(!filesystem::create_directories(path)){
        cerr << RED << "[ERROR] Failed to creating directoires : " << path << RESET << endl;
        cerr << RED << "Check if you have write permissions in this directory." << RESET << endl;
        return -1;
    }
    return 0;
}

    // This function checking is are there not any error 

bool is_not_error(int x){
    if(x < 0){
        return false;
    }
    return true;
}

    // This function create TOML file for Kate parameters

int create_toml_file(filesystem::path& path){
    filesystem::path toml_path = path / "kate.toml";
    if (filesystem::exists(toml_path)) {
        return 0; 
    }
    string source = "[project]\nname = \"" + path.string() + "\"\n";
    return create_file_and_write(toml_path, source);
}
    