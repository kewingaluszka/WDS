#include "player.h"

#include "virus.h"
#include <QDebug>
#include <QKeyEvent>
#include "syringe.h"
#include <QGraphicsScene>

player::player()
{
    setPixmap(QPixmap(":/img/player.png"));
    qDebug()<<"player created!";
}

void player::keyPressEvent(QKeyEvent *event)
{
    if (event ->key() == Qt::Key_Left){
        setPos(x()-10, y());
        qDebug() << "left";
        if (x() < -100 ){
            setPos(569, y());
            qDebug() << "hopla!";
        }
    }

    else if (event ->key() == Qt::Key_Right){
        setPos(x()+10, y());

        qDebug() << "right";
        if (x()> 569){
            setPos(-100, y());
            qDebug() << "hopla!";
        }
    }


       else if (event ->key() == Qt::Key_Space){
        syringe * syringe1 = new syringe();
        syringe1 -> setPos(x(), y());
        scene() -> addItem(syringe1);
        qDebug()<< "syringe created!";
    }
}

void player::spawn()
{
    virus * enemy = new virus();
    scene() -> addItem(enemy);
}
