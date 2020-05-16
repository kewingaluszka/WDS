#ifndef USART_H
#define USART_H

#include <QDialog>
#include <QList>
#include <QtSerialPort>
#include <QSerialPortInfo>



class usart: public QObject
{
    Q_OBJECT
public:
    usart();
    ~usart();

private:
    QSerialPort *device;
    QByteArray serialData;
    QString serialBuffer;
    //void addToLogs(QString message);

private slots:

    void slt_usart_connect(QString clear_portName);
    void slt_usart_disconnect();
    void usart_read();



signals:

    void plotData(QList <float>);
    void sig_addToLogs(QString message);
    void sig_writeStatus(QString message);
    void sig_clearStatus();

};

#endif // USART_H
