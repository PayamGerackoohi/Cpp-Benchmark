//
// Created by Payam Gerackoohi on 14.05.22.
//

#include "file-util.h"
#include <fstream>
#include <sstream>

using namespace std;

unique_ptr<string> read_file(const string &file_name) {
    ifstream file(file_name);
    string str;
    stringstream ss;
    bool first = true;
    while (getline(file, str)) {
        if (first)
            first = false;
        else
            ss << "\n";
        ss << str;
    }
    file.close();
    return make_unique<string>(ss.str());
}
