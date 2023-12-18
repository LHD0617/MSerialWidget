#include "mserialwidget.h"
#include "ui_mserialwidget.h"

MSerialWidget::MSerialWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MSerialWidget)
{
    switchState = false;

    ui->setupUi(this);

    connect(ui->switchPbtn, SIGNAL(clicked()), this, SLOT(switchPort()));
    connect(&refreshTimer, SIGNAL(timeout()), this, SLOT(refreshProt()));

    refreshTimer.start(100);
}

MSerialWidget::~MSerialWidget()
{
    delete ui;
}

void MSerialWidget::refreshProt()
{
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        qDebug() << info.portName() << info.description();
    }
}

void MSerialWidget::switchPort()
{
    if (switchState == false)
    {
        switchState = true;

        ui->switchPbtn->setText("关闭串口");
        ui->portCobox->setEnabled(false);
        ui->baudCobox->setEnabled(false);
        ui->dataCobox->setEnabled(false);
        ui->checkCobox->setEnabled(false);
        ui->stopCobox->setEnabled(false);
    }
    else
    {
        switchState = false;

        ui->switchPbtn->setText("打开串口");
        ui->portCobox->setEnabled(true);
        ui->baudCobox->setEnabled(true);
        ui->dataCobox->setEnabled(true);
        ui->checkCobox->setEnabled(true);
        ui->stopCobox->setEnabled(true);
    }
}
