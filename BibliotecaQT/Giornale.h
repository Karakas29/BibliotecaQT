// Giornale.h
#ifndef GIORNALE_H
#define GIORNALE_H

#include "Media.h"

class Giornale : public Media {
private:
    std::string country;
    std::string language;
    int circulation;
    std::string image;

public:
    Giornale(int id, const std::string& title, int year, const std::string& country, const std::string& language, int circulation, const std::string& image)
        : Media(id, "newspaper", title, year), country(country), language(language), circulation(circulation), image(image) {}

    std::string getCountry() const { return country; }
    std::string getLanguage() const { return language; }
    int getCirculation() const { return circulation; }
    std::string getImage() const { return image; }

    void display() const override {
        // Implementazione specifica per Giornale
        std::cout << "Giornale: " << title << " (" << year << "), " << country << ", " << language << ", " << circulation << " copie." << std::endl;
    }
};

#endif // GIORNALE_H