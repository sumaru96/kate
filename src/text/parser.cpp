// parser.cpp

// This file implements functions for working with text and light version TOML file

#include "../main-header.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// ----------------FUNCTIONS---------------------

    // This function splitting line by character

vector<string> split(const string& str,char delimiter) {
    vector<string> result;
    string current;
    for (char c : str) {
        if (c == delimiter) {
            if (!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        } else {
            current += c;
        }
    }
    if (!current.empty()) {
        result.push_back(current);
    }
    return result;
}

    // This function trimming space and tab by start and end

string strim(const string& str) {
    size_t start = 0;
    while (start < str.size() && isspace(str[start])) {
        start++;
    }
    size_t end = str.size();
    while (end > start && isspace(str[end - 1])) {
        end--;
    }
    return str.substr(start, end - start);
}

    // This function get values by TOML file 

vector<string> get_values(const vector<string>& value, const string& toml){
    vector<string> values;
    vector<string> data;
    vector<string> lines = split(toml, '\n');
    for (string& line : lines){
        line = strim(line);
        if (line.empty() || line[0] == '#' || line[0] == '[') continue;
        vector<string> tokens = split(line, '=');
        for(string& token : tokens) {
            if (tokens.size() == 2) data.push_back(strim(token));
            else {
                cerr << RED << "Error: Invalid line in TOML file: " << MAGENTA << line << RESET << endl;
                return {};
            }
        }
    }
    unsigned int j = 0;
    for (int i = 0; j < value.size(); i++){
        if (data[i] == value[j]){
            values.push_back(data[i+1]);
            j++;
            i = -1;
        }
    }
    return values;
}

    // This function lower string and return her

string lowercase(const string& str) {
    string result;
    for (char letter : str) {
        if (letter >= 'A' && letter <= 'Z') {
            result += static_cast<char>(letter + 32);
        }
    }
    return result;
}