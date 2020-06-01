#include "usart.h"
#include <string.h>

usart::usart()
{
    this -> device = new QSerialPort;
}

usart::~usart()
{
    delete device;
}



void usart::slt_usart_connect(QString clear_portName)
{
    this->device->setPortName(clear_portName);

    if(!device->isOpen()){
        if(device->open(QSerialPort::ReadWrite)) {
            this->device->setBaudRate(QSerialPort::Baud9600);
            this->device->setDataBits(QSerialPort::Data8);
            this->device->setParity(QSerialPort::NoParity);
            this->device->setStopBits(QSerialPort::OneStop);
            this->device->setFlowControl(QSerialPort::NoFlowControl);

            qDebug() << "Otwarto port szeregowy.";
            connect(this->device, SIGNAL(readyRead()), this, SLOT(usart_read()));
            emit sig_clearStatus();
            QString stat_con;
            stat_con = tr("<font color = green >Połączono\n"" </font size = 11 >");
            emit sig_writeStatus(stat_con);
        }
    }
    else{
        emit sig_addToLogs("Nie można otworzyć portu");
    }
}




void usart::slt_usart_disconnect()
{

    if(this->device->isOpen())
    {
        this->device->close();
        emit sig_addToLogs("Zakonczono polaczenie");
        emit sig_clearStatus();
        QString stat_dis;
        stat_dis = tr("<font color = red >Rozłączono\n"" </font size = 11 >");
        emit sig_writeStatus(stat_dis);

    }
    else
    {
        emit sig_addToLogs("Nie mozna zamknac portu. Port nie jest otwarty");
        return;
    }


}

void usart::usart_read() {


    float resolution = 2.0;
    QString tmp_buffer;
    QStringList buffer_list, good_buffer_list;


    while(this->device->canReadLine()) {

        QString tmp_buffer = this->device->readLine();                  //read line from port and add to buffer
        // qDebug() << "line" << tmp_buffer;

        //serialData = device->readAll();
        // tmp_buffer = this->device->readLine();
        //qDebug() << "serial" << tmp_buffer;

        buffer_list = tmp_buffer.split(" ");                            //split by space

        // qDebug() << "rozdzielone" << buffer_list;

        bool bStatus = false;
        int16_t CRC_read = buffer_list[4].toInt(&bStatus,16);
        int16_t CRC_comp = 0;
        int16_t tmp_sum = 0;

        // qDebug() << "CRC_READ=" << CRC_read;

        for(int i =1; i<4; i++){
            tmp_sum = tmp_sum + abs(buffer_list[i].toInt());
        }

        CRC_comp =(tmp_sum %256);

        //qDebug() << "CRC_COMP=" << CRC_comp;

        if(CRC_read == CRC_comp){

            //qDebug() << "POPRAWNA RAMKA";

            good_buffer_list = buffer_list;

            int16_t unconverted_acc_x = good_buffer_list[1].toInt();
            int16_t unconverted_acc_y = good_buffer_list[2].toInt();
            int16_t unconverted_acc_z = good_buffer_list[3].toInt();

            emit moveData(unconverted_acc_y);
            emit shootData(unconverted_acc_x);

            float acc_x = ((float)unconverted_acc_x*resolution)/((float)INT16_MAX);
            float acc_y = ((float)unconverted_acc_y*resolution)/((float)INT16_MAX);
            float acc_z = ((float)unconverted_acc_z*resolution)/((float)INT16_MAX);

            QList<float> acc_list = {acc_x, acc_y, acc_z};

            // qDebug()<<"data:" << acc_list;

            emit plotData(acc_list);

        }

        // serialBuffer="";
        buffer_list.clear();
        good_buffer_list.clear();






    }



    //emit sig_addToLogs(line.left(pos));

}


