#ifndef MSERIALWIDGET_H
#define MSERIALWIDGET_H

#include <QDebug>
#include <QWidget>
#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class MSerialWidget;
}

class MSerialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MSerialWidget(QWidget *parent = nullptr);
    ~MSerialWidget();

private:
    bool switchState;

    QStringList portList;

    QSerialPort serial;

    QTimer refreshTimer;

    Ui::MSerialWidget *ui;

public slots:

private slots:
    void refreshProt();
    void switchPort();
};

#endif // MSERIALWIDGET_H
