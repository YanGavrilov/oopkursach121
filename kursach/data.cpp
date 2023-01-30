#include <QString>
#include "data.h"
#include <QTextStream>
#include "ui_data.h"
#include <QPixmap>
#include <QFile>
#include "mainwindow.h"
#include "result.h"
#include <QtCore>

class bio {
    private:
    QString chr1_1;
    QString dra1_1;
    QString hethom1_1;
    QString chr2_1;
    QString dra2_1;
    QString hethom2_1;
    QString pa="";//  класс с данными
    public:
    QString chr1;
    QString dra1;
    QString hethom1;
    QString chr2;
    QString dra2;
    QString hethom2;
    void set(QString i1,QString i2,QString i3,QString i4,QString i5,QString i6)
    {
        chr1_1=i1;
        dra1_1=i2;
        hethom1_1=i3;
        chr2_1=i4;
        dra2_1=i5;
        hethom2_1=i6;
    }
    void get()
    {
        chr1=chr1_1;
        dra1=dra1_1;
        hethom1=hethom1_1;
        chr2=chr2_1;
        dra2=dra2_1;
        hethom2=hethom2_1;
    }
    void save(QString s){
        pa+=s;
    }
    QString getpa()
    {
        return pa;
    }
};
class table { //таблица сводности аллелей
public:
    QString al;
    void save5(QString s){
        al+=s;
    }

    void Table_Fill_FirstCol_Row(table all[5][5], bio p1, bio p2)
    {
           all[0][0].save5("/");
           all[0][1].save5(p2.getpa()[0]);
           all[0][1].save5(p2.getpa()[2]);
           all[0][2].save5(p2.getpa()[0]);
           all[0][2].save5(p2.getpa()[3]);
           all[0][3].save5(p2.getpa()[1]);
           all[0][3].save5(p2.getpa()[2]);
           all[0][4].save5(p2.getpa()[1]);
           all[0][4].save5(p2.getpa()[3]);
           all[1][0].save5(p1.getpa()[0]);
           all[1][0].save5(p1.getpa()[2]);
           all[2][0].save5(p1.getpa()[0]);
           all[2][0].save5(p1.getpa()[3]);
           all[3][0].save5(p1.getpa()[1]);
           all[3][0].save5(p1.getpa()[2]);
           all[4][0].save5(p1.getpa()[1]);
           all[4][0].save5(p1.getpa()[3]);
    }
    void Table_Fill_Main(table all[5][5], bio p1, bio p2)
    {
        for (int i = 1; i < 5; i++)
             for (int j = 1; j < 5; j++)
             {
                 all[i][j].save5(all[i][0].al[0]);
                 all[i][j].save5(all[0][j].al[0]);
                 all[i][j].save5(all[i][0].al[1]);
                 all[i][j].save5(all[0][j].al[1]);
                 if (all[i][j].al[0] == 'a' && all[i][j].al[1] == 'A')
                     std::swap(all[i][j].al[0], all[i][j].al[1]);
                 if (all[i][j].al[2] == 'b' && all[i][j].al[3] == 'B')
                     std::swap(all[i][j].al[2], all[i][j].al[3]);
             }
    }
};

