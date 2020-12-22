/********************************************************************************
** Form generated from reading UI file 'mainmenuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENUWINDOW_H
#define UI_MAINMENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuWindow
{
public:
    QWidget *centralwidget;
    QComboBox *player1select;
    QComboBox *player2select;
    QPushButton *startButton;
    QLabel *p1display;
    QLabel *p2display;
    QLabel *titleDisplay;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMenuWindow)
    {
        if (MainMenuWindow->objectName().isEmpty())
            MainMenuWindow->setObjectName(QString::fromUtf8("MainMenuWindow"));
        MainMenuWindow->resize(1000, 1000);
        centralwidget = new QWidget(MainMenuWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        player1select = new QComboBox(centralwidget);
        player1select->setObjectName(QString::fromUtf8("player1select"));
        player1select->setGeometry(QRect(120, 240, 200, 60));
        player2select = new QComboBox(centralwidget);
        player2select->setObjectName(QString::fromUtf8("player2select"));
        player2select->setGeometry(QRect(430, 240, 200, 60));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(290, 340, 300, 50));
        p1display = new QLabel(centralwidget);
        p1display->setObjectName(QString::fromUtf8("p1display"));
        p1display->setGeometry(QRect(120, 160, 200, 60));
        p2display = new QLabel(centralwidget);
        p2display->setObjectName(QString::fromUtf8("p2display"));
        p2display->setGeometry(QRect(430, 160, 200, 60));
        titleDisplay = new QLabel(centralwidget);
        titleDisplay->setObjectName(QString::fromUtf8("titleDisplay"));
        titleDisplay->setGeometry(QRect(120, 40, 401, 71));
        titleDisplay->setTextFormat(Qt::AutoText);
        MainMenuWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMenuWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 22));
        MainMenuWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainMenuWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainMenuWindow->setStatusBar(statusbar);

        retranslateUi(MainMenuWindow);

        QMetaObject::connectSlotsByName(MainMenuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenuWindow)
    {
        MainMenuWindow->setWindowTitle(QCoreApplication::translate("MainMenuWindow", "MainWindow", nullptr));
        startButton->setText(QCoreApplication::translate("MainMenuWindow", "PushButton", nullptr));
        p1display->setText(QCoreApplication::translate("MainMenuWindow", "TextLabel", nullptr));
        p2display->setText(QCoreApplication::translate("MainMenuWindow", "TextLabel", nullptr));
        titleDisplay->setText(QCoreApplication::translate("MainMenuWindow", "Othello", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenuWindow: public Ui_MainMenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUWINDOW_H
