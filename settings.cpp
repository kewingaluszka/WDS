#include "settings.h"
#include "ui_settings.h"
#include "usart.h"
#include <QDebug>
#include <algorithm>
#include <alg.h>
#include <stdio.h>
#include <cctype>



Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    //  this->device = new QSerialPort(this);

    setWindowTitle(tr("Ustawienia gry"));
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_b_search_clicked()
{
    QList<QSerialPortInfo> devices;
    devices = QSerialPortInfo::availablePorts();



    for(int i = 0; i < devices.count(); i++) {
        slt_addToLogs("Znaleziono urządzenie: " + devices.at(i).portName() + " " + devices.at(i).description());
        ui->uart_list->addItem(devices.at(i).portName() + " " + devices.at(i).description());
    }

    if(ui->uart_list->count() == 0) {
        slt_addToLogs("Nie wykryto żadnych urządzen");
        // return;
    }
}

void Settings::on_b_connect_clicked()
{
    if(ui->uart_list->count() == 0) {
        slt_addToLogs("Nie mozna połączyć. Nie wykryto żadnych urządzen");
        //return;
    }
    else{
        QString comboBoxQString = ui->uart_list->currentText();                  //take full name of port
        //  qDebug() << comboBoxQString;
        QStringList portList = comboBoxQString.split(" ");                        //split by space, returns list
        //  qDebug() << portList;
        QString portName = portList.first();                                      //first position is "COMx" where x is number of COM port
        //  qDebug() << portName;
        QString clear_portName = portName.replace(" ", "");                       //remove all spaces, not necesarry
        slt_addToLogs("Połączono z: " + clear_portName);

        emit sig_usart_connect(clear_portName);                                   // set connection
    }

}

void Settings::slt_addToLogs(QString message)
{

    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    ui->uart_term->append(currentDateTime + "\t" + message);
}



void Settings::on_b_disconnect_clicked()
{
    emit sig_usart_disconnect();
}


void Settings::on_b_close_clicked()
{
    this->close();
}
