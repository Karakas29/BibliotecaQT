// main.cpp
#include <iostream>
#include "include/Libro.h"
#include "include/Film.h"
#include "include/Musica.h"
#include "include/Podcast.h"
#include "include/Giornale.h"

int main() {
    Libro libro(1, "Il Nome della Rosa", 1980, "Umberto Eco", "Bompiani", 512);
    Film film(2, "La Vita è Bella", 1997, "Roberto Benigni", "Gianluigi Braschi", 116, "path/to/image.jpg");
    Musica musica(3, "Bohemian Rhapsody", 1975, "Queen", "A Night at the Opera", 354, "path/to/image.jpg");
    Podcast podcast(4, "Serial", 2014, "Sarah Koenig", "This American Life", 12, "path/to/image.jpg");
    Giornale giornale(5, "The New York Times", 1851, "USA", "English", 1000000, "path/to/image.jpg");

    libro.display();
    film.display();
    musica.display();
    podcast.display();
    giornale.display();

    return 0;
}

