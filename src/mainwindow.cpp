// mainwindow.cpp
#include "include/mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addButton_clicked() {
    // Implementazione per aggiungere un media
    QMessageBox::information(this, "Add", "Add button clicked");
}

void MainWindow::on_removeButton_clicked() {
    // Implementazione per rimuovere un media
    QMessageBox::information(this, "Remove", "Remove button clicked");
}