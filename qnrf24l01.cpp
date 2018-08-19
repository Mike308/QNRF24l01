#include "qnrf24l01.h"

QNRF24L01::QNRF24L01(QObject *parent) : QObject(parent)
{

}

QNRF24L01::QNRF24L01(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed){
    radio = new RF24(cePin, csPin, spiSpeed);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(listenSlot()));
}

void QNRF24L01::connectToRadio(){
    qDebug () << "Connecting to RF24...";
    radio->begin();
}

void QNRF24L01::selectSendingPipes(uint64_t address){
    radio->openWritingPipe(address);
}

void QNRF24L01::selectRecevingPipe(uint8_t i, uint64_t address){
    radio->openReadingPipe(i, address);
}

void QNRF24L01::sendData(QString data){
    char * buf;
    QByteArray ba = data.toLatin1();
    buf = ba.data();
    radio->stopListening();
    radio->powerDown();
    radio->powerUp();
    radio->write(buf, 128);
    radio->startListening();
}

void QNRF24L01::startListening(){
    timer->start(1000);
}

void QNRF24L01::listenSlot(){
    char msg[] = "";
    uint8_t pipeNum = 0;
    int len = 0;
    qDebug() << "Start listening";
        while(radio->available(&pipeNum)){
            len = radio->getDynamicPayloadSize();
            radio->read(&msg, len);
            QString stringMsg = QString(msg);
            emit updatedStatus(receivingData);
            emit dataReceived(stringMsg, pipeNum);

        }

        emit updatedStatus(endOfReceiving);



}





