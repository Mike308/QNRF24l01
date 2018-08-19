#ifndef QNRF24L01NETWORK_H
#define QNRF24L01NETWORK_H

#include "qnrf24l01.h"

class QNRF24L01Network : public QNRF24L01
{
    Q_OBJECT
public:
    QNRF24L01Network(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed);
    void updateNodeAddressList(QString nodeAddress);
    void sendDataToNode(QString nodeAddress, QString data);

private:
    QList<QString> nodeAdressList;

signals:
    void receivedMessageFromNode(QString data, QString nodeAddress);

public slots:
    void receiveMessage(QString data, uint8_t pipeNum);
};

#endif // QNRF24L01NETWORK_H
