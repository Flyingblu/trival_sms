#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"
#include "ui_mainwindow.h"

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

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_actionSave_triggered();

    void on_actionSave_on_edit_triggered(bool checked);

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    std::vector<Data::Student> students;
    std::string data_path = "/Users/flyingblu/data.json";
    bool save_on_modify = true;
    void clear_formdata();
    void json_desrialize(string path);
    void json_serialize(string path);
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
