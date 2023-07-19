#include "Library.h"
#include <stdexcept>
#include <fstream>
#include <set> // контейнер, который хранит уникальные значения в отсортированном порядке
void Library::addBook(const std::string& title, const std::string& author, int year) {
    if (year <= 0) {
        throw std::invalid_argument("Invalid year. Year must be a positive number.");
    }

    auto& books = libraryData[author];//// Проверяем, есть ли уже такой автор в библиотеке. Если нет, создаем новую запись для него.

    if (books.find(std::make_pair(title, year)) != books.end()) {//Проверяем, есть ли уже такая книга у этого автора по названию и году издания.
        throw std::invalid_argument("Book already exists in the library.");
    }

    books.insert(std::make_pair(title, year));// Добавляем книгу  для данного автора.
}

void Library::saveToFile(std::ofstream& outFile) const {//Функция принимает ссылку на файл,в который будут записаны данные
    if (!outFile) {
        throw std::runtime_error("Error opening the file.");//Если файлне удалость найти
    }

    for (const auto& entry : libraryData) {
        const std::string& author = entry.first;
        const std::multiset<std::pair<std::string, int>, PairCompare>& books = entry.second;

        for (const auto& book : books) {// Записываем информацию об авторе и книгах в файл.
            outFile << author << "," << book.first << "," << book.second << "\n";
        }
    }
}