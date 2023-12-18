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
    QSerialPort* serial;

    bool getSwitchState();

    explicit MSerialWidget(QWidget *parent = nullptr);
    ~MSerialWidget();

private:
    bool switchState;

    QStringList portList;

    QTimer refreshTimer;

    Ui::MSerialWidget *ui;

public slots:

private slots:
    void refreshProt();
    void switchPort();

signals:
    void log(QString log);
};

#endif // MSERIALWIDGET_H
