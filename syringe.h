#ifndef SYRINGE_H
#define SYRINGE_H


#include<QGraphicsRectItem>
#include<QObject>
#include <QGraphicsPixmapItem>

class syringe: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    syringe();

public slots:
    void move();

signals:
    void sig_point();

};

#endif // SYRINGE_H
