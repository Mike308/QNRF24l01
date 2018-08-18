#ifndef QNRF24L01_H
#define QNRF24L01_H

#include <QObject>

class QNRF24L01 : public QObject
{
    Q_OBJECT
public:
    explicit QNRF24L01(QObject *parent = 0);
    QNRF24L01(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed);

signals:

public slots:
};

#endif // QNRF24L01_H
