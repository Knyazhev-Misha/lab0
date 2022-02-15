#pragma once
#include<map>
#include<string>
#include<list>
#include <iostream>
#include <fstream>
#include <regex>
#include "Read_input_file.h"

class Writing_csv_file {
private:
    std::list<std::pair<int, std::string>> l_words;
    int number;

public:

    Writing_csv_file(const Read_input_file& ltr);
    ~Writing_csv_file();

    void Writing_file(std::string ptr);
};