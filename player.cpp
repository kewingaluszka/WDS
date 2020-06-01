#include "player.h"
#include "mainwindow.h"
#include "syringe.h"
#include "virus.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QElapsedTimer>

player::player(QMainWindow *view1)
{
    view = view1;
    setPixmap(QPixmap(":/img/player.png"));
    qDebug()<<"player created!";

}


void player::spawn()
{
    virus * enemy = new virus();
    scene() -> addItem(enemy);
    connect(enemy,SIGNAL(sig_life()),view,SLOT(life_LCD()));

}


void player::p_move(int Data)
{
    if (Data < -700){
        //left
        setPos(x()-10, y());
        if (x() < -100 ){
            setPos(569, y());
            qDebug() << "hopla!";
        }
    }
    else if (Data > 700){
        //right
        setPos(x()+10, y());
        if (x()> 569){
            setPos(-100, y());
            qDebug() << "hopla!";
        }
    }

    //qDebug()<< Data<< "data";



}
void player::p_shoot(int Data){



    if (Data < -15000){
        if(flag>200){
            syringe * syringe1 = new syringe();
            syringe1 -> setPos(x(), y());
            scene() -> addItem(syringe1);
            qDebug()<< "syringe created!";
            connect(syringe1,SIGNAL(sig_point()),view,SLOT(points_LCD()));
            flag =0;

            QMediaPlayer * syringe_sound = new QMediaPlayer();
            syringe_sound ->setMedia(QUrl("qrc:/music/bullet.mp3"));
            syringe_sound->play();


        }
    }
}

void player::let_shoot()
{
    flag++;
    // qDebug() << flag ;
}



