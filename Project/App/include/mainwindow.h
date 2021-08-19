#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <QMainWindow>
#include <QGraphicsScene>
#include <QListWidget>
#include <QListWidgetItem>
#include <iostream>
#include <fstream>
#include <stack>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ///\brief    Constructor
    MainWindow(QWidget *parent = nullptr);

    ///\brief    Destructor
    ~MainWindow();

private slots:
    ///\brief    Slot for opening an image.
    void on_actionOpen_triggered();

    ///\brief    Slot for saving an image as png.
    void on_actionSave_triggered();

    ///\brief    Slot for saving an image in any format.
    void on_actionSave_as_triggered();

    ///\brief    Slot for opening the recent files window.
    void on_actionRecent_files_triggered();

    ///\brief    Slot for exiting the program.
    void on_actionExit_triggered();

    ///\brief    Slot for opening the about window.
    void on_actionAbout_triggered();

    ///\brief    Slot for opening the info window.
    void on_actionInfo_triggered();

    ///\brief    Slot for applying the grayscale luminance filter on an image.
    void on_actionGrayScale_Luminance_triggered();

    ///\brief    Slot for applying the grayscale average filter on an image.
    void on_actionGrayScale_Average_triggered();

    ///\brief    Slot for applying the sepia filter on an image.
    void on_actionSepia_triggered();

    ///\brief    Slot for applying blur filter on an image.
    void on_actionBlur_triggered();

    ///\brief    Slot for applying negative on an image.
    void on_actionNegative_triggered();

    ///\brief    Slot for applying two tones filter on an image.
    void on_actionTwo_Tones_triggered();

    ///\brief    Slot for applying emboss filter on an image.
    void on_actionEmboss_triggered();

    ///\brief    Slot for applying brightness on an image.
    void on_actionBrightness_triggered();

    ///\brief    Slot for applying tv60 filter on an image.
    void on_actionTV_60_triggered();

    ///\brief    Slot for knowing when the row in the recent files window had changed.
    void on_Item_Row_Changed(int currentRow);

    ///\brief    Slot for undoing a change.
    void on_actionUndo_2_triggered();

    ///\brief    Slot for redoing a change.
    void on_actionRedo_2_triggered();

    ///\brief    Slot for moving the mouse.
    void mouseMoveEvent(QMouseEvent* event);

    ///\brief    Slot for changing an event.
    void changeEvent(QEvent*event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QListWidget* listWidget;
    QImage qImage; /**< The current image. */
    cv::Mat image; /**< The current image. */
    std::vector<QString> recentFiles; /**< Vector that stores the most recent 10 files opened. */
    std::vector<cv::Mat> undoMatVector; /**< Stack that stores the previous stages of the processed image. */
    std::vector<cv::Mat> redoMatVector; /**< Stack that stores the stages of an image for the redo action. */

private:
    ///\brief    Function that sets the paths of the icons in the taskbar.
    void SetIcons();

    ///\brief    Function that converts a cv::mat object into an QImage object.
    ///\param [in] source   cv::Mat object containing the image that will be modified by the user.
    ///\return   QImage object containing the same image as the param [in] object.
    QImage ConvertMatToQImage(const cv::Mat& source);

    ///\brief     Function that shows the image in the ui label and sets the message in the status bar.
    ///\param [in] img  QImage object containing the image to be set in the label from the ui.
    ///\param [in] text QString object containing the text to be shown in the status bar.
    void SetLabel(const QImage& img, const QString& text);

    ///\brief    Function that creates all the connections for the application.
    void CreateActions();

    ///\brief    Function that destroys all the connections for the application.
    void DisconnectActions();
};
#endif // MAINWINDOW_H
