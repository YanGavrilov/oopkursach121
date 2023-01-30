#ifndef GENETICS_H
#define GENETICS_H

#include <QWidget>

namespace Ui {
class Genetics;
}

class Genetics : public QWidget
{
    Q_OBJECT

public:
    explicit Genetics(QWidget *parent = nullptr);
    ~Genetics();

private:
    Ui::Genetics *ui;
};

#endif // GENETICS_H
