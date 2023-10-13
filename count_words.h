#ifndef COUNT_WORDS_H
#define COUNT_WORDS_H

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <climits>
#include <algorithm>

class CountWords {
    private:
        std::map<std::string, int> countWords;
    public:
        CountWords();
        ~CountWords();
        int getCountWord(const std::string& word) const;
        int addWord(const std::string& word);
        std::list<std::pair<std::string, int>> getMaxCountWord() const;
        std::list<std::pair<std::string, int>> getMinCountWord() const;
};
#endif
