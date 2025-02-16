// Podcast.h
#ifndef PODCAST_H
#define PODCAST_H

#include "Media.h"

class Podcast : public Media {
private:
    std::string host;
    std::string network;
    int episodes;
    std::string image;

public:
    Podcast(int id, const std::string& title, int year, const std::string& host, const std::string& network, int episodes, const std::string& image)
        : Media(id, "podcast", title, year), host(host), network(network), episodes(episodes), image(image) {}

    std::string getHost() const { return host; }
    std::string getNetwork() const { return network; }
    int getEpisodes() const { return episodes; }
    std::string getImage() const { return image; }

    void display() const override {
        // Implementazione specifica per Podcast
        std::cout << "Podcast: " << title << " ospitato da " << host << " (" << year << "), " << episodes << " episodi." << std::endl;
    }
};

#endif // PODCAST_H