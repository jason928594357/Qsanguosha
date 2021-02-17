#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>



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


public slots:
    void startConnection();
};

#endif // MAINWINDOW_H
