#ifndef HOTEL_H
#define HOTEL_H

#include <QObject>
#include <QVector>
#include <algorithm>
#include <QFile>
#include "hospede.h"


class Hotel
{

private:
    QVector<Hospede> hotel;


public:

    Hotel();
    Hospede operator [](int i);

    void inserirHospede(const Hospede a);
    void ordenarPorData();
    void ordenarPorNome();
    void ordenarPorPreco();

    int size();
    void clear();
};

bool compHospede(Hospede a,Hospede b);
bool compPreco(Hospede a,Hospede b);
//bool comp(Hospede a,Hospede b);



#endif // HOTEL_H
