#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "first_sub_menu_widget.h"
#include "second_sub_menu_widget.h"
#include "third_sub_menu_widget.h"
#include "fourth_sub_menu_widget.h"
#include "fifth_sub_menu_widget.h"

#include "second_main_menu_widget.h"
#include "third_main_menu_widget.h"
#include "fourth_main_menu_widget.h"
#include "fifth_main_menu_widget.h"

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
    //Указатели на виджеты подменю первого пункта главного меню
    First_sub_menu_widget *first_sub;
    second_sub_menu_widget *second_sub;
    Third_sub_menu_widget *third_sub;
    Fourth_sub_menu_widget *fourth_sub;
    Fifth_sub_menu_widget *fifth_sub;

    //Указатель на второй пункт главного меню
    Second_main_menu_widget *second_main;

    //Указатель на третий пункт главного меню
    Third_main_menu_widget *third_main;

    //Указатель на четвёртый пункт главного меню
    Fourth_main_menu_widget *fourth_main;

    //Указатель на пятый пункт главного меню
    Fifth_main_menu_widget *fifth_main;
};

#endif // MAINWINDOW_H

