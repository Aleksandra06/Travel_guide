#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <iostream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //Слоты для подменю "Необходимая информация"
    void first_sub_menu();
    void second_sub_menu();
    void third_sub_menu();
    void fourth_sub_menu();
    void fifth_sub_menu();

    //Слоты для кнопок
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;

public:
    //Widget
     QStackedWidget * stackedWidget = new QStackedWidget ;
};


#endif // MAINWINDOW_H

