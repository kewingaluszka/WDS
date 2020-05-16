#ifndef VIRUS_H
#define VIRUS_H


#include<QGraphicsRectItem>
#include<QObject>

class virus: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    virus();

public slots:
    void move();


};

#endif // VIRUS_H
