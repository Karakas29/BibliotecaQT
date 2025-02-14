#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addMedia();
    void removeMedia();
    void loadFromJson();
    void saveToJson();

private:
    Ui::MainWindow *ui;
    QTableView *tableView;
    QStandardItemModel *model;
    void setupUI();
    void populateTable();
};

#endif // MAINWINDOW_H
