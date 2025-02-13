// Film.h
#ifndef FILM_H
#define FILM_H

#include "Media.h"

class Film : public Media {
private:
    std::string director;
    std::string producer;
    int duration; // in minuti
    std::string image;

public:
    Film(int id, const std::string& title, int year, const std::string& director, const std::string& producer, int duration, const std::string& image)
        : Media(id, "movie", title, year), director(director), producer(producer), duration(duration), image(image) {}

    std::string getDirector() const { return director; }
    std::string getProducer() const { return producer; }
    int getDuration() const { return duration; }
    std::string getImage() const { return image; }

    void display() const override {
        // Implementazione specifica per Film
        std::cout << "Film: " << title << " diretto da " << director << " (" << year << "), " << duration << " minuti." << std::endl;
    }
};

#endif // FILM_H