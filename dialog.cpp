#include "dialog.h"
#include "ui_dialog.h"
#include <QComboBox>
#include <QOverload>
#include <string>
#include <vector>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QStringList TransportOptions;
    TransportOptions << "Plain" << "Train";
    ui->comboBox->addItems(TransportOptions);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    emit dataChanged();
}

void Dialog::on_comboBox_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
        ui->comboBox->setCurrentIndex(0);
        ui->StopsLabel->hide();
        ui->StopsTextEdit->hide();
        ui->CountCarriageLabel->hide();
        ui->CountCarriageLineEdit->hide();

        ui->MaxAltitudeLabel->show();
        ui->MaxAltitudeLineEdit->show();
        ui->NameAirlineLabel->show();
        ui->NameAirlineLineEdit->show();
        break;
    case 1:
        ui->comboBox->setCurrentIndex(1);
        ui->MaxAltitudeLabel->hide();
        ui->MaxAltitudeLineEdit->hide();
        ui->NameAirlineLabel->hide();
        ui->NameAirlineLineEdit->hide();

        ui->StopsLabel->show();
        ui->StopsTextEdit->show();
        ui->CountCarriageLabel->show();
        ui->CountCarriageLineEdit->show();
        break;
    }
}

void Dialog::EditDataTransport(std::string route, int price, int maxAltitude, std::string nameAirline)
{
    ui->RouteLineEdit->setText(QString::fromStdString(route));
    ui->PriceLineEdit->setText(QString::number(price));
    ui->MaxAltitudeLineEdit->setText(QString::number(maxAltitude));
    ui->NameAirlineLineEdit->setText(QString::fromStdString(nameAirline));

    on_comboBox_currentIndexChanged(0);
}

void Dialog::EditDataTransport(std::string route, int price, std::vector<std::string> stops, int countCarriage)
{
    ui->RouteLineEdit->setText(QString::fromStdString(route));
    ui->PriceLineEdit->setText(QString::number(price));
    QStringList list;
    for (const std::string& s : stops)
    {
        list << QString::fromStdString(s);
    }
    ui->StopsTextEdit->setPlainText(list.join('\n'));
    ui->CountCarriageLineEdit->setText(QString::number(countCarriage));

    on_comboBox_currentIndexChanged(1);
}

int Dialog::GetIndex()
{
    return ui->comboBox->currentIndex();
}

std::string Dialog::GetRoute()
{
    return ui->RouteLineEdit->text().toStdString();
}

int Dialog::GetPrice()
{
    return ui->PriceLineEdit->text().toInt();
}

int Dialog::GetMaxAltitude()
{
    return ui->MaxAltitudeLineEdit->text().toInt();
}

std::string Dialog::GetNameAirline()
{
    return ui->NameAirlineLineEdit->text().toStdString();
}

std::vector<std::string> Dialog::GetStops()
{
    QString text = ui->StopsTextEdit->toPlainText();
    QStringList lines = text.split('\n', Qt::SkipEmptyParts);
    std::vector<std::string> result;
    result.reserve(text.size());

    for (QString &str : lines)
    {
        result.push_back(str.simplified().toStdString());
    }

    return result;
}

int Dialog::GetCountCarriage()
{
    return ui->CountCarriageLineEdit->text().toInt();
}
