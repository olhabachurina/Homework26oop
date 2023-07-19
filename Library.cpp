#include "Library.h"
#include <stdexcept>
#include <fstream>
#include <set> // ���������, ������� ������ ���������� �������� � ��������������� �������
void Library::addBook(const std::string& title, const std::string& author, int year) {
    if (year <= 0) {
        throw std::invalid_argument("Invalid year. Year must be a positive number.");
    }

    auto& books = libraryData[author];//// ���������, ���� �� ��� ����� ����� � ����������. ���� ���, ������� ����� ������ ��� ����.

    if (books.find(std::make_pair(title, year)) != books.end()) {//���������, ���� �� ��� ����� ����� � ����� ������ �� �������� � ���� �������.
        throw std::invalid_argument("Book already exists in the library.");
    }

    books.insert(std::make_pair(title, year));// ��������� �����  ��� ������� ������.
}

void Library::saveToFile(std::ofstream& outFile) const {//������� ��������� ������ �� ����,� ������� ����� �������� ������
    if (!outFile) {
        throw std::runtime_error("Error opening the file.");//���� ������ �������� �����
    }

    for (const auto& entry : libraryData) {
        const std::string& author = entry.first;
        const std::multiset<std::pair<std::string, int>, PairCompare>& books = entry.second;

        for (const auto& book : books) {// ���������� ���������� �� ������ � ������ � ����.
            outFile << author << "," << book.first << "," << book.second << "\n";
        }
    }
}