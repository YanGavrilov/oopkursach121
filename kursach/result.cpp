#include "result.h"
#include "ui_result.h"
#include "mainwindow.h"
#include "data.h"
#include <QPixmap>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>


Result::Result(QWidget *parent) :

    QWidget(parent),

    ui(new Ui::Result)

{
    ui->setupUi(this);

    QPixmap pix(":/img/clipart1619109.png");
    int w= ui->label->width();
    int h= ui->label->height();
    ui->label->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
    ui->label_2->setText("The program has successfully completed\n its work! Look for the result in the\n file you specified.");
}

Result::~Result()
{
    delete ui;

}

void Result::on_pushButton_clicked()
{

}

void Result::on_pushButton_3_clicked()
{
    this->close();
    emit firstWindow4();
}



void Result::on_pushButton_2_clicked()
{
    this->close();

  }

