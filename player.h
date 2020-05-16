#ifndef PLAYER_H
#define PLAYER_H
#include<QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>


class player :public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    player();
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();

};

#endif // PLAYER_H