class pov { //класс для получения уникального потомства
public:
    QString n;
    double k;
    void save3(QString s){
        n=s;
    }
    void save4(double s){
        k=s;
    }
    int Kid_Find_Unique_N(table all[5][5], pov kid[16])
    {
        for (int i = 0; i < 16; i++)
        {
            kid[i].n = '0';
            kid[i].k = 0;
        }
            int s = 0;
            int l = 0;
        for (int i = 1; i < 5; i++)
        {
            for (int j = 1; j < 5; j++)
            {
                QString p = all[i][j].al;
                    for (int k = 0; k < 16; k++)
                         if (kid[k].n == p)
                            s++;
                                if (s == 0)
                                {
                                    kid[l].n = p;
                                    l++;
                                }
                s = 0;
            }
        }
    return l;
    }
    void Kid_Find_Sum_Unique(table all[5][5], pov nma[9], pov kid[16], int l)
    {
        for (int i = 0; i < l; i++)
            for (int j = 0; j < 9; j++)
                if (kid[i].n == nma[j].n)
                 nma[j].k = 1;
            for (int i = 0; i < l; i++)
                for (int k = 1; k < 5; k++)
                    for (int q = 1; q < 5; q++)
                        if (kid[i].n == all[k][q].al)
                            kid[i].k++;
    }
};
class MyException //класс исключений
{
private:
    QString exp;


public:
    MyException(int q){
        switch (q)
            {
            case 1:
                exp="If 2 charapter ate different they can not be both dominant or both reccessive";
                break;
            case 2:
                exp="Reccessive can be only Heterozygous allele allele.Error in 1 chr 1 parent";
                break;
            case 3:
                exp="Reccessive can be only Heterozygous allele allele.Error in 2 chr 1 parent";
                break;
            case 4:
                exp="Reccessive can be only Heterozygous allele allele.Error in 1 chr 2 parent";
                break;
            case 5:
                exp="Reccessive can be only Heterozygous allele allele.Error in 2 chr 2 parent";
                break;
            case 6:
                exp="Could not open the file";
                break;
            }

    }
    QString get()
    {
        return exp;
    }
};
Data::Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Data)
{
    ui->setupUi(this);
    res= new Result();   // подключение окна с результатами
    connect( res, &Result::firstWindow4, this, &Data::show);
    QPixmap pix1(":/img/arrow2.png");
    int w1= ui->label_13->width();
    int h1= ui->label_13->height();
    QTextStream sstream("MyXML.xml"); //получение информации из xml файла
    QString dom1 = "";
    QString rec1 = "";
    QString hom1 = "";
    QString het1 = "";
    while(!sstream.atEnd())
    {
        QString line=sstream.readLine();
        if(line.contains("Dominant")!=-1)
        dom1 = "Dominant";
        if(line.contains("Reccessive")!=-1)
        rec1 = "Reccessive";
        if(line.contains("Homozigot")!=-1)
        hom1 = "Homozygous allele";
        if(line.contains("Heterozigot")!=-1)
        het1 = "Heterozygous allele";
    }
     if(hom1=="" || het1=="" || rec1=="" || dom1=="")
     qDebug()<<"XML file data is broken!";
     ui->label_13->setPixmap(pix1.scaled(w1,h1, Qt::KeepAspectRatio));
     ui->comboBox->addItem(dom1);  // добавление в комбобоксы варианты для выбора
     ui->comboBox->addItem(rec1);
     ui->comboBox_3->addItem(dom1);
     ui->comboBox_3->addItem(rec1);
     ui->comboBox_5->addItem(dom1);
     ui->comboBox_5->addItem(rec1);
     ui->comboBox_7->addItem(dom1);
     ui->comboBox_7->addItem(rec1);
     ui->comboBox_2->addItem(het1);
     ui->comboBox_2->addItem(hom1);
     ui->comboBox_4->addItem(het1);
     ui->comboBox_4->addItem(hom1);
     ui->comboBox_6->addItem(het1);
     ui->comboBox_6->addItem(hom1);
     ui->comboBox_8->addItem(het1);
     ui->comboBox_8->addItem(hom1);
}

Data::~Data()
{
    delete ui;
}

void Data::on_pushButton_2_clicked()
{

    this->close();  // возможность вернуться назад (стрелочка)
    emit firstWindow3();
}


void Data::on_comboBox_currentTextChanged(const QString &arg1)
{

}


