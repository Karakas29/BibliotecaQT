// Musica.h
#ifndef MUSICA_H
#define MUSICA_H

#include "Media.h"

class Musica : public Media {
private:
    std::string artist;
    std::string album;
    int duration; // in secondi
    std::string image;

public:
    Musica(int id, const std::string& title, int year, const std::string& artist, const std::string& album, int duration, const std::string& image)
        : Media(id, "music", title, year), artist(artist), album(album), duration(duration), image(image) {}

    std::string getArtist() const { return artist; }
    std::string getAlbum() const { return album; }
    int getDuration() const { return duration; }
    std::string getImage() const { return image; }

    void display() const override {
        // Implementazione specifica per Musica
        std::cout << "Musica: " << title << " di " << artist << " (" << year << "), " << duration << " secondi." << std::endl;
    }
};

#endif // MUSICA_H