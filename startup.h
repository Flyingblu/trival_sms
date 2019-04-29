#ifndef STARTUP_H
#define STARTUP_H

#include <QDialog>

namespace Ui {
class Startup;
}

class Startup : public QDialog
{
    Q_OBJECT

public:
    explicit Startup(QWidget *parent = nullptr);
    ~Startup();

private slots:
    void on_choose_file_pb_clicked();

    void on_ok_pb_clicked();

    void on_cancel_pb_clicked();

    void on_new_file_pb_clicked();

private:
    Ui::Startup *ui;
};

#endif // STARTUP_H
