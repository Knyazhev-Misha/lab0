#include "Writing_csv_file.h"

Writing_csv_file::Writing_csv_file(const Read_input_file& ltr) {
    std::map<std::string, int> m_words = ltr.Getmap();
    
    for (auto it = m_words.begin(); it != m_words.end(); it++) {

        l_words.push_back(make_pair(it->second, it->first));
    }

    l_words.sort();
    l_words.reverse();

    number = ltr.Getnumber();
}

Writing_csv_file::~Writing_csv_file() {
    l_words.clear();
}

void Writing_csv_file::Writing_file(std::string ptr) {
    std::ofstream out;
    float frequency;

    out.open(ptr);

    for (auto it = l_words.begin(); it != l_words.end(); it++) {
        frequency = it->first * 1.0 / number;

        out << it->second << ";" << frequency << ";" << frequency * 100 << "%" << std::endl;
    }

    out.close();
}