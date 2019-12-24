#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include<QSplashScreen>

void loadModules(QSplashScreen* psplash)
{
    QTime time;
    time.start();

    for(int i = 0; i < 100;)
    {
        if(time.elapsed()>40)
        {
            time.start();
            ++i;
        }

        psplash->showMessage("Запуск программы: "
                             + QString::number(i)+"%",
                             Qt::AlignCenter|Qt::AlignCenter,
                             Qt::black
                             );
        qApp->processEvents();
    }
}




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //Заставка
    QSplashScreen splash(QPixmap("C:\\Qt\\qq\\Travel_guide\\orig.jfif"));
    splash.show();
    loadModules(&splash);
    splash.finish(&w);

    //css файл
    QFile file(":/style.css");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());

    w.show();
    return a.exec();
}
