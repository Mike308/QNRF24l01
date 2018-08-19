#ifndef QNRF24L01_H
#define QNRF24L01_H

#include <QObject>
#include <QTimer>
#include <QDebug>

#include "3rdparty/RF24.h"
#include "3rdparty/RF24_config.h"

class QNRF24L01 : public QObject
{
    Q_OBJECT
public:
    explicit QNRF24L01(QObject *parent = 0);
    QNRF24L01(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed);
    void connectToRadio();
    void selectSendingPipes(uint64_t address);
    void selectRecevingPipe(uint8_t i, uint64_t address);
    void sendData(QString data);
    void startListening();
    int getStatus() const;
    enum {receivingData, endOfReceiving};

private:
    RF24 * radio;
    QTimer *timer;
    int status;

signals:
    void dataReceived(QString data, uint8_t pipeNum);
    void updatedStatus(int status);

private slots:
    void listenSlot();

public slots:

};

#endif // QNRF24L01_H
