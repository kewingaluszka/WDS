#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <player.h>
#include "virus.h"
#include <QTimer>
#include <QObject>
#include<QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QStackedWidget>
#include <qcustomplot.h>
#include "settings.h"
#include "usart.h"
#include <QGraphicsPixmapItem>
#include "syringe.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /* MAIN GAME SCENE */
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui -> game_window-> setScene(scene);

    setWindowTitle(tr("STRASZNA EPIDEMIA v1.0"));

    ui->plot_x->addGraph(0);
    ui->plot_y->addGraph(0);
    ui->plot_z->addGraph(0);


    connect(&settings_window,SIGNAL(sig_usart_connect(QString)),&usart_connection,SLOT(slt_usart_connect(QString)));       //connection usart connect signal and slot
    connect(&settings_window,SIGNAL(sig_usart_disconnect()),&usart_connection,SLOT(slt_usart_disconnect()));               //connection usart disconnect signal and slot
    connect(&usart_connection,SIGNAL(sig_addToLogs(QString)),&settings_window,SLOT(slt_addToLogs(QString)));               //connection add to logs signal and slot (term)
    connect(&usart_connection,SIGNAL(sig_writeStatus(QString)),this,SLOT(slt_writeStatus(QString)));                       //connection add to logs signal and slot (term)
    connect(&usart_connection,SIGNAL(sig_clearStatus()),this,SLOT(slt_clearStatus()));                                     //connection add to logs signal and slot (term)
    connect(&usart_connection,SIGNAL(plotData(QList<float>)),this,SLOT(makePlot(QList<float>)));                           //connection plotData and makePlot signal and slot
    connect(&syringe,SIGNAL(sig_point()),this,SLOT(on_points_LCD_overflow()));


    player * player1 = new player();                                   //create player
    player1->setPos(230,300);                                          //setting position
    player1 -> setFlag(QGraphicsItem :: ItemIsFocusable);
    player1 -> setFocus();                                             //player focusable
    scene ->addItem(player1);                                          //add player to scene


    QGraphicsView *view = new QGraphicsView(scene);                    //create view

   // view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );     //off scroll bars
   // view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );



    ui->status_window->clear();                                         //status_window initialization
    slt_writeStatus("Nie polaczono");



    view ->setFixedSize(800,600);                                       //view and scene parameters
    scene->setSceneRect(0,0,569,419);





    QTimer * timer = new QTimer();                                      //spawning enemies
    QObject::connect(timer,SIGNAL(timeout()),player1,SLOT(spawn()));
    timer->start(2000);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_b_settings_clicked()
{
    /* settings_window = new Settings(this);           //create object
    settings_window -> show();*/
    settings_window.show();

}

void MainWindow::slt_writeStatus(QString message)
{
    ui->status_window->append(message);
    // statusBar()->showMessage(message);
}

void MainWindow::slt_clearStatus()
{
    ui->status_window->clear();
    // qDebug() <<"Okno statusu wyczyszczone" ;
}

void MainWindow::makePlot(QList<float> acc_dat)
{

    float tmp_x,tmp_y,tmp_z =0;

    tmp_x = acc_dat.at(0);
    tmp_y = acc_dat.at(1);
    tmp_z = acc_dat.at(2);



    ui->plot_x->graph(0)->addData(t_plot,tmp_x);
    ui->plot_x->xAxis->setRange(t_plot-10, t_plot);
    ui->plot_x->yAxis->setRange(-2,2);
    ui->plot_x->replot();


    ui->plot_y->graph(0)->addData(t_plot,tmp_y);
    ui->plot_y->xAxis->setRange(t_plot-10, t_plot);
    ui->plot_y->yAxis->setRange(-2,2);
    ui->plot_y->replot();

    ui->plot_z->graph(0)->addData(t_plot,tmp_z);
    ui->plot_z->xAxis->setRange(t_plot-10, t_plot);
    ui->plot_z->yAxis->setRange(-2,2);
    ui->plot_z->replot();


    t_plot=t_plot+0.1;
    qDebug() <<"plot completed" ;
}

void MainWindow::on_points_LCD_overflow()
{
    points++;
    ui->life_LCD->display(points);
    qDebug() <<"POINT+1" ;

}
