#include "parse_text.h"

int ParseText::currentWord = 0;

ParseText::ParseText(const std::string& fileName) {
    filePuring(fileName, fileName + ".tmp");
    file = std::ifstream(fileName + ".tmp");
    parseFile();
}

ParseText::ParseText(const std::string& fileName, unsigned long long int maxWords) {
    openFile(fileName);
    parseFile();
    if (maxWords < words.size()) {
        auto it = words.begin();
        std::advance(it, maxWords);
        words.erase(it, words.end());
    }
}

ParseText::~ParseText() {
    closeFile();
}

void ParseText::filePuring(const std::string& inputFileName, const std::string& outputFileName) const {
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);
    char c;
    while(inputFile.get(c)) {   
        if (std::ispunct(c) || std::isdigit(c)) {
            outputFile.put(' ');
        }
        else {
            outputFile.put(c);
        }
    }
    inputFile.close();
    outputFile.close();
}

void ParseText::openFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open file: " + fileName);
    }
}

void ParseText::parseFile() {
    if (!file.is_open()) {
        throw std::runtime_error("couldn't open file");
    }
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }
}

void ParseText::closeFile() {
    std::ifstream file(fileName);
    file.close();
}

const std::string& ParseText::getFirstWord() const {
    currentWord = 0;
    if (words.empty()) {
        throw std::runtime_error("no words in the list");
    }
    return words.front();
}

std::pair<std::string, bool> ParseText::getNextWord() const {
    std::string first;
    bool second;
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
    std::pair<std::string, int> result = {first, second};
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
        return "";
    }
}
