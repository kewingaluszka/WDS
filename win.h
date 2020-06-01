#ifndef WIN_H
#define WIN_H

#include <QDialog>

namespace Ui {
class win;
}

/*!
 * \brief Klasa win reprezentującą okno wyświetlane po zakończeniu rozgrywki.
 * W oknie wyświetlana jest liczba punktów uzyskana przez użytkownika
 */

class win : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Konstruktor
     */
    explicit win(QWidget *parent = nullptr);
    /*!
     * \brief Destruktor
     */
    ~win();

private slots:
    /*!
     * \brief Funkcja zamykająca okno po wciśnięciu przycisku zamknij
     */
    void on_close_win_clicked();
    /*!
     * \brief Funkcja wyświetlająca w oknie liczbę punktów uzyskanych
     * podczas rozgrywki przez gracza
     * \param [in] points - liczba punktów uzyskanych przez gracza
     */
    void slt_win(int points);

private:
    Ui::win *ui;
};

#endif // WIN_H