void Data::on_pushButton_clicked()
{


    int n = 0;
    bio p1, p2; //информация о первом и втором родителе
    QString path;
    QString i1;
    QString i2;
    QString i3;
    QString i4;
    QString i5;
    QString i6;
    QString i12;
    QString i22;
    QString i32;
    QString i42;
    QString i52;
    QString i62;
    i1=ui->textEdit->toPlainText().trimmed();
    i2=ui->comboBox->currentText();
    i3=ui->comboBox_2->currentText();
    i4=ui->textEdit_2->toPlainText().trimmed();
    i5=ui->comboBox_3->currentText();
    i6=ui->comboBox_4->currentText();
    p1.set(i1,i2,i3,i4,i5,i6);
    i12=ui->textEdit_3->toPlainText().trimmed();
    i22=ui->comboBox_5->currentText();
    i32=ui->comboBox_6->currentText();
    i42=ui->textEdit_4->toPlainText().trimmed();
    i52=ui->comboBox_7->currentText();
    i62=ui->comboBox_8->currentText();
    p2.set(i12,i22,i32,i42,i52,i62);
    p1.get();
    p2.get();
    path=ui->textEdit_6->toPlainText().trimmed();
    QTextStream stream("MyXML.xml");
                   QString dom = "";
                   QString rec = "";
                   QString hom = "";
                   QString het = "";
                   while(!stream.atEnd())
                   {
                       QString line=stream.readLine();
                       if(line.contains("Dominant")!=-1)
                       dom = "Dominant";
                       if(line.contains("Reccessive")!=-1)
                       rec = "Reccessive";
                       if(line.contains("Homozigot")!=-1)
                       hom = "Homozygous allele";
                       if(line.contains("Heterozigot")!=-1)
                       het = "Heterozygous allele";
                   }

                   if (rec == p1.dra1){
                       p1.hethom1 = hom;

                   }
                   if (rec == p1.dra2){
                       p1.hethom2 = hom;

                   }
                   if (rec == p2.dra1){
                       p2.hethom1 = hom;

                   }
                   if (rec == p2.dra2){
                       p2.hethom2 = hom;

                   }
                   if (dom == p1.dra1 && rec==p1.dra2)
                   {
                       if (hom==p1.hethom1){
                           p1.save("AA");

                       }
                       if (het==p1.hethom1)
                           p1.save("Aa");
                       p1.save("bb");
                   }
                   if (dom==p1.dra1  && dom==p1.dra2)
                   {
                       if (hom==p1.hethom1){
                           p1.save("AA");

                       }
                       if (het==p1.hethom1)
                          p1.save("Aa");
                       if (het==p1.hethom2)
                           p1.save("Bb");
                       if (hom==p1.hethom2)
                           p1.save("BB");
                   }
                   if (rec==p1.dra1 && rec==p1.dra2)
                   {
                       p1.save("aa");
                       p1.save("bb");
                   }
                   if (rec==p1.dra1 && dom==p1.dra2)
                   {
                       p1.save("aa");
                       if (hom==p1.hethom2)
                           p1.save("BB");
                       if (het==p1.hethom2)
                           p1.save("Bb");
                   }
                   if (dom==p2.dra1 && rec==p2.dra2)
                   {
                       if (hom==p2.hethom1)
                       {
                           p2.save("AA");
                       }
                       if (het==p2.hethom1)
                       {
                           p2.save("Aa");
                       }
                       p2.save("bb");
                   }
                   if (dom==p2.dra1 && dom==p2.dra2)
                   {
                       if (hom==p2.hethom1)
                   {
                           p2.save("AA");
                       }
                       if (het==p2.hethom1)
                           p2.save("Aa");
                       if (het==p2.hethom2)
                           p2.save("Bb");
                       if (hom==p2.hethom2)
                           p2.save("BB");
                   }
                   if (rec==p2.dra1 && rec==p2.dra2)
                   {
                       p2.save("aa");
                       p2.save("bb");
                   }
                   if (rec==p2.dra1 && dom==p2.dra2)
                   {
                       p2.save("aa");
                       if (hom==p2.hethom2)
                           p2.save("BB");
                       if (het==p2.hethom2)
                           p2.save("Bb");
                   }
  // текст эдит - выводится текст, сет эдит- выводит текст, в скобках текст, который выводится
if(p1.dra1==rec && p1.hethom1==het ){
    throw 2;
}
if(p1.dra2==rec && p1.hethom2==het ){
    throw 3;
}
if(p2.dra1==rec && p2.hethom1==het ){
     throw 4 ;
}
if(p2.dra2==rec && p2.hethom2==het ){
    throw 5;
}
try{
if(p1.chr2==p2.chr2 ){
       if(p1.dra2!=p2.dra2){
           throw 1;
       }
   }
   if(p1.chr1==p2.chr1){
   if(p1.dra1!=p2.dra1){
        throw 1;
   }
   }
   if(p1.dra1==p2.dra1 && p1.chr1!=p2.chr1){
        throw 1;
   }
              table all[5][5];
                   for (int i = 0; i < 5; i++){
                       for (int j = 0; j < 5; j++){
                           all[i][j].al = "";
                       }
                   }
                   if(p1.chr1!=p2.chr1 ){
                        if(p1.dra1==p2.dra1){
                               throw 1;
                           }
                       }
                   if(p1.chr2!=p2.chr2 ){
                        if(p1.dra2==p2.dra2){
                            throw 1;
                           }
                       }
                   if(p1.chr2!=p2.chr2 ){
                        if(p1.dra2==p2.dra2){
                               throw 1;
                           }
                       }
                   pov nma[9];
                   nma[0].save3("AABB");
                   nma[1].save3("AABb");
                   nma[2].save3("AAbb");
                   nma[3].save3("AaBB");
                   nma[4].save3("AaBb");
                   nma[5].save3("Aabb");
                   nma[6].save3("aaBB");
                   nma[7].save3("aaBb");
                   nma[8].save3("aabb");
                   nma[0].save4(0);
                   nma[1].save4(0);
                   nma[2].save4(0);
                   nma[3].save4(0);
                   nma[4].save4(0);
                   nma[5].save4(0);
                   nma[6].save4(0);
                   nma[7].save4(0);
                   nma[8].save4(0);
                   for(int i=0;i<9;i++){
                       if(nma[i].n==p1.getpa() || nma[i].n==p2.getpa())
                       nma[i].save4(1);
                   }
                  // путь к файлу
                    QFile mfile(path);  //  открытие файла  (кьюфайл - библиотека для открытия файла)
                    QTextStream ofs(&mfile);  // указатель на файл (название) (кьютекст стрим - библиотека для считывания из файла и запись в файл)
                    if(!mfile.open(QFile :: WriteOnly)){  // WriteOnly - открытие файла только для записи
                        throw 6;
                         // вывод в консоль
                        return;
                    }
                    else{
                             n++;
                             ofs <<"Number" << n<<'\n';
                             ofs << "Parents:  " << p1.getpa() << "," << p2.getpa()<<'\n';
                             ofs <<'\n';
                             table tab; // створення змінної класу для звертання до нього й виклику функцій
                                                        tab.Table_Fill_FirstCol_Row(all,p1,p2); // виклик методу класу для заповнення першого рядка та стовпця решітки Пеннета
                                                        tab.Table_Fill_Main(all,p1,p2); // заповнення всієї решітки Пеннета, отримання алелей нащадків

                                                          for (int i = 0; i < 5; i++)
                                                          {
                                                              for (int j = 0; j < 5; j++)
                                                              {
                                                                  if (i == 0 && all[i][j].al[0] == 'a' && all[i][j].al[1] == 'B')
                                                                      ofs << all[i][j].al[1] << all[i][j].al[0] << ","<<"       ";
                                                                  else if (j == 0 && all[i][j].al[0] == 'a' && all[i][j].al[1] == 'B')
                                                                      ofs << all[i][j].al[1] << all[i][j].al[0] << ","<<"       ";
                                                                  else
                                                                      ofs << all[i][j].al << ","<<"       ";
                                                              }
                                                              ofs << "\n";
                                                          }
                                                         pov kid[16]; // змінна класу для заповнення таблиці відповідності (назва унікальних алелей, їхня кількість)
                                                         ofs.flush();
                                                         pov pow; // створення змінної класу для звертання до нього й виклику функцій
                                                         int l = pow.Kid_Find_Unique_N(all,kid); // виклик функції класу, ініціалізація змінної
                                                         //за рахунок отримання кількості унікальних алелей нащадків
                                                         kid[l];
                                                         pow.Kid_Find_Sum_Unique(all,nma,kid,l);
                             ofs << '\n';
                             ofs << "Alleles: ";
                             ofs.flush();
                             for (int i = 0; i < l; i++)
                             {
                                 if (kid[i].n[0] == 'a' && kid[i].n[2] == 'B')
                                     ofs << kid[i].n[2] << kid[i].n[3] << kid[i].n[0] << kid[i].n[1] << ",";
                                 else
                                     ofs << kid[i].n << ",";
                             }
                             ofs << '\n';
                             ofs << "Ratio: ";
                             for (int i = 0; i < l; i++)
                                 ofs << kid[i].k << ",";
                             ofs << '\n';
                             ofs<<'\n';
                             int j = 1;
                                 for (int i = 0; i < l; i++)
                                 {
                                     double ch = kid[i].k / 16;
                                     ch *= 100;
                                     ofs << "Children: ";
                                     if (kid[i].n[0] == 'A' && kid[i].n[1] == 'A')
                                     {
                                         if (dom==p1.dra1)
                                             ofs << p1.chr1 << ",";
                                         else if (dom==p2.dra1)
                                             ofs << p2.chr1 << ",";
                                     }
                                     if (kid[i].n[0] == 'A' && kid[i].n[1] == 'a')
                                     {
                                         if (dom==p1.dra1)
                                             ofs << p1.chr1 << ",";
                                         else if (dom==p2.dra1)
                                             ofs << p2.chr1 << ",";
                                     }
                                     if (kid[i].n[0] == 'a' && kid[i].n[1] == 'a')
                                     {
                                         if (rec==p1.dra1)
                                             ofs << p1.chr1 << ",";
                                         else if (rec==p2.dra1)
                                             ofs << p2.chr1 << ",";
                                         else
                                             ofs << p1.chr1 << ",";
                                     }
                                     if (kid[i].n[2] == 'B' && kid[i].n[3] == 'B')
                                     {
                                         if (dom==p1.dra2)
                                             ofs << p1.chr2 << "," << ch << "%";
                                         else if (dom==p2.dra2)
                                             ofs << p2.chr2 << "," << ch << "%";
                                     }
                                     if (kid[i].n[2] == 'B' && kid[i].n[3] == 'b')
                                     {if (dom==p1.dra2)
                                             ofs << p1.chr2 << "," << ch << "%";
                                         else if (dom==p2.dra2)
                                             ofs << p2.chr2 << "," << ch << "%";
                                     }
                                     if (kid[i].n[2] == 'b' && kid[i].n[3] == 'b')
                                     {
                                         if (rec==p1.dra2)
                                             ofs << p1.chr2 << "," << ch << "%";
                                         else if (rec==p2.dra2)
                                             ofs << p2.chr2 << "," << ch << "%";
                                         else
                                             ofs << p1.chr2 << "," << ch << "%";
                                     }
                                     ofs << '\n';
                                     j++;
                                 }
                                       mfile.close();
                                       res->show();   //открытие окна с результатами
                                       this->close();
                                }
}
   catch(int q){
      MyException exp(q);
       ui->textEdit_5->setText(exp.get());
   }
}
