#include"Make_csv_file.h"

Read_input_file::Read_input_file() {
    number = 0;
}

Read_input_file::~Read_input_file() {
    m_words.clear();
}

const std::map<std::string, int>& Read_input_file::Getmap() const {
    return m_words;
}

int Read_input_file::Getnumber() const{
    return number;
}

void Read_input_file::Read_file(std::string ptr) {
    std::string str;
    std::ifstream in;

    in.open(ptr);

    while (!in.eof()) {
        getline(in, str);

        std::regex rgx("\\w+");

        for (std::sregex_iterator it(str.begin(), str.end(), rgx), it_end; it != it_end; ++it) {
            number += 1;

            m_words[(*it)[0]] += 1;
        }
    }

    in.close();
}

void Writing_csv_file::Writing_file(std::string ptr, int number, const std::map<std::string, int>& m_words) {
    std::ofstream out;
       
    Create_list(m_words);
    
    out.open(ptr);

    float frequency;

    for (auto it = l_words.begin(); it != l_words.end(); it++) {
        frequency = it->first * 1.0 / number;
        out << it->second << ";" << frequency << ";" << frequency * 100 << "%" << std::endl;
    }

    out.close();
}

void Writing_csv_file::Create_list(const std::map<std::string, int>& m_words) {

    for (auto it = m_words.begin(); it != m_words.end(); it++) {
        
        l_words.push_back(make_pair(it->second, it->first));
    }

    l_words.sort();
    l_words.reverse();
}


