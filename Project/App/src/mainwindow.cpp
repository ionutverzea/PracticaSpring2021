#include "../../App/include/mainwindow.h"
#include "./ui_mainwindow.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "../../App/include/Utils.h"

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QImage>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QSize>
#include <QApplication>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	SetIcons();
}

MainWindow::~MainWindow()
{
	delete scene;
	delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
	QString filter = "All files (*.*);;JPEG(*.jpg);;PNG(*.png);;TIFF(*.tif)";
	QFile file("C://");
	QString filename = QFileDialog::getOpenFileName(
		this,
		tr("Open File"),
		"C://",
		filter
	);
	if (!filename.isEmpty())
	{
		QImage image(filename);

		int w = ui->label->width();
		int h = ui->label->height();
		ui->label->setPixmap(QPixmap::fromImage(image.scaled(w, h, Qt::KeepAspectRatio)));
		ui->statusbar->showMessage("File loaded");

		cv::Mat img = Utils::ReadImage(filename.toStdString());
		Utils::ShowImage(img);

	}
	else
	{
		ui->statusbar->showMessage("File is not a image");
	}
}

void MainWindow::on_actionSave_triggered()
{
	QMessageBox::information(this, "title", "Save");
}

void MainWindow::on_actionSave_as_triggered()
{

}

void MainWindow::on_actionRecent_files_triggered()
{

}

void MainWindow::on_actionExit_triggered()
{
	qApp->quit();
}

void MainWindow::on_actionAbout_triggered()
{

}

void MainWindow::on_actionInfo_triggered()
{

}

void MainWindow::SetIcons()
{
	//open folder icon
	QPixmap icon = QPixmap(QString("C:\\Users\\Laur\\source\\repos\\Practica Siemens\\Application\\App\\Resources\\open.png"));
	ui->actionOpen->setIcon(QIcon(icon));

	//save icon
	icon = QPixmap(QString("C:\\Users\\Laur\\source\\repos\\Practica Siemens\\Application\\App\\Resources\\save.png"));
	ui->actionSave->setIcon(QIcon(icon));

	//save as icon
	icon = QPixmap(QString("C:\\Users\\Laur\\source\\repos\\Practica Siemens\\Application\\App\\Resources\\save_as.jpg"));
	ui->actionSave_as->setIcon(QIcon(icon));

	//exit icon
	icon = QPixmap(QString("C:\\Users\\Laur\\source\\repos\\Practica Siemens\\Application\\App\\Resources\\exit.png"));
	ui->actionExit->setIcon(QIcon(icon));

	//about icon
	icon = QPixmap(QString("C:\\Users\\Laur\\source\\repos\\Practica Siemens\\Application\\App\\Resources\\about.jpg"));
	ui->actionAbout->setIcon(QIcon(icon));

	//recent files icon
	icon = QPixmap(QString("C:\\Users\\Laur\\source\\repos\\Practica Siemens\\Application\\App\\Resources\\recent_file.png"));
	ui->actionRecent_files->setIcon(QIcon(icon));

	//info icon
	icon = QPixmap(QString("C:\\Users\\Laur\\source\\repos\\Practica Siemens\\Application\\App\\Resources\\info.png"));
	ui->actionInfo->setIcon(QIcon(icon));
}

