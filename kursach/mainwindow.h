#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <developers.h>
#include <qa.h>
#include "data.h"
#include "result.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void firstWindow();   // сигналы для соединения с другими формами
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui; // объявляем указатели на формы
    Developers *developers;
    QA *qa;
    Data *data;
    Result *res;

};
#endif // MAINWINDOW_H
