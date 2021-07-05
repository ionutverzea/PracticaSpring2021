#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

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

    void on_actionGrayScale_Luminance_triggered();

    void on_actionGrayScale_Average_triggered();

    void on_actionSepia_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    cv::Mat image;
    void SetIcons();
    QImage ConvertMatToQImage(const cv::Mat& source);
};
#endif // MAINWINDOW_H
