#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->serialWidget->serial, SIGNAL(readyRead()), this, SLOT(handle()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle()
{
    ui->serialWidget->serial->write(ui->serialWidget->serial->readAll());
}
