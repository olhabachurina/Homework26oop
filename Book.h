#pragma once
#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author, int year);

    
    std::string getTitle() const;// Методы доступа к полям
    std::string getAuthor() const;
    int getYear() const;

   
    void display() const; // Метод для вывода информации о книге

private:
    std::string title;
    std::string author;
    int year;
};
