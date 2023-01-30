#include "qa.h"
#include "ui_qa.h"
#include <QPixmap>

QA::QA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QA)
{
    ui->setupUi(this);
    QPixmap pix1(":/img/questionMark.png");
    int w1= ui->label->width();
    int h1= ui->label->height();
    ui->label->setPixmap(pix1.scaled(w1,h1, Qt::KeepAspectRatio));
    QPixmap pix2(":/img/arrow2.png");
    int w2= ui->label_2->width();
    int h2= ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(w2,h2, Qt::KeepAspectRatio));

}

QA::~QA()
{
    delete ui;
}

void QA::on_pushButton_clicked()  // закрываем окно, возвращаемся к главному
{
    this->close();
    emit firstWindow2();
}

