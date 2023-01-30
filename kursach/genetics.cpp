include "genetics.h"
#include "ui_genetics.h"

Genetics::Genetics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Genetics)
{
    ui->setupUi(this);
}

Genetics::~Genetics()
{
    delete ui;
}
