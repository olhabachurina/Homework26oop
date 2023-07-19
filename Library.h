#pragma once
#include "Book.h"
#include <string>
#include <map>
#include <fstream>
#include <set>

class Library {
public:
    void addBook(const std::string& title, const std::string& author, int year);
    void saveToFile(std::ofstream& outFile) const;

private:
    // Определение оператора сравнения для std::pair<std::string, int>
    struct PairCompare {
        bool operator()(const std::pair<std::string, int>& lhs, const std::pair<std::string, int>& rhs) const {
            return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
        }
    };

    std::map<std::string, std::multiset<std::pair<std::string, int>, PairCompare>> libraryData; // Автор -> (Название произведения, Дата издания)
};