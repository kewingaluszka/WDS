#include"virus.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <QGraphicsPixmapItem>


virus::virus(): QObject(), QGraphicsPixmapItem()
{
    int random_pos = rand() %500;
    setPos(random_pos,0);

    setPixmap(QPixmap(":/img/virus.png"));

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

}

void virus::move(){
    setPos(x(), y()+10);
    if(pos().y() > 400){                    //position -50 due height of syringe
        emit sig_life();
        scene() -> removeItem(this);
        delete this;
        qDebug() << "enemy deleted!";
    }
}
