#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QVBoxLayout>
#include "FactoryPlane.hpp"
#include "FactoryTrain.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_listView()
{
    qDebug() << "update_view";
    model = new QStringListModel(this);
    datalist.clear();
    for (ITransport* transport : sr.GetTransports())
    {
        qDebug() << transport->GetInfo();
        datalist << QString::fromStdString(transport->GetInfo());
    }
    ui->totalPriceLabel->setText(QString::fromStdString("Total price: " + std::to_string(sr.GetPrice())));
    model->setStringList(datalist);
    ui->listView->setModel(model);
}


void MainWindow::on_addButton_clicked()
{
    Dialog* dlg = new Dialog(this);

    connect(dlg, &Dialog::dataChanged, this, &MainWindow::update_listView);

    FactoryPlane fp;
    FactoryTrain ft;

    if (dlg->exec() == QDialog::Accepted)
    {
        if (dlg->GetIndex() == 0)
        {
            qDebug() << dlg->GetRoute() << dlg->GetPrice() << dlg->GetMaxAltitude() << dlg->GetNameAirline();
            sr.Add(fp.create(dlg->GetRoute(), dlg->GetPrice(), dlg->GetMaxAltitude(), dlg->GetNameAirline()));
            update_listView();
        }
        else
        {
            qDebug() << dlg->GetRoute() << dlg->GetPrice() << dlg->GetStops() << dlg->GetCountCarriage();
            sr.Add(ft.create(dlg->GetRoute(), dlg->GetPrice(), dlg->GetStops(), dlg->GetCountCarriage()));
            update_listView();
        }
    }

    delete dlg;
}


void MainWindow::on_editButton_clicked()
{
    Dialog* dlg = new Dialog(this);

    QModelIndex index = ui->listView->currentIndex();

    FactoryPlane fp;
    FactoryTrain ft;

    connect(dlg, &Dialog::dataChanged, this, &MainWindow::update_listView);

    if(index.isValid())
    {
        ITransport* transport = sr.GetTransports()[index.row()];
        Plane* plane = dynamic_cast<Plane*>(transport);
        if(plane)
        {
            qDebug() <<  "plane";
            dlg->EditDataTransport(plane->GetRoute(),plane->GetPrice(), plane->GetMaxAltitude(), plane->GetNameAirline());
        }

        Train* train = dynamic_cast<Train*>(transport);
        if (train)
        {
            qDebug() <<  "train";
            dlg->EditDataTransport(train->GetRoute(), train->GetPrice(), train->GetStops(), train->GetCountCarriage());
        }

        if (dlg->exec() == QDialog::Accepted)
        {
            sr.Delete(index.row());
            if (dlg->GetIndex() == 0)
            {
                qDebug() << dlg->GetRoute() << dlg->GetPrice() << dlg->GetMaxAltitude() << dlg->GetNameAirline();
                sr.Add(fp.create(dlg->GetRoute(), dlg->GetPrice(), dlg->GetMaxAltitude(), dlg->GetNameAirline()));
            }
            else
            {
                qDebug() << dlg->GetRoute() << dlg->GetPrice() << dlg->GetStops() << dlg->GetCountCarriage();
                sr.Add(ft.create(dlg->GetRoute(), dlg->GetPrice(), dlg->GetStops(), dlg->GetCountCarriage()));
            }
            update_listView();
        }
    }

    delete dlg;
}



void MainWindow::on_deleteButton_clicked()
{
    QModelIndex index = ui->listView->currentIndex();

    if(index.isValid())
    {
        model->removeRow(index.row());
        sr.Delete(index.row());
    }
    update_listView();
}

