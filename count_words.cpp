#include "count_words.h"

CountWords::CountWords() {}

CountWords::~CountWords() {
    countWords.clear();
}

int CountWords::getCountWord(const std::string& word) const {
    if (countWords.find(word) != countWords.end()) {
        return countWords.find(word)->second;
    }
    else {
        return 0;
    }
}

int CountWords::addWord(const std::string& word) {
    if (word == "") {
        return 0;
    }
    else {
        return ++countWords[word];
    }
}

std::list<std::pair<std::string, int>> CountWords::getMaxCountWord() const {
    int limit = 10;
    std::list<std::pair<std::string, int>> result;
    std::vector<std::pair<std::string, int>> allWords(countWords.begin(), countWords.end());
    std::sort(allWords.begin(), allWords.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
		return a.second > b.second;
    });
    for (auto item = allWords.begin(); item != allWords.end(); item++) {
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
    std::vector<std::pair<std::string, int>> allWords(countWords.begin(), countWords.end());
    std::sort(allWords.begin(), allWords.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
		return a.second > b.second;
    });
    for (auto item = allWords.end(); item != allWords.begin(); item--) {
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

