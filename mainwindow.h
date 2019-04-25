#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_listWidget_currentRowChanged(int currentRow);

    void on_add_pb_clicked();

    void on_del_pb_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Data::Student> students;
};

#endif // MAINWINDOW_H
