/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QPushButton *add_pb;
    QPushButton *del_pb;
    QLabel *first_name_label;
    QLabel *last_name_label;
    QLineEdit *first_name_le;
    QLineEdit *last_name_le;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(780, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 181, 241));
        add_pb = new QPushButton(centralWidget);
        add_pb->setObjectName(QString::fromUtf8("add_pb"));
        add_pb->setGeometry(QRect(240, 160, 113, 32));
        del_pb = new QPushButton(centralWidget);
        del_pb->setObjectName(QString::fromUtf8("del_pb"));
        del_pb->setGeometry(QRect(240, 190, 113, 32));
        first_name_label = new QLabel(centralWidget);
        first_name_label->setObjectName(QString::fromUtf8("first_name_label"));
        first_name_label->setGeometry(QRect(210, 10, 81, 16));
        last_name_label = new QLabel(centralWidget);
        last_name_label->setObjectName(QString::fromUtf8("last_name_label"));
        last_name_label->setGeometry(QRect(210, 80, 121, 16));
        first_name_le = new QLineEdit(centralWidget);
        first_name_le->setObjectName(QString::fromUtf8("first_name_le"));
        first_name_le->setGeometry(QRect(210, 30, 171, 31));
        last_name_le = new QLineEdit(centralWidget);
        last_name_le->setObjectName(QString::fromUtf8("last_name_le"));
        last_name_le->setGeometry(QRect(210, 100, 171, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 780, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        add_pb->setText(QApplication::translate("MainWindow", "Add", nullptr));
        del_pb->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        first_name_label->setText(QApplication::translate("MainWindow", "First Name", nullptr));
        last_name_label->setText(QApplication::translate("MainWindow", "Last Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
