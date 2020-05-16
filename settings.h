#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QList>
#include <QSerialPortInfo>
#include <QDateTime>
#include <QSerialPort>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private slots:
    void on_b_search_clicked();

    void on_b_connect_clicked();

    void on_b_disconnect_clicked();

    void slt_addToLogs(QString message);


private:
    Ui::Settings *ui;



    QSerialPort *device;

signals:
    void sig_usart_connect(QString); //Sygnal emitowany po wcisnieciu przycisku połącz
    void sig_usart_disconnect(); //Sygnal emitowany po wcisnieciu przycisku rozłącz


};

#endif // SETTINGS_H
