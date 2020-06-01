#ifndef USART_H
#define USART_H
#include <QDialog>
#include <QList>
#include <QtSerialPort>
#include <QSerialPortInfo>


/*!
 * \brief Klasa usart
 * Klasa dziedzicząca QObject \n
 * Klasa zawierające funkcje wykorzystywane podczas realizacji połączenia
 * przez protokół USART
 */
class usart: public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief Konstruktor
     */
    usart();
    /*!
     * \brief Destruktor
     */
    ~usart();


private:
    QSerialPort *device;
    QByteArray serialData;
    QString serialBuffer;


private slots:
    /*!
     * \brief Funkcja nawiązująca połączenie z danym portem
     * \param [in] clear_portName - mazwa portu w formie "COMx"
     */
    void slt_usart_connect(QString clear_portName);
    /*!
     * \brief Funkcja realizująca rozłączenie połączenia z portem, z którym
     * aktualnie nawiązanie jest połączenie
     */
    void slt_usart_disconnect();
    /*!
     * \brief Funkcja realizująca rozłączenie połączenia z portem, z którym
     * aktualnie nawiązanie jest połączenie
     */
    void usart_read();
    /*!
     * \brief Funkcja realizująca odczytywanie danych z portu szeregowego oraz
     * obsługę sumy kontrolnej
     */



signals:
    /*!
     * \brief Sygnał emitowany celem dodania danych do wykresu
     * \param [in] Data - lista odczytanych i przeliczonych danych odczytanych z akcelerometru w jednostce [g]
     */
    void plotData(QList <float> Data);
    /*!
     * \brief Sygnał emitowany celem wykonania ruchu przez użytkownika
     * \param [in] Data - odczyt żyroskopu z osi OY w postaci nieprzeliczonej na wartość [g]
     */
    void moveData(int Data);
    /*!
     * \brief Sygnał emitowany celem oddania strzału przez użytkownika
     * \param [in] Data - odczyt żyroskopu z osi OX w postaci nieprzeliczonej na wartość [g]
     */
    void shootData(int Data);
    /*!
     * \brief Sygnał emitowany celem dodania komunikatu do okna ustawień
     * \param [in] message - komunikat do dodania
     */
    void sig_addToLogs(QString message);
    /*!
     * \brief Sygnał emitowany celem dodania komunikatu do okna ustawień
     * \param [in] message - komunikat do wyświetlenia
     */
    void sig_writeStatus(QString message);
    /*!
     * \brief Sygnał emitowany celem wyczyszczenia widżetu statusu połączenia
     */
    void sig_clearStatus();

};

#endif // USART_H
