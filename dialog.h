#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <string>
#include <vector>

namespace Ui
{
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    Ui::Dialog *ui;

    void EditDataTransport(std::string route, int price, int maxAltitude, std::string nameAirline);
    void EditDataTransport(std::string route, int price, std::vector<std::string> stops, int countCarriage);;

    int GetIndex();

    std::string GetRoute();
    int GetPrice();

    int GetMaxAltitude();
    std::string GetNameAirline();
    std::vector<std::string> GetStops();
    int GetCountCarriage();


signals:
    void dataChanged();

private:

private slots:
    void on_buttonBox_accepted();
    void on_comboBox_currentIndexChanged(int index);
};

#endif // DIALOG_H
