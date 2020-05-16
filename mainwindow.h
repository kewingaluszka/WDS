#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>
#include <QMainWindow>
#include <QGraphicsScene>
#include "settings.h"
#include "usart.h"
#include "player.h"
#include "syringe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    float t_plot = 0;
    int points = 0;
    int life =0;

private slots:
    void on_b_settings_clicked();
    void slt_writeStatus(QString message);
    void slt_clearStatus();
    void makePlot(QList<float> acc_dat);
    void on_points_LCD_overflow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    //  QGraphicsScene * scene_x;
    // QGraphicsScene * scene_y;
    // QGraphicsScene * scene_z;
    // QGraphicsWidget *plot;
   // QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rect;
   // QPolygonF *triangle;
    Settings settings_window;
    usart usart_connection;
    syringe syringe;

};
#endif // MAINWINDOW_H
