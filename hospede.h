#ifndef HOSPEDE_H
#define HOSPEDE_H


#include <QObject>


class Hospede
{


private:

    QString titular;
    QString email;
    QString fone;
    QString checkin;
    QString checkout;
    QString adultos;
    QString criancas;
    int valor;

public:
    Hospede();


    QString getAdultos() const;
    void setAdultos(const QString &value);
    QString getCriancas() const;
    void setCriancas(const QString &value);
    QString getStatus();

    QString getTitular() const;
    void setTitular(const QString &value);
    QString getEmail() const;
    void setEmail(const QString &value);
    QString getFone() const;
    void setFone(const QString &value);
    QString getCheckin() const;
    void setCheckin(const QString &value);
    QString getCheckout() const;
    void setCheckout(const QString &value);
    int getValor() const;
    void setValor(int value);

};

#endif // HOSPEDE_H

