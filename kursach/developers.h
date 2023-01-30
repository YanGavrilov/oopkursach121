#ifndef DEVELOPERS_H
#define DEVELOPERS_H

#include <QWidget>

namespace Ui {
class Developers;
}

class Developers : public QWidget
{
    Q_OBJECT

public:
    explicit Developers(QWidget *parent = nullptr);   // базовое
    ~Developers();
signals:
    void firstWindow1();  // подключение формы
private slots:
    void on_pushButton_clicked();

private:
    Ui::Developers *ui;
};

#endif // DEVELOPERS_H
