#ifndef COUNT_WORDS_H
#define COUNT_WORDS_H

#include <string>
#include <list>
#include <map>
#include <vector>
#include <tuple>
#include <climits>
#include <algorithm>

class CountWords {
    private:
        std::map<std::string, int> countWords;
        std::map<std::pair<std::string, std::string>, int> countWordsPairs;
    public:
        CountWords();
        ~CountWords();
        int getCountWord(const std::string& word) const;
        int addWord(const std::string& word);
        std::list<std::pair<std::string, int>> getMaxCountWord() const;
        std::list<std::pair<std::string, int>> getMinCountWord() const;
        int insertWordsPair(const std::pair<std::string, std::string>& pair_word);
        std::tuple<std::string, std::string, int> getWordPair(const std::pair<std::string, std::string>& pair_word);
};
#endif

