#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMenu>

#include <QMessageBox>

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



    //Добавление первого виджета для подменю 0
    first_sub = new First_sub_menu_widget(this);
    ui->stackedWidget->addWidget(first_sub);

    //Добавление второго виджета для подменю 1
    second_sub = new second_sub_menu_widget(this);
    ui->stackedWidget->addWidget(second_sub);

    //Добавление третьего виджета для подменю 2
    third_sub = new Third_sub_menu_widget(this);
    ui->stackedWidget->addWidget(third_sub);

    //Добавление четвёртого виджета для подменю 3
    fourth_sub = new Fourth_sub_menu_widget(this);
    ui->stackedWidget->addWidget(fourth_sub);

    //Добавление пятого виджета для подменю 4
    fifth_sub = new Fifth_sub_menu_widget(this);
    ui->stackedWidget->addWidget(fifth_sub);

    //Добавление второго пункта главного меню (с собой) 5
    second_main = new Second_main_menu_widget(this);
    ui->stackedWidget->addWidget(second_main);

    //Добавление третьего пункта главного меню 6
    third_main = new Third_main_menu_widget(this);
    ui->stackedWidget->addWidget(third_main);

    //Добавление четвёртого пункта главного меню 7
    fourth_main = new Fourth_main_menu_widget(this);
    ui->stackedWidget->addWidget(fourth_main);

    //Добавление пятого пункта главного меню 8
    fifth_main = new Fifth_main_menu_widget(this);
    ui->stackedWidget->addWidget(fifth_main);



    //Добавление окна изменения в виджет 9
    change_second_menu = new Change_second_main_menu_widget(this);
    ui->stackedWidget->addWidget(change_second_menu);

    //Добавление окна зменения в виджет 10
    change_third_menu = new Change_third_main_menu_widget(this);
    ui->stackedWidget->addWidget(change_third_menu);

    //Добавление окна зменения в виджет 11
    change_fourth_menu = new Change_fourth_main_menu_widget(this);
    ui->stackedWidget->addWidget(change_fourth_menu);



    //Привязываем слот к сигналу который поменяет окно в виджете + функция возвращения для второго меню
    connect(second_main, SIGNAL(change_press()), this, SLOT(second_change_widget()));
    connect(change_second_menu, SIGNAL(back_to_second_main_menu()), this, SLOT(back_to_second_main()));

    //Привязываем слот к сигналу который поменяет окно в виджете + функция возвращения для третьего меню
    connect(third_main, SIGNAL(change_press()), this, SLOT(third_change_widget()));
    connect(change_third_menu, SIGNAL(back_to_third_main_menu()), this, SLOT(back_to_third_main()));

    //Привязываем слот к сигналу который поменяет окно в виджете + функция возвращения для четвёртого меню
    connect(fourth_main, SIGNAL(change_press()), this, SLOT(fourth_change_widget()));
    connect(change_fourth_menu, SIGNAL(back_to_fourth_main_menu()), this, SLOT(back_to_fourth_main()));
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



//Функция смены окна для второго пункта меню + функция возвращения
void MainWindow::second_change_widget()
{
    ui->stackedWidget->setCurrentIndex(9);
}
void MainWindow::back_to_second_main()
{
    ui->stackedWidget->setCurrentIndex(5);
}

//Функция смены окна для третьего пункта меню + функция возвращения
void MainWindow::third_change_widget()
{
    ui->stackedWidget->setCurrentIndex(10);
}
void MainWindow::back_to_third_main()
{
    ui->stackedWidget->setCurrentIndex(6);
}

//Функция смены окна для четвёртого пункта меню + функция возвращения
void MainWindow::fourth_change_widget()
{
    ui->stackedWidget->setCurrentIndex(11);
}
void MainWindow::back_to_fourth_main()
{
    ui->stackedWidget->setCurrentIndex(7);
}
