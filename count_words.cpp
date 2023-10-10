#include "count_words.h"

bool cmp(std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
    return a.second < b.second;
}
 
void Sort(std::map<std::string, int>& M) {
    std::vector<std::pair<std::string, int>> A; 
    for (auto& it : M) {
        A.push_back(it);
    }
    sort(A.begin(), A.end(), cmp);
}


CountWords::CountWords(std::string file_name) {
    file = file_name;
    std::map<std::string, int> countWords;
    std::ifstream File;
    File.open(file);
    if (!File.is_open()) {
        throw std::runtime_error("couldn't open file: " + file);
    }
    else {
        File.close;
    }
}

CountWords::~CountWords() {
    countWords.clear();
    std::ifstream tfile(file);
    tfile.close();
}

int CountWords::getCountWord(const std::string& word) const {
    std::ifstream tfile(file);
    int count_words = 0;
    std::string tword;
    if (tfile.is_open()) {
        for (tfile >> tword; !tfile.eof(); tfile >> tword) {
            if (word == tword) {
                count_words += 1;
            }
        }
    }
    else {
        std::cout << "[ERROR] File is not opened" << std::endl;
    }
    return count_words;
}

int CountWords::addWord(const std::string& word) {
    std::ifstream tfile(file);
    int count_words = 0;
    std::string tword;
    if (tfile.is_open()) {
        for (tfile >> tword; !tfile.eof(); tfile >> tword) {
            if (word == tword) {
                count_words += 1;
            }
        }
        countWords[word] = count_words;
    }
    else {
        std::cout << "[ERROR] File is not opened" << std::endl;
    }
    Sort(countWords);
    return count_words;
}

std::list<std::pair<std::string, int>> CountWords::getMaxCountWord() const {
    int limit = 10;
    std::list<std::pair<std::string, int>> result;
    for (auto item = countWords.begin(); item != countWords.end(); item++) {
        if (limit != 0) {
            result.push_back(std::pair(item->first, item->second));
            limit -= 1;
        }
        else {
            break;
        }
    }
    return result;
}

std::list<std::pair<std::string, int>> CountWords::getMinCountWord() const {
    int limit = 10;
    std::list<std::pair<std::string, int>> result;
    for (auto item = countWords.end(); item != countWords.begin(); item--) {
        if (limit != 0) {
            result.push_back(std::pair(item->first, item->second));
            limit -= 1;
        }
        else {
            break;
        }
    }
    return result;
}

