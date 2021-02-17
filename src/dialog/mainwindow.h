#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QTextEdit>

namespace Ui {
    class MainWindow;
}

class Server;
class QTextEdit;
class ConnectionDialog;


class BroadcastBox : public QDialog {
    Q_OBJECT

public:
    BroadcastBox(Server *server, QWidget *parent = 0);
protected:
    virtual void accept();
private:
    Server *server;
    QTextEdit *text_edit;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ConnectionDialog *connection_dialog;
    Server *server;

public slots:
    void startConnection();

private slots:
    void on_actionStart_Server_triggered();
};

#endif // MAINWINDOW_H
