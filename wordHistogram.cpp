#include "wordHistogram.hpp"

std::vector<int> wordHistogram(std::string sentence) {
    std::stringstream in(sentence);

    std::vector<int> char_count;
    
    std::string word;

    while (in >> word) {
        //std::cout << word << std::endl;
        size_t len = word.size();

        while(char_count.size() < len + 1) {
            //std::cout << "push back 0";
            char_count.push_back(0);
        }

        char_count[len] += 1;
        //std::cout << len << std::endl;
    }

    return char_count;
}
/*
int main() {
    std::vector<int> char_count = wordHistogram("we love cpp");

    for (size_t i = 0; i < char_count.size(); ++i) {

        std::cout << char_count[i] << std::endl;
    }
}*/