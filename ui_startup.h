/********************************************************************************
** Form generated from reading UI file 'startup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUP_H
#define UI_STARTUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Startup
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *choose_file_pb;
    QLineEdit *data_path_le;
    QLabel *warning_label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancel_pb;
    QPushButton *new_file_pb;
    QPushButton *ok_pb;

    void setupUi(QDialog *Startup)
    {
        if (Startup->objectName().isEmpty())
            Startup->setObjectName(QString::fromUtf8("Startup"));
        Startup->resize(516, 134);
        gridLayoutWidget = new QWidget(Startup);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 491, 51));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        choose_file_pb = new QPushButton(gridLayoutWidget);
        choose_file_pb->setObjectName(QString::fromUtf8("choose_file_pb"));

        gridLayout->addWidget(choose_file_pb, 0, 1, 1, 1);

        data_path_le = new QLineEdit(gridLayoutWidget);
        data_path_le->setObjectName(QString::fromUtf8("data_path_le"));

        gridLayout->addWidget(data_path_le, 0, 0, 1, 1);

        warning_label = new QLabel(gridLayoutWidget);
        warning_label->setObjectName(QString::fromUtf8("warning_label"));

        gridLayout->addWidget(warning_label, 1, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(Startup);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(220, 90, 281, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cancel_pb = new QPushButton(horizontalLayoutWidget);
        cancel_pb->setObjectName(QString::fromUtf8("cancel_pb"));

        horizontalLayout->addWidget(cancel_pb);

        new_file_pb = new QPushButton(horizontalLayoutWidget);
        new_file_pb->setObjectName(QString::fromUtf8("new_file_pb"));

        horizontalLayout->addWidget(new_file_pb);

        ok_pb = new QPushButton(horizontalLayoutWidget);
        ok_pb->setObjectName(QString::fromUtf8("ok_pb"));

        horizontalLayout->addWidget(ok_pb);


        retranslateUi(Startup);

        QMetaObject::connectSlotsByName(Startup);
    } // setupUi

    void retranslateUi(QDialog *Startup)
    {
        Startup->setWindowTitle(QApplication::translate("Startup", "Open data file", nullptr));
        choose_file_pb->setText(QApplication::translate("Startup", "Choose file...", nullptr));
        warning_label->setText(QString());
        cancel_pb->setText(QApplication::translate("Startup", "Cancel", nullptr));
        new_file_pb->setText(QApplication::translate("Startup", "New file", nullptr));
        ok_pb->setText(QApplication::translate("Startup", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Startup: public Ui_Startup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUP_H
