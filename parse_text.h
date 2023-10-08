#ifndef PARSE_TEXT_H
#define PARSE_TEXT_H

#include <list>
#include <string>
#include <utility>
#include <fstream>
#include <regex>

class ParseText {
    private:
        std::ifstream file;
        std::string fileName;
        std::list<std::string> words;
        static int currentWord;
        bool lastWord;

        void openFile(const std::string& fileName);
        void parseFile();
        void closeFile();

    public:
        ParseText() = delete;
        ParseText(const std::string& fileName);
        ParseText(const std::string& fileName, unsigned long long int maxWords);
        ~ParseText();

        const std::string& getFirstWord() const;
        std::pair<std::string, bool> getNextWord() const;
        const std::string& getWordAt(int index) const; //начиная с 0
        void filePuring(const std::string& inputFileName, const std::string& ouputFileName) const;
};

#endif // _parse_text_h_
