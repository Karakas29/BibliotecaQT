QT += core widgets
CONFIG += c++17
SOURCES += src/main.cpp src/mainwindow.cpp
HEADERS += src/include/mainwindow.h src/include/Media.h src/include/Film.h src/include/Giornale.h src/include/Libro.h src/include/Musica.h src/include/Podcast.h
FORMS += ui/mainwindow.ui
DESTDIR = build/release
OBJECTS_DIR = build/obj