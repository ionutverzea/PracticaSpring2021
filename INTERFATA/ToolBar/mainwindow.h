#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionRecent_files_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionInfo_triggered();

    void mouseMoveEvent(QMouseEvent* event);
    void changeEvent(QEvent*event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QImage image;
};
#endif // MAINWINDOW_H
