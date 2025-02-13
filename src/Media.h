// Media.h
#ifndef MEDIA_H
#define MEDIA_H

#include <string>

class Media {
protected:
    int id;
    std::string type;
    std::string title;
    int year;

public:
    Media(int id, const std::string& type, const std::string& title, int year)
        : id(id), type(type), title(title), year(year) {}

    virtual ~Media() {}

    int getId() const { return id; }
    std::string getType() const { return type; }
    std::string getTitle() const { return title; }
    int getYear() const { return year; }

    virtual void display() const = 0; // Metodo polimorfico puro
};

#endif // MEDIA_H
