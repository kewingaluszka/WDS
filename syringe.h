#ifndef SYRINGE_H
#define SYRINGE_H
#include<QGraphicsRectItem>
#include<QObject>
#include <QGraphicsPixmapItem>

/*!
 * \brief Klasa syringe
 * Klasa dziedzicząca QObject oraz QGraphicsPixmapItem \n
 * Klasa reprezentująca pocisk - strzykawkę. Zawiera obsługę funkcjonalności
 * pocisku.
 */


class syringe: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    /*!
     * \brief Konstruktor
     */
    syringe();


public slots:
    /*!
     * \brief Funkcja animująca i wykonująca ruch strzykawki do góry,
     * realizująca usuwanie obiektów w momencie wykrycia kolizji lub
     * wyjścia poza scenę
     */
    void move();

signals:
    /*!
     * \brief Sygnał emitowany po zdobyciu punktu - po wykryciu kolizji
     * strzykawki z przeciwnikiem
     */
    void sig_point();

};

#endif // SYRINGE_H
