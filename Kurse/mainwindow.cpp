#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Выпадающий список для первой кнопки
    QMenu*       pm = new QMenu(ui->pushButton);
    pm->addAction("Готовимся к путешествию", this, SLOT(first_sub_menu()));
    pm->addAction("Путешествуем с детьми", this, SLOT(second_sub_menu()));
    pm->addAction("Путешествуем с животными", this, SLOT(third_sub_menu()));
    pm->addAction("В аэропорте и самолёте", this, SLOT(fourth_sub_menu()));
    pm->addAction("Безопастность", this, SLOT(fifth_sub_menu()));
    ui->pushButton->setMenu(pm);



    //Добавление первого виджета для подменю
    first_sub = new First_sub_menu_widget(this);
    ui->stackedWidget->addWidget(first_sub);

    //Добавление второго виджета для подменю
    second_sub = new second_sub_menu_widget(this);
    ui->stackedWidget->addWidget(second_sub);

    //Добавление третьего виджета для подменю
    third_sub = new Third_sub_menu_widget(this);
    ui->stackedWidget->addWidget(third_sub);

    //Добавление четвёртого виджета для подменю
    fourth_sub = new Fourth_sub_menu_widget(this);
    ui->stackedWidget->addWidget(fourth_sub);

    //Добавление пятого виджета для подменю
    fifth_sub = new Fifth_sub_menu_widget(this);
    ui->stackedWidget->addWidget(fifth_sub);

    //Добавление второго пункта главного меню
    second_main = new Second_main_menu_widget(this);
    ui->stackedWidget->addWidget(second_main);

    //Добавление третьего пункта главного меню
    third_main = new Third_main_menu_widget(this);
    ui->stackedWidget->addWidget(third_main);

    //Добавление четвёртого пункта главного меню
    fourth_main = new Fourth_main_menu_widget(this);
    ui->stackedWidget->addWidget(fourth_main);

    //Добавление пятого пункта главного меню
    fifth_main = new Fifth_main_menu_widget(this);
    ui->stackedWidget->addWidget(fifth_main);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//Реализация нажатия на первое подменю
void MainWindow::first_sub_menu()
{
    //Переключение на виджет первого подменю
    ui->stackedWidget->setCurrentIndex(0);
}

//Реализация нажатия на второе подменю
void MainWindow::second_sub_menu()
{
    //Переключение на виджет второго подменю
    ui->stackedWidget->setCurrentIndex(1);
}

//Реализация нажатия на третье подменю
void MainWindow::third_sub_menu()
{
    //Переключение на виджет третьего подменю
    ui->stackedWidget->setCurrentIndex(2);
}

//Реализация нажатия на четвёртое подменю
void MainWindow::fourth_sub_menu()
{
    //Переключение на виджет четвёртого подменю
    ui->stackedWidget->setCurrentIndex(3);
}

//Реализация нажатия на четвёртое подменю
void MainWindow::fifth_sub_menu()
{
    //Переключение на виджет пятого подменю
    ui->stackedWidget->setCurrentIndex(4);
}

//Реализация нажатия на кнопку "Список с собой"
void MainWindow::on_pushButton_2_clicked()
{
    //Переключение на виджет второго пункта главного меню
    ui->stackedWidget->setCurrentIndex(5);
}

//Реализация нажатия на кнопку "Хочу посетить"
void MainWindow::on_pushButton_3_clicked()
{
    //Переключение на виджет третьего пункта главного меню
    ui->stackedWidget->setCurrentIndex(6);
}

//Реализация нажатия на кнопку "Посетил"
void MainWindow::on_pushButton_4_clicked()
{
    //Переключение на виджет четвёртого пункта главного меню
    ui->stackedWidget->setCurrentIndex(7);
}

//Реализация нажатия на кнопку "Настройки"
void MainWindow::on_pushButton_5_clicked()
{
    //Переключение на виджет четвёртого пункта главного меню
    ui->stackedWidget->setCurrentIndex(8);
}
