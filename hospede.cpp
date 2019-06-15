#include "hospede.h"
#include <QApplication>
#include <QObject>
#include <QVector>
#include <algorithm>
#include <QFile>
#include "hospede.h"



QString Hospede::getAdultos() const
{
    return adultos;
}

void Hospede::setAdultos(const QString &value)
{
   adultos = value;
}

QString Hospede::getCriancas() const
{
    return criancas;
}

void Hospede::setCriancas(const QString &value)
{
    criancas = value;
}


QString Hospede::getTitular() const
{

    return titular;
}

void Hospede::setTitular(const QString &value)
{
    titular = value;
}

QString Hospede::getEmail() const
{
    return email;
}

void Hospede::setEmail(const QString &value)
{
    email = value;
}

QString Hospede::getFone() const
{
    return fone;
}

void Hospede::setFone(const QString &value)
{
    fone = value;
}

QString Hospede::getCheckin() const
{
    return checkin;
}

void Hospede::setCheckin(const QString &value)
{
    checkin = value;
}

QString Hospede::getCheckout() const
{
    return checkout;
}

void Hospede::setCheckout(const QString &value)
{
    checkout = value;
}

int Hospede::getValor() const
{
    return valor;
}

void Hospede::setValor(int value)
{
    valor = value;
}


Hospede::Hospede()
{

}

