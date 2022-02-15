#include"Read_input_file.h"

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
