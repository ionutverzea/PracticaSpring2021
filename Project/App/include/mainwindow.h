#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <QMainWindow>
#include <QGraphicsScene>
#include <iostream>
#include <fstream>

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
    void on_actionBlur_triggered();
    void on_actionNegative_triggered();
    void on_actionTwo_Tones_triggered();
    void on_actionEmboss_triggered();
    void on_actionBrightness_triggered();
    void on_actionTV_60_triggered();

    void mouseMoveEvent(QMouseEvent* event);
    void changeEvent(QEvent*event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QImage qImage;
    cv::Mat image;
    std::vector<QString> recentFiles;

private:
    void SetIcons();
    QImage ConvertMatToQImage(const cv::Mat& source);
    void SetLabel(const QImage& img, const QString& text);
};
#endif // MAINWINDOW_H
