#ifndef PARSE_TEXT_H
#define PARSE_TEXT_H

#include <list>
#include <string>
#include <utility>
#include <fstream>

class ParseText {
    private:
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
        ParseText(const std::string& fileName, unsigned long long maxWords);
        ~ParseText();

	const std::string& getFirstWord() const;
    	const std::pair<std::string, bool>& getNextWord() const;
	const std::string& getWordAt(int index) const; //начиная с 0
};

#endif // _parse_text_h_

