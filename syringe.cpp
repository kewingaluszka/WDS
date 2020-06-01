#include"syringe.h"
#include "virus.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>

syringe::syringe(): QObject(), QGraphicsPixmapItem()

{
    setPixmap(QPixmap(":/img/syringe.png"));

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

}



void syringe::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(virus)){
            // remove them both

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //syringe syringe;
            emit sig_point();

            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(), y()-10);
    if(pos().y() < -45){                    //position -50 due height of syringe
        scene() -> removeItem(this);
        delete this;
        qDebug() << "Syringe deleted!";
    }
}
