#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class FitView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setBackgroundBrush(bool center_as_origin);

public:
    virtual void closeEvent(QCloseEvent *event);
private:
    FitView *view;
    QGraphicsScene *scene;
    Ui::MainWindow *ui;

    void restoreFromConfig();

private slots:
    void on_actionExit_triggered();
};

#endif // MAINWINDOW_H
