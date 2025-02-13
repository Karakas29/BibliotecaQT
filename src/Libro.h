// Libro.h
#ifndef LIBRO_H
#define LIBRO_H

#include "Media.h"

class Libro : public Media {
private:
    std::string author;
    std::string editor;
    int pages;

public:
    Libro(int id, const std::string& title, int year, const std::string& author, const std::string& editor, int pages)
        : Media(id, "book", title, year), author(author), editor(editor), pages(pages) {}

    std::string getAuthor() const { return author; }
    std::string getEditor() const { return editor; }
    int getPages() const { return pages; }

    void display() const override {
        // Implementazione specifica per Libro
        std::cout << "Libro: " << title << " di " << author << " (" << year << "), " << pages << " pagine." << std::endl;
    }
};

#endif // LIBRO_H