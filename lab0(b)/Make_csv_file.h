#pragma once
#include<map>
#include<string>
#include<list>
#include <iostream>
#include <fstream>
#include <regex>

class Read_input_file {
 private:
    std::map<std::string, int> m_words;
    int number;

public:
    Read_input_file();
    ~Read_input_file();

    void Read_file(std::string ptr);

    const std::map<std::string, int>& Getmap() const;

    int Getnumber() const;
};

class Writing_csv_file {
private:
    std::list<std::pair<int, std::string>> l_words;
    void Create_list(const std::map<std::string, int>& m_words);

public:

    void Writing_file(std::string ptr, int number, const std::map<std::string, int>& m_words);
};