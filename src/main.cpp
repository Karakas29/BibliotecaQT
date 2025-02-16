// main.cpp
#include <iostream>
#include "include/Libro.h"
#include "include/Film.h"
#include "include/Musica.h"
#include "include/Podcast.h"
#include "include/Giornale.h"
#include <QApplication>
#include "include/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}

