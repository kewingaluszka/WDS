#include "win.h"
#include "ui_win.h"

win::win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win)
{

    ui->setupUi(this);
    setWindowTitle(tr("Koniec gry!"));
}

win::~win()
{
    delete ui;
}

void win::on_close_win_clicked()
{
    this->close();
}

void win::slt_win(int points)
{
    ui->lcd_win->display(points);
}
