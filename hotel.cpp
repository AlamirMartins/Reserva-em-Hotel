#include "hotel.h"

Hotel::Hotel()
{

}
void Hotel::inserirHospede(Hospede a)
{
    hotel.push_back(a);
}

void Hotel::ordenarPorData()
{
    std::sort(hotel.begin(), hotel.end(), [](Hospede a, Hospede b){return a.getCheckin()<b.getCheckin();});
}

void Hotel::ordenarPorNome()
{
    std::sort(hotel.begin(), hotel.end(),compHospede);
}

void Hotel::ordenarPorPreco()
{

}

Hospede Hotel::operator[](int i)
{
    return hotel[i];
}
int Hotel::size()
{
     return hotel.size();
}

void Hotel::clear()
{
    return hotel.clear();
}

bool compHospede(Hospede a, Hospede b)
{
    return a.getTitular()<b.getTitular();
}

/*bool compPreco(Hospede a, Hospede b)
{
    return a.getV
}*/
