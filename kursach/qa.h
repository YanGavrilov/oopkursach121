#ifndef QA_H
#define QA_H

#include <QWidget>

namespace Ui {
class QA;
}

class QA : public QWidget
{
    Q_OBJECT

public:
    explicit QA(QWidget *parent = nullptr);
    ~QA();
signals:
    void firstWindow2();  // подключение формы
private slots:
    void on_pushButton_clicked();

private:
    Ui::QA *ui;
};

#endif // QA_H
