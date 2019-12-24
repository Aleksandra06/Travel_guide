#ifndef FIFTH_MAIN_MENU_WIDGET_H
#define FIFTH_MAIN_MENU_WIDGET_H

#include <QWidget>
#include <qwidget.h>
#include <QPushButton>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace Ui {
class Fifth_main_menu_widget;
}

class Fifth_main_menu_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Fifth_main_menu_widget(QWidget *parent = 0);
    ~Fifth_main_menu_widget();

private:
    Ui::Fifth_main_menu_widget *ui;
private slots:
void onAnchorClicked(const QUrl &link);
void on_pushButton_clicked();
};


class HelpBrowser : public QWidget
{
    Q_OBJECT
public:
    HelpBrowser(const QString& strPath,
                const QString& strFileName,
                       QWidget* pwgt = 0
                ): QWidget(pwgt)
    {
        QPushButton* pcmdBack = new QPushButton("<<");
        QPushButton* pcmdHome = new QPushButton("Home");
        QPushButton* pcmdForward = new QPushButton(">>");
        QTextBrowser* ptxtBrowser = new QTextBrowser;

        connect(pcmdBack, SIGNAL(clicked(bool)), ptxtBrowser, SLOT(backward()));
        connect(pcmdHome, SIGNAL(clicked(bool)), ptxtBrowser, SLOT(home()));
        connect(pcmdForward, SIGNAL(clicked(bool)),ptxtBrowser, SLOT(forward()));
        connect(ptxtBrowser, SIGNAL(backwardAvailable(bool)), pcmdBack, SLOT(setEnabled(bool)));
        connect(ptxtBrowser, SIGNAL(forwardAvailable(bool)), pcmdForward, SLOT(setEnabled(bool)));

        ptxtBrowser->setSearchPaths(QStringList() << strPath);
        ptxtBrowser->setSource(QString(strFileName));


        QVBoxLayout* pvbxLayout = new QVBoxLayout;
        QHBoxLayout* phbxLayout = new QHBoxLayout;
        phbxLayout->addWidget(pcmdBack);
        phbxLayout->addWidget(pcmdHome);
        phbxLayout->addWidget(pcmdForward);
        pvbxLayout->addLayout(phbxLayout);
        pvbxLayout->addWidget(ptxtBrowser);
        setLayout(pvbxLayout);
    }
};


#endif // FIFTH_MAIN_MENU_WIDGET_H
