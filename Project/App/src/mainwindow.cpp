#include "../../App/include/mainwindow.h"
#include "./ui_mainwindow.h"

#include "../../App/include/Utils.h"
#include "GraphicalAlgorithmsLibrary.h"

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QInputDialog>
#include <QImage>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QSize>
#include <QLayout>
#include <QRect>
#include <iostream>
#include <QResizeEvent>
#include <QEvent>
#include <QListWidget>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	SetIcons();
	recentFiles = Utils::ReadFile("recentFiles.txt");
}

MainWindow::~MainWindow()
{
	Utils::WriteFile("recentFiles.txt", recentFiles);
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
		if (recentFiles.size() < 9)
		{
			recentFiles.push_back(filename);
		}
		else
		{
			recentFiles.pop_back();
			recentFiles.push_back(filename);
		}

		image = Utils::ReadImage(filename.toStdString());
		cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
		QImage convertedImage = ConvertMatToQImage(image);

		int w = ui->label->width();
		int h = ui->label->height();
		ui->label->setPixmap(QPixmap::fromImage(convertedImage));
		ui->label->resize(ui->label->pixmap()->size());
		ui->statusbar->showMessage("File loaded " + filename);
		qImage = convertedImage;
	}
	else
		ui->statusbar->showMessage("File is not an image");
}


void MainWindow::on_actionSave_triggered()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image File"),
		QString(),
		tr("PNG(*.png)"));
	if (!fileName.isEmpty())
	{
		qImage = ConvertMatToQImage(image);
		qImage.save(fileName);
	}
	ui->statusbar->showMessage("Image save");
}

void MainWindow::on_actionSave_as_triggered()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image File"),
		QString(),
		tr("PNG(*.png);;JPG(*.jpg);;TIFF(*.tif);;GIF(*.gif)"));
	if (!fileName.isEmpty())
	{
		qImage = ConvertMatToQImage(image);
		qImage.save(fileName);
	}
	ui->statusbar->showMessage("Image save");
}


void MainWindow::on_actionRecent_files_triggered()
{
	QListWidget* listWidget = new QListWidget;
	listWidget->setWindowTitle("Recent files");
	for each (QString var in recentFiles)
		listWidget->addItem(var);
	listWidget->show();

	//listWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
	//listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	//listWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
	
	if (listWidget->item(0))
	{
		image = Utils::ReadImage(recentFiles.at(0).toStdString());
		cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
		QImage convertedImage = ConvertMatToQImage(image);

		int w = ui->label->width();
		int h = ui->label->height();
		ui->label->setPixmap(QPixmap::fromImage(convertedImage));
		ui->label->resize(ui->label->pixmap()->size());
		ui->statusbar->showMessage("File loaded " + recentFiles.at(0));
		qImage = convertedImage;
	}
}

void MainWindow::on_actionExit_triggered()
{
	QApplication::quit();
}


void MainWindow::on_actionAbout_triggered()
{
	QMessageBox about;
	about.setWindowTitle("About");
	about.setText("Program de editare grafica a pozelor, implementat cu ajutorul OpenCV si Qt.");
	about.exec();
}


void MainWindow::on_actionInfo_triggered()
{
	QMessageBox info;
	info.setWindowTitle("Info");
	info.setText("Program realizat in cadrul programului de internship Siemens.");
	info.exec();
}


