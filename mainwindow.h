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
    explicit MainWindow(std::string data_path, QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_listWidget_currentRowChanged(int currentRow);

    void on_add_pb_clicked();

    void on_del_pb_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_actionSave_triggered();

    void on_actionSave_on_edit_triggered(bool checked);

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

private:
    Ui::MainWindow *ui;
    std::vector<Data::Student> students;
    std::string data_path;
    std::string file_name;
    bool save_on_modify = true;
    void clear_formdata();
    void json_desrialize(string path);
    void json_serialize(string path);
    void closeEvent(QCloseEvent *event);
    void set_data_path(string file_path);
};

#endif // MAINWINDOW_H
