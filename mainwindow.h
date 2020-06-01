#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>
#include <QMainWindow>
#include <QGraphicsScene>
#include "settings.h"
#include "usart.h"
#include "player.h"
#include "syringe.h"
#include "win.h"

/*!
 * \mainpage Gra zręcznościowa „Straszna Epidemia" V1.2
 *
 * \section etykieta-sterowanie Sterowanie
 * Sterowanie odbywa się z użyciem dedykowanego do niniejszej gry kontrolera
 * wykorzystującym akcelerometr. \n
 * Użytkownik ma możliwość zmiany położenia postaci gracza przez zmianę orientacji
 * kontrolera i wykonywanie nim ruchu skętnego (lewo/prawo). Wykonanie nagłego
 * ruchu do przodu skutkuje oddaniem strzału.
 *
 * \section etykieta-glowne Okno główne
 * Okno główne zawiera okno gry, wyświetlacze „LCD" prezentujące ilość uzyskanych
 * przez użytkownika punktów jak i pozostałe punkty życia. Okno zawiera przyciski
 * obsługi gry „Start", „Koniec" oraz „Pauza" oraz przycisk „Ustawienia" otwierający
 * okno ustawień. Okno zawiera również sekcję zawierającą wykresy przyspieszenia
 * zarejestrwanego w trzech osiach. W pasku stanu udostępniana jest informacja
 * o obecnym stanie gry. Okno zawiera również widżet informujący uytkownika o aktualnym
 * stanie rozgrywki
 *
 * \section etykieta-ustawienia Okno ustawień
 * W oknie ustawień użytkownikowi udostępniono możliwość wyszukania dostępnych urządzeń
 * magistrali szeregowej, wybrania urządzenia, nawiązania i zerwania połączenia
 *
 * \section etykieta-koncowe Okno końcowe
 * Okno końcowe przedstawia użytkownikowi liczbę uzyskanych przez niego punktów, gdy gra
 * zakończy się z powodu utraty wszystkich punktów życia lub zostanie zakończona przez
 * użytkownika.
 */


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief Klasa MainWindow
 * Klasa dziedzicząca QMainWindow, jest ona głównym oknem aplikacji \n
 * Klasa zawiera informacje o stanie gry oraz funkcje związane z obsługą
 * funkcjonalności udostępnionych w oknie głównym gry
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Konstruktor
     */
    MainWindow(QWidget *parent = nullptr);
    /*!
     * \brief Destruktor
     */
    ~MainWindow();
    /*!
     * \brief Czas wykorzystywany do rysowania osi OX wykresów pomiaru
     *  przyspieszenia w jednostce [s]
     */
    float t_plot = 0;
    /*!
     * \brief Liczba punktów uzyskanych przez gracza
     */
    int points = 0;
    /*!
     * \brief Liczba życia, które pozostało graczowi
     */
    int life =5;

private slots:
    /*!
     * \brief Funkcja wywołująca okno ustawień po naciśnięciu
     * przycisku ustawienia
     */
    void on_b_settings_clicked();
    /*!
     * \brief Funkcja rozpoczynająca rozgrywkę po naciśnięciu
     * przycisku start
     */
    void on_b_start_clicked();
    /*!
     * \brief Funkcja kończąca rozgrywkę i wyświetlająca wynik
     *  po naciśnięciu przycisku stop
     */
    void on_b_koniec_clicked();
    /*!
     * \brief Funkcja wstrzymująca rozgrywkę po wciśnięciu
     * przycisku pauza oraz wznawiająca rozgrywkę po jego
     * wyciśnięciu
     * \param [in] checked - parametr określający wciśnięcie lub wyciśnięcie przycisku
     */
    void on_b_pauza_toggled(bool checked);
    /*!
     * \brief Funkcja wypisująca status połączenia
     * \param [in] message - wiadomość o stanie połaczenia
     */
    void slt_writeStatus(QString message);
    /*!
     * \brief Funkcja usuwająca z widżetu status połączenia
     */
    void slt_clearStatus();
    /*!
     * \brief Funkcja rysująca wykres
     * \param [in] acc_data - lista odczytanych i przeliczonych danych odczytanych z akcelerometru w jednostce [g]
     */
    void makePlot(QList<float> acc_dat);
    /*!
     * \brief Funkcja dodająca punkt po jego zdobyciu i wyświetlająca ilość punktów
     */
    void points_LCD();
    /*!
     * \brief Funkcja odejmująca życie po jego utracie i wyświetlająca ilość pozostałego życia
     */
    void life_LCD();
    /*!
     * \brief Funkcja wyświetlająca dane w konsoli debug
     * \param [in] Data - odczyt żyroskopu z osi OY w postaci nieprzeliczonej na wartość [g]
     */
    void plot_moveData(int Data);

signals:
    /*!
     * \brief Sygnał emitowany po zakończeniu rozgrywki, gdy ilość punktów życia spadnie do 0
     * \param [in] points - liczba punktów uzyskanych przez gracza
     */
    void sig_win(int points);

private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    QGraphicsRectItem *rect;
    Settings settings_window;
    win win_window;
    usart usart_connection;
    QTimer * timer = new QTimer();
    QTimer * timer_shoot = new QTimer();
};
#endif // MAINWINDOW_H