void MainWindow::mouseMoveEvent(QMouseEvent* event)
{

	QRect geometry = ui->centralwidget->geometry();
	int w = geometry.width();
	int h = geometry.height();


	ui->label->setPixmap(QPixmap::fromImage(qImage.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
}

void MainWindow::changeEvent(QEvent* event)
{
	if (event->type() == QEvent::WindowStateChange)
	{
		if (static_cast<QWindowStateChangeEvent*>(event)->oldState() == windowState())
		{
			return;
		}

		QRect geometry = ui->centralwidget->geometry();
		int w = geometry.width();
		int h = geometry.height();

		if (isMaximized()) {
			//conditi h si l
			ui->label->setPixmap(QPixmap::fromImage(qImage.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
		}
		else {

			ui->label->setPixmap(QPixmap::fromImage(qImage.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
			QSize q;
			q.scale(w, h, Qt::KeepAspectRatio);
			setFixedSize(q);
		}
	}
}

void MainWindow::on_actionGrayScale_Luminance_triggered()
{
	cv::Mat temp = GrayScale_Luminance(image);
	image = temp;
	QImage convertedImage = ConvertMatToQImage(temp);
	SetLabel(convertedImage, "GrayScale Luminance");
}

void MainWindow::on_actionGrayScale_Average_triggered()
{
	cv::Mat temp = GrayScale_Average(image);
	image = temp;
	QImage convertedImage = ConvertMatToQImage(temp);
	SetLabel(convertedImage, "GrayScale Average");
}

void MainWindow::on_actionSepia_triggered()
{
	cv::Mat temp = SepiaFilter(image);
	image = temp;
	QImage convertedImage = ConvertMatToQImage(temp);
	SetLabel(convertedImage, "Sepia");
}

void MainWindow::on_actionBlur_triggered()
{
	bool ok;
	int value = QInputDialog::getInt(this, tr("Integer"), tr("Enter a number for the kernel size of the blur"), 0, 0, 100, 1, &ok);
	if (ok)
	{
		cv::Mat temp = BlurFilter(image, value);
		image = temp;
		QImage convertedImage = ConvertMatToQImage(temp);
		SetLabel(convertedImage, "Blur");
	}
}

void MainWindow::on_actionNegative_triggered()
{
	cv::Mat temp = Negative(image);
	image = temp;
	QImage convertedImage = ConvertMatToQImage(temp);
	SetLabel(convertedImage, "Negative");
}

void MainWindow::on_actionTwo_Tones_triggered()
{
	cv::Mat temp = Two_Tones(image);
	image = temp;
	QImage convertedImage = ConvertMatToQImage(temp);
	SetLabel(convertedImage, "Two Tones");
}

void MainWindow::on_actionEmboss_triggered()
{
	cv::Mat temp = Emboss(image);
	image = temp;
	QImage convertedImage = ConvertMatToQImage(temp);
	SetLabel(convertedImage, "Emboss");
}

void MainWindow::on_actionBrightness_triggered()
{
	bool ok;
	int value = QInputDialog::getInt(this, tr("Integer"), tr("Enter a number representing the scale of the brightness"), 0, 0, 100, 1, &ok);
	if (ok)
	{
		cv::Mat temp = Brightness(image, value);
		image = temp;
		QImage convertedImage = ConvertMatToQImage(temp);
		SetLabel(convertedImage, "Brightness");
	}
}

void MainWindow::on_actionTV_60_triggered()
{
	cv::Mat temp = TV_60(image);
	image = temp;
	QImage convertedImage = ConvertMatToQImage(temp);
	SetLabel(convertedImage, "TV_60");
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

QImage MainWindow::ConvertMatToQImage(const cv::Mat& source)
{
	cv::Mat cpyImage = source;
	if (cpyImage.channels() == 4)
	{
		QImage result = QImage((uchar*)cpyImage.data, cpyImage.cols, cpyImage.rows, QImage::Format_ARGB32);
		return result;
	}
	if (cpyImage.channels() == 3)
	{
		QImage result = QImage((uchar*)cpyImage.data, cpyImage.cols, cpyImage.rows, QImage::Format_RGB888);
		return result;
	}
	if (cpyImage.channels() == 1)
	{
		QImage result = QImage((uchar*)cpyImage.data, cpyImage.cols, cpyImage.rows, QImage::Format_Indexed8);
		return result;
	}
}

void MainWindow::SetLabel(const QImage& img, const QString& text)
{
	ui->label->setPixmap(QPixmap::fromImage(img));
	ui->label->resize(ui->label->pixmap()->size());
	ui->statusbar->showMessage(text + " filter applied");
}





