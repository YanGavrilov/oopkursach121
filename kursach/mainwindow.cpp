#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "developers.h"
#include "data.h"
#include "qa.h"
#include <QFile>
#include "result.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/DNA.png"); // вставка картинки
    int w= ui->label->width();  // ширина
    int h= ui->label->height();  // высота
    ui->label->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));  // подгоняем картинку под размер label
    developers= new Developers(); // инициализация указателя (подключение формы)
    connect( developers, &Developers::firstWindow1, this, &MainWindow::show); // явное подключение формы
    // переход дальше, ссылка на класс, текущий объект, отображение окна, которое мы вызвали
    qa = new QA();
    connect( qa, &QA::firstWindow2, this, &MainWindow::show);
    data = new Data();
    connect( data, &Data::firstWindow3, this, &MainWindow::show);
    res = new Result();
    connect( res, &Result::firstWindow4, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()     // кнопка для закрытия программы
{
this->close();
}

void MainWindow::on_pushButton_3_clicked()
{

    developers->show();   // кнопка открытия формы разработиков
    this->close();
}

void MainWindow::on_pushButton_4_clicked()
{
  qa->show();
  this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    data->show();
     this->close();
}

