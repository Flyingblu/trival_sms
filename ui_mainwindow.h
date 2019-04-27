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
#include <QtWidgets/QComboBox>
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
    QLineEdit *stu_id_le;
    QLineEdit *age_le;
    QLabel *first_name_label_2;
    QLabel *first_name_label_3;
    QLabel *last_name_label_2;
    QComboBox *gender_cb;
    QLabel *first_name_warning;
    QLabel *last_name_warning;
    QLabel *stu_id_warning;
    QLabel *age_warning;
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
        add_pb->setGeometry(QRect(660, 170, 113, 32));
        del_pb = new QPushButton(centralWidget);
        del_pb->setObjectName(QString::fromUtf8("del_pb"));
        del_pb->setGeometry(QRect(660, 200, 113, 32));
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
        stu_id_le = new QLineEdit(centralWidget);
        stu_id_le->setObjectName(QString::fromUtf8("stu_id_le"));
        stu_id_le->setGeometry(QRect(460, 30, 171, 31));
        age_le = new QLineEdit(centralWidget);
        age_le->setObjectName(QString::fromUtf8("age_le"));
        age_le->setGeometry(QRect(460, 100, 171, 31));
        first_name_label_2 = new QLabel(centralWidget);
        first_name_label_2->setObjectName(QString::fromUtf8("first_name_label_2"));
        first_name_label_2->setGeometry(QRect(460, 10, 81, 16));
        first_name_label_3 = new QLabel(centralWidget);
        first_name_label_3->setObjectName(QString::fromUtf8("first_name_label_3"));
        first_name_label_3->setGeometry(QRect(460, 80, 81, 16));
        last_name_label_2 = new QLabel(centralWidget);
        last_name_label_2->setObjectName(QString::fromUtf8("last_name_label_2"));
        last_name_label_2->setGeometry(QRect(210, 150, 121, 16));
        gender_cb = new QComboBox(centralWidget);
        gender_cb->setObjectName(QString::fromUtf8("gender_cb"));
        gender_cb->setGeometry(QRect(210, 170, 171, 31));
        first_name_warning = new QLabel(centralWidget);
        first_name_warning->setObjectName(QString::fromUtf8("first_name_warning"));
        first_name_warning->setGeometry(QRect(210, 60, 171, 16));
        first_name_warning->setMouseTracking(false);
        last_name_warning = new QLabel(centralWidget);
        last_name_warning->setObjectName(QString::fromUtf8("last_name_warning"));
        last_name_warning->setGeometry(QRect(210, 130, 171, 16));
        last_name_warning->setMouseTracking(false);
        stu_id_warning = new QLabel(centralWidget);
        stu_id_warning->setObjectName(QString::fromUtf8("stu_id_warning"));
        stu_id_warning->setGeometry(QRect(460, 60, 171, 16));
        stu_id_warning->setMouseTracking(false);
        age_warning = new QLabel(centralWidget);
        age_warning->setObjectName(QString::fromUtf8("age_warning"));
        age_warning->setGeometry(QRect(460, 130, 171, 16));
        age_warning->setMouseTracking(false);
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
        first_name_label_2->setText(QApplication::translate("MainWindow", "Student ID", nullptr));
        first_name_label_3->setText(QApplication::translate("MainWindow", "Age", nullptr));
        last_name_label_2->setText(QApplication::translate("MainWindow", "Gender", nullptr));
        first_name_warning->setText(QString());
        last_name_warning->setText(QString());
        stu_id_warning->setText(QString());
        age_warning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
