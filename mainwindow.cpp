#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mThread = new MyThread();
    connect(mThread, SIGNAL(Display(QImage)), this, SLOT(onDisplay(QImage)));
    connect(mThread, SIGNAL(WebDisplay(QImage)), this, SLOT(onWebDisplay(QImage)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //start
    mThread->start();
    mThread->Stop = false;
    mThread->LStop =true;
}

void MainWindow::on_pushButton_2_clicked()
{
    //stop
    mThread->Stop = true;
    mThread->LStop =true;
}

void MainWindow::onDisplay(QImage image)
{
    ui->label->setPixmap(QPixmap::fromImage(image.rgbSwapped()));

}

void MainWindow::onWebDisplay(QImage image)
{
    ui->label_2->setPixmap(QPixmap::fromImage(image.rgbSwapped()));

}

void MainWindow::on_pushButton_3_clicked()
{
    mThread->start();
    mThread->LStop=false;
    mThread->Stop = true;
}

void MainWindow::on_pushButton_4_clicked()
{
    mThread->LStop =true;
    mThread->Stop = true;
}
