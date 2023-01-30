#include "developers.h"
#include "ui_developers.h"
#include <QPixmap>
#include "mainwindow.h"
Developers::Developers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Developers)
{
    ui->setupUi(this);
    QPixmap pix1(":/img/glasses-10380.png");  // вставка картинок
    int w1= ui->label_12->width();
    int h1= ui->label_12->height();
    ui->label_12->setPixmap(pix1.scaled(w1,h1, Qt::KeepAspectRatio));
    QPixmap pix2(":/img/brush-25471.png");
    int w2= ui->label_13->width();
    int h2= ui->label_13->height();
    ui->label_13->setPixmap(pix2.scaled(w2,h2, Qt::KeepAspectRatio));
    QPixmap pix3(":/img/cross-12802.png");
    int w3= ui->label_14->width();
    int h3= ui->label_14->height();
    ui->label_14->setPixmap(pix3.scaled(w3,h3, Qt::KeepAspectRatio));
    QPixmap pix4(":/img/algorithm.png");
    int w4= ui->label_15->width();
    int h4= ui->label_15->height();
    ui->label_15->setPixmap(pix4.scaled(w4,h4, Qt::KeepAspectRatio));
    QPixmap pix5(":/img/mysql-26345.png");
    int w5= ui->label_16->width();
    int h5= ui->label_16->height();
    ui->label_16->setPixmap(pix5.scaled(w5,h5, Qt::KeepAspectRatio));
    QPixmap pix6(":/img/arrow2.png");
    int w6= ui->label_17->width();
    int h6= ui->label_17->height();
    ui->label_17->setPixmap(pix6.scaled(w6,h6, Qt::KeepAspectRatio));

}

Developers::~Developers()
{
    delete ui;
}

void Developers::on_pushButton_clicked()
{
   this->close();
    emit firstWindow1();   // открытие основного окна (открытие предыдущего окна)
}

