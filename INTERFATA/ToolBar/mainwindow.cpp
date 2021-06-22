#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMessageBox>
#include<QFile>
#include<QFileDialog>
#include<QImage>
#include<QGraphicsItem>
#include<QGraphicsPixmapItem>
#include<QGraphicsView>
#include<QSize>
#include<QLayout>
#include<QRect>
#include<iostream>
#include<QResizeEvent>
#include<QEvent>

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
               //QPixmap scaledPixmap = myPixmap(QSize(100,100));
              // QPixmap p; // load pixmap
               // get label dimensions
//               int w = ui->label->width();
//               int h = ui->label->height();

               // set a scaled pixmap to a w x h window keeping its aspect ratio
              // ui->label->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
              /* QImage img2 = image.scaled(100,100,Qt::KeepAspectRatio);
               QLabel *plotImg = new QLabel;
               plotImg->setScaledContents(true);
               plotImg->setPixmap(QPixmap::fromImage(img2))*/;

    //          QGraphicsPixmapItem item(QPixmap::fromImage(image));
    //           QGraphicsScene scene(this);
    //           ui->graphicsView->setScene(scene);
    //           ui->graphicsView->show();



//               int w = ui->label->width();
//               int h = ui->label->height();
//               int*left;
//               int*right;
//               int*top;
//               int*bottom;
               QRect geometry = ui->centralwidget->geometry();
               int w=geometry.width();
               int h = geometry.height();


               ui->label->setPixmap(QPixmap::fromImage(image.scaled(w,h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

               QString mesage = "File loaded: " + filename;
               ui->statusbar->showMessage(mesage);
               ui->statusbar->size();


    }
         image=QImage(filename);
}


void MainWindow::on_actionSave_triggered()
{
    //QMessageBox::information(this,"title","Save");
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image File"),
                                                    QString(),
                                                    tr("Images (*.png)"));
    if (!fileName.isEmpty())
    {
      image.save(fileName);
    }
    ui->statusbar->showMessage("Image save");

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

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

    QRect geometry = ui->centralwidget->geometry();
    int w=geometry.width();
    int h = geometry.height();


    ui->label->setPixmap(QPixmap::fromImage(image.scaled(w,h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
}

void MainWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::WindowStateChange)
        {
            if (static_cast<QWindowStateChangeEvent*>(event)->oldState() == windowState())
            {
                return;
            }

    QRect geometry = ui->centralwidget->geometry();
    int w=geometry.width();
    int h = geometry.height();

if(isMaximized()){
    //conditi h si l
    ui->label->setPixmap(QPixmap::fromImage(image.scaled(w,h,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
}
else {

  ui->label->setPixmap(QPixmap::fromImage(image.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation)));
     QSize q;
     q.scale(w,h,Qt::KeepAspectRatio);
    setFixedSize(q);
}
    }

}





