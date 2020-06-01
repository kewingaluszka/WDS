#ifndef VIRUS_H
#define VIRUS_H
#include<QGraphicsRectItem>
#include<QObject>
#include "mainwindow.h"

/*!
 * \brief Klasa virus
 * Klasa dziedzicząca QObject oraz QGraphicsPixmapItem \n
 * Klasa reprezentująca wirusa - przeciwnika. Zawiera obsługę funkcjonalności
 * przeciwnika.
 */
class virus: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    /*!
     * \brief Konstruktor
     */
    virus();


public slots:
    /*!
     * \brief Funkcja animująca i wykonująca ruch wirusa w dół,
     * realizująca usuwanie przeciwnika w momencie wyjścia poza scenę
     */
    void move();

signals:
    /*!
     * \brief Sygnał emitowany po utracie punktu życia - w momencie
     * wyjścia przeciwnika poza obszar sceny
     */
    void sig_life();



};

#endif // VIRUS_H
