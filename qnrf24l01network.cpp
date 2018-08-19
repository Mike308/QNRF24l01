#include "qnrf24l01network.h"

QNRF24L01Network::QNRF24L01Network(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed) : QNRF24L01(cePin, csPin, spiSpeed){
    connect(this, SIGNAL(dataReceived(QString,uint8_t)), this, SLOT(receiveMessage(QString,uint8_t)));
}

void QNRF24L01Network::updateNodeAddressList(QString nodeAddress){
    this->nodeAdressList.append(nodeAddress);
}

void QNRF24L01Network::sendDataToNode(QString nodeAddress, QString data){
    this->sendData(nodeAddress+"|"+data);
}

void QNRF24L01Network::receiveMessage(QString data, uint8_t pipeNum){
    QStringList items = data.split("|");
    if (this->nodeAdressList.contains(items.at(0))) emit receivedMessageFromNode(items.at(1), items.at(0));
}
