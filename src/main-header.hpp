// main-header.hpp

// This is main header, all files using this header

#ifndef MAIN_HEADER_HPP
#define MAIN_HEADER_HPP

#include <string>
#include <vector>
#include <filesystem>

using namespace std;

inline const string RED = "\033[1;31m";
inline const string GREEN = "\033[1;32m";
inline const string YELLOW = "\033[1;33m";
inline const string BLUE = "\033[1;34m";
inline const string MAGENTA = "\033[1;35m";
inline const string CYAN = "\033[1;36m";
inline const string RESET = "\033[0m";

vector<string> split(const string& str,char delimiter);
vector<string> get_values(const vector<string>& value, const string& toml);

string lowercase(const string& str);
string strim(const string& str);
string read_file(const filesystem::path& path);

int create_directory(const filesystem::path& path, const string& lang);
int binary_to_file(const filesystem::path& path,const unsigned char binary[],unsigned int length);
int create_file_and_write(const filesystem::path& path,const string &source);
int create_dir(const filesystem::path& path);
int create_toml_file(const filesystem::path& path);
int command_new(int argc, char* argv[]);
int command_run(int argc, char* argv[]);
int command_build();
int command_help();
int command_clean();


bool is_not_error(const int& x);


#endif