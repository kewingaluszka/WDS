#ifndef PLAYER_H
#define PLAYER_H

#include<QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "mainwindow.h"
#include <QMediaPlayer>

/*!
 * \brief Klasa player
 * Klasa zawiera funkcje bezpośrednio związane z obsługą gracza i związanymi z nim funkcjonalnościami gry
 */
class player :public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    /*!
     * \brief Konstruktor
     */
    player(QMainWindow *view1);

    /*!
     * \brief Flaga ustawiana okresowo w momencie nadania zezwolenia do oddania
     * strzału
     */
    int flag =0;

public slots:
    /*!
     * \brief Generowanie przeciwnika na scenie
     */
    void spawn();
    /*!
     * \brief Ruch gracza lewo/prawo
     * \param [in] Data - odczyt żyroskopu z osi OY w postaci nieprzeliczonej na wartość [g]
     */
    void p_move(int Data);
    /*!
     * \brief Oddanie strzału przez gracza
     * \param [in] Data - odczyt żyroskopu z osi OX w postaci nieprzeliczonej na wartość [g]
     */
    void p_shoot(int Data);
    /*!
     * \brief Pozwolenie na strzał celem ograniczenia szumów z akcelerometru
     */
    void let_shoot();


private:
    QMainWindow *view;

};

#endif // PLAYER_H


