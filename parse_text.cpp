// parse_text.cpp

#include "parse_text.h"


ParseText::ParseText(const std::string& fileName) {
    openFile(fileName);
    lastWord = words.empty();
    int ParseText::currentWord = 0;
}

ParseText::ParseText(const std::string& fileName, unsigned long long maxWords) {
    openFile(fileName);
    for (unsigned long long i = 0; i < maxWords; ++i) {
        if (!lastWord) {
            parseFile();
        }
	else {
            break;
        }
    }
    lastWord = words.empty();
}

ParseText::~ParseText() {
    closeFile();
}

void ParseText::openFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open file: " + fileName);
    }
    lastWord = words.empty();
}

void ParseText::parseFile() {
    if (currentWord < words.size()) {
        lastWord = (currentWord == (words.size() - 1));
        currentWord++;
    }
    else {
        lastWord = true;
    }
}

void ParseText::closeFile() {
    std::ifstream file(fileName);
    file.close();
}

const std::string& ParseText::getFirstWord() const {
    currentWord = 0;
    if (!words.empty()) {
        return words.front();
    }
    else {
        static std::string emptyString;
        return emptyString;
    }
}
const std::pair<std::string, bool>& ParseText::getNextWord() const {
    std::string first;
    int second;
    if (currentWord != (words.size() - 1)) {
	auto item = words.begin();
	std::advance(item, currentWord + 1);
	first = *item;
        second = (currentWord == (words.size() - 1));
	currentWord += 1;
    }
    else {
	first = "";
        second = true;
    }
    const std::pair<std::string, int> result = {first, second};
    return result;
}

const std::string& ParseText::getWordAt(int index) const {
    static std::string emptyString;
    if (index >= 0 and index < words.size()) {
        auto it = words.begin();
        std::advance(it, index);
        return *it;
    }
    else {
        return emptyString;
    }
}

