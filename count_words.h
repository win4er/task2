#ifndef COUNT_WORDS_H
#define COUNT_WORDS_H

#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <bits/stdc++.h>

bool cmp(std::pair<std::string, int>& a, std::pair<std::string, int>& b);
void Sort(std::map<std::string, int>& M);

class CountWords {
    private:
    //здесь можно объявлять любые необходимые переменные
        std::string file;
        std::map<std::string, int> countWords;
    public:
        CountWords();
        ~CountWords();
        int getCountWord(const std::string& word) const;
        int addWord(const std::string& word); //возвращает число слов, встретившихся в тексте
        std::list<std::pair<std::string, int>> getMaxCountWord() const; // возвращает список слов, которые встретились чаще других не более 10 слов
        std::list<std::pair<std::string, int>> getMinCountWord() const; // возвращает список слов, которые встретились реже других не более 10 слов
};
#endif

