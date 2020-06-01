#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QList>
#include <QSerialPortInfo>
#include <QDateTime>
#include <QSerialPort>

namespace Ui {
class Settings;
}

/*!
 * \brief Klasa Settings
 * Klasa dziedzicząca QDialog, stanowiąca okno ustawień. Zawiera
 * obsługę funkcjonalności udostępnionych w oknie ustawień.
 */

class Settings : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Konstruktor
     */
    explicit Settings(QWidget *parent = nullptr);
    /*!
     * \brief Destruktor
     */
    ~Settings();

private slots:
    /*!
     * \brief Funkcja rozpoczynająca wyszukiwanie po wciśnięciu
     *  przcisku szukaj
     */
    void on_b_search_clicked();
    /*!
     * \brief Funkcja nawiązująca połączenie po wciśnięciu przycisku
     * połącz
     */
    void on_b_connect_clicked();
    /*!
     * \brief Funkcja zamykająca połączenie po wciśnięciu przycisku
     * połącz
     */
    void on_b_disconnect_clicked();
    /*!
     * \brief Funkcja wypisująca w oknie komunikaty dotyczące połączenia
     * i aktualnego jego statusu
     * \param [in] message - komunikat do dołączenia do okna
     */
    void slt_addToLogs(QString message);
    /*!
     * \brief Funkcja zamykająca okno ustawień
     */
    void on_b_close_clicked();

private:
    Ui::Settings *ui;
    QSerialPort *device;

signals:
    /*!
     * \brief Sygnał wykorzystany do nawiązania połączenia
     * \param [in] message - nazwa portu w formie "COMx"
     */
    void sig_usart_connect(QString message);
    /*!
     * \brief Sygnał wykorzystany do zamknięcia połączenia
     */
    void sig_usart_disconnect();


};

#endif // SETTINGS_H
