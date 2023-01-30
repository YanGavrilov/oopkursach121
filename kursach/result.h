#ifndef RESULT_H
#define RESULT_H

#include <QWidget>

#include "ui_data.h"
namespace Ui {
class Result;
}

class Result : public QWidget
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = nullptr);
    ~Result();

signals:
    void firstWindow4();  // подключение формы
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Result *ui;


};

#endif // RESULT_H
