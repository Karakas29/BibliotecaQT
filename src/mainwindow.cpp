#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setupUI();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupUI() {
    // Crea il widget centrale
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Crea la tabella
    tableView = new QTableView(this);
    model = new QStandardItemModel(0, 4, this); // 4 colonne per ID, Titolo, Tipo, Anno
    model->setHorizontalHeaderLabels({"ID", "Titolo", "Tipo", "Anno"});
    tableView->setModel(model);

    // Crea i pulsanti
    QPushButton *btnAdd = new QPushButton("Aggiungi Media", this);
    QPushButton *btnRemove = new QPushButton("Rimuovi Selezionato", this);
    QPushButton *btnLoad = new QPushButton("Carica JSON", this);
    QPushButton *btnSave = new QPushButton("Salva JSON", this);

    // Aggiungi i widget al layout
    layout->addWidget(tableView);
    layout->addWidget(btnAdd);
    layout->addWidget(btnRemove);
    layout->addWidget(btnLoad);
    layout->addWidget(btnSave);

    // Collega i segnali ai slot
    connect(btnAdd, &QPushButton::clicked, this, &MainWindow::addMedia);
    connect(btnRemove, &QPushButton::clicked, this, &MainWindow::removeMedia);
    connect(btnLoad, &QPushButton::clicked, this, &MainWindow::loadFromJson);
    connect(btnSave, &QPushButton::clicked, this, &MainWindow::saveToJson);

    // Imposta il widget centrale
    setCentralWidget(centralWidget);
}

void MainWindow::addMedia() {
    int row = model->rowCount();
    model->insertRow(row);

    // Imposta dei valori predefiniti per il nuovo media (opzionale)
    model->setData(model->index(row, 1), "Nuovo Titolo");
    model->setData(model->index(row, 2), "Tipo di Media");
    model->setData(model->index(row, 3), 2023);
}

void MainWindow::removeMedia() {
    QModelIndexList selected = tableView->selectionModel()->selectedRows();
    for (const QModelIndex &index : selected) {
        model->removeRow(index.row());
    }
}

void MainWindow::loadFromJson() {
    QString fileName = QFileDialog::getOpenFileName(this, "Apri File JSON", "", "JSON Files (*.json)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Errore", "Impossibile aprire il file.");
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    QJsonObject root = doc.object();
    QJsonArray books = root["books"].toArray();

    model->setRowCount(0); // Svuota la tabella

    for (const QJsonValue &value : books) {
        QJsonObject obj = value.toObject();
        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(QString::number(obj["id"].toInt())));
        rowItems.append(new QStandardItem(obj["title"].toString()));
        rowItems.append(new QStandardItem(obj["type"].toString()));
        rowItems.append(new QStandardItem(QString::number(obj["year"].toInt())));
        model->appendRow(rowItems);
    }
}

void MainWindow::saveToJson() {
    QString fileName = QFileDialog::getSaveFileName(this, "Salva File JSON", "", "JSON Files (*.json)");
    if (fileName.isEmpty()) return;

    QJsonArray booksArray;
    for (int row = 0; row < model->rowCount(); ++row) {
        QJsonObject book;
        book["id"] = model->item(row, 0)->text().toInt();
        book["title"] = model->item(row, 1)->text();
        book["type"] = model->item(row, 2)->text();
        book["year"] = model->item(row, 3)->text().toInt();
        booksArray.append(book);
    }

    QJsonObject root;
    root["books"] = booksArray;
    
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Errore", "Impossibile scrivere il file.");
        return;
    }

    file.write(QJsonDocument(root).toJson());
    file.close();
}