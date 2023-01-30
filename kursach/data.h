#ifndef DATA_H
#define DATA_H

#include <QWidget>
#include "result.h"
#include <QString>
namespace Ui {
class Data;
}

class Data : public QWidget
{
    Q_OBJECT

public:
  QString it;
    explicit Data(QWidget *parent = nullptr);

    ~Data();

signals:
    void firstWindow3();  // подключение формы

private slots:
    void on_pushButton_2_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::Data *ui;

    Result *res;

};

#endif // DATA_H
