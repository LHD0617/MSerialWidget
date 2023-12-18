#include "mserialwidget.h"
#include "ui_mserialwidget.h"

static const enum QSerialPort::DataBits dataBitsMap[] = {QSerialPort::Data5, QSerialPort::Data6, QSerialPort::Data7, QSerialPort::Data8};
static const enum QSerialPort::Parity parityMap[] = {QSerialPort::NoParity, QSerialPort::EvenParity, QSerialPort::OddParity};
static const enum QSerialPort::StopBits stopBitsMap[] = {QSerialPort::OneStop, QSerialPort::OneAndHalfStop, QSerialPort::TwoStop};

MSerialWidget::MSerialWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MSerialWidget)
{
    switchState = false;
    portList.clear();
    serial = new QSerialPort();

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
    QStringList list;

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        list << QString(info.portName() + ":" + info.description());
    }

    if (switchState == false)
    {
        if (list != portList)
        {
            portList.clear();
            portList = list;
            ui->portCobox->clear();
            ui->portCobox->addItems(list);
        }
    }
    else if (!list.contains(ui->portCobox->currentText()))
    {
        switchPort();
    }
}

void MSerialWidget::switchPort()
{
    if (switchState == false)
    {
        if (ui->portCobox->count() > 0)
        {
            serial->setPort(QSerialPortInfo::availablePorts().at(ui->portCobox->currentIndex()));
            serial->setBaudRate(ui->baudCobox->currentText().toInt());
            serial->setDataBits(dataBitsMap[ui->dataCobox->currentIndex()]);
            serial->setParity(parityMap[ui->checkCobox->currentIndex()]);
            serial->setStopBits(stopBitsMap[ui->stopCobox->currentIndex()]);

            if (serial->open(QIODevice::ReadWrite))
            {
                switchState = true;

                ui->switchPbtn->setText("关闭串口");
                ui->portCobox->setEnabled(false);
                ui->baudCobox->setEnabled(false);
                ui->dataCobox->setEnabled(false);
                ui->checkCobox->setEnabled(false);
                ui->stopCobox->setEnabled(false);
                emit log("打开成功");
            }
            else
            {
                emit log("打开失败");
            }
        }
        else
        {
            emit log("未搜索到可用串口");
        }
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
        serial->close();
        emit log("关闭串口");
    }
}

bool MSerialWidget::getSwitchState()
{
    return switchState;
}
