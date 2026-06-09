// main-header.hpp

// This is main header, all files using this header

#include <string>
#include <vector>
#include <filesystem>
#ifndef MAIN_HEADER_HPP
#define MAIN_HEADER_HPP

using namespace std;

static const string RED = "\033[1;31m";
static const string GREEN = "\033[1;32m";
static const string YELLOW = "\033[1;33m";
static const string BLUE = "\033[1;34m";
static const string MAGENTA = "\033[1;35m";
static const string CYAN = "\033[1;36m";
static const string RESET = "\033[0m";

vector<string> split(const string& str,char delimiter);
vector<string> get_values(const vector<string>& value, const string& toml);

string strim(const string& str);

int create_directory(const filesystem::path& path, const string& lang);
int binary_to_file(filesystem::path& path,unsigned char binary[],unsigned int length);
int create_file_and_write(filesystem::path& path,const string &source);
int create_dir(filesystem::path& path);
int create_kotlin_directories(filesystem::path& root_path);
int create_java_directories(filesystem::path& root_path);
int create_toml_file(filesystem::path& path);
int command_new(int argc, char* argv[]);
int command_run(int argc, char* argv[]);
int command_build();
int command_help();

bool is_not_error(int x);


#endif