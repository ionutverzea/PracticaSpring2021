#include "../../App/include/mainwindow.h"
#include "./ui_mainwindow.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "../../App/include/Utils.h"

#include<QMessageBox>
#include<QFile>
#include<QFileDialog>
#include<QImage>
#include<QGraphicsItem>
#include<QGraphicsPixmapItem>
#include<QGraphicsView>
#include<QSize>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //scene = new QGraphicsScene(0,0,500,500);

}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString filter =  "All files (*.*);;JPEG(*.jpg);;PNG(*.png);;TIFF(*.tif)";
       QFile file("C://");
        QString filename=QFileDialog::getOpenFileName(
                    this,
                    tr("Open File"),
                    "C://",
                    filter
                    );
         if(!filename.isEmpty()){
               QImage image(filename);
               //cv::Mat image = Utils::ReadImage(filename.toStdString());
    //          QGraphicsPixmapItem item(QPixmap::fromImage(image));
    //           QGraphicsScene scene(this);
    //           ui->graphicsView->setScene(scene);
    //           ui->graphicsView->show();


               int w = ui->label->width();
               int h = ui->label->height();
               //QImage img = QImage((uchar*)image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
               ui->label->setPixmap(QPixmap::fromImage(image.scaled(w,h,Qt::KeepAspectRatio)));
               ui->statusbar->showMessage("File loaded");


         }else{

             ui->statusbar->showMessage("File is not a image");
    }
}



void MainWindow::on_actionSave_triggered()
{
    QMessageBox::information(this,"title","Save");
}


void MainWindow::on_actionSave_as_triggered()
{

}


void MainWindow::on_actionRecent_files_triggered()
{

}



void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionAbout_triggered()
{

}


void MainWindow::on_actionInfo_triggered()
{

}

