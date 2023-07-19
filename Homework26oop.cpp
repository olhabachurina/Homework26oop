// Homework26oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Library.h"
#include <iostream>
#include <string>
#include <fstream>

int main() {
    Library library;
    std::string title, author;
    int year;

    try {
        while (true) {
            std::cout << "Enter book title (or 'exit' to finish): ";
            std::getline(std::cin, title);

            if (title == "exit") {
                break;
            }

            std::cout << "Enter book author: ";
            std::getline(std::cin, author);

            std::cout << "Enter year of publication: ";
            std::cin >> year;

            std::cin.ignore(); // Очистка буфера после ввода числа

            library.addBook(title, author, year);
        }

        std::string filename;
        std::cout << "Enter filename to save the library: ";//Введите имя файла для сохранения информации о библиотеке
        std::getline(std::cin, filename);

        std::ofstream outFile(filename, std::ios::app);
        outFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);

        if (outFile.is_open()) {
            library.saveToFile(outFile);
        std::cout << "Library information has been successfully saved to " << filename << std::endl;//Информация о библиотеке успешно сохранена в файле
        }
        else {
            std::cerr << "Error! Unable to open file " << filename << " для записи." << std::endl;//Ошибка! Невозможно открыть файл
        }

    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
