#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#endif // MAINWINDOW_H
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QStringListModel>
#include <QStringList>
#include "AbstractTransport.hpp"
#include "SetRoutes.hpp"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    SetRoutes sr;
    QStringListModel *model;
    QStringList datalist;

private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();

    void update_listView();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

