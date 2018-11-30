//
// Created by poldera_sithgod on 26/11/18.
//

#ifndef PROJETOFINAL_MULTILISTA_SYSTEM_H
#define PROJETOFINAL_MULTILISTA_SYSTEM_H

#include "MultiList.h"
#include "Vehicle.h"
#include "strucs/LinkedList.h"

#include <string>
#include <iostream>

class System {

public:
    System();
    ~System();

    //void init();
    void populate();
    void run();

private:
    MultiList<Vehicle> _multiList;
};


System::System():
    _multiList{}
{}

System::~System() {
}

void System::populate() {
    //Ford vehicles
    _multiList.insertVehicle("AAA1", "SC", "Palhoca", "Ford", "9", "1998");
    _multiList.insertVehicle("AAA2", "SC", "Palhoca", "Ford", "9", "1998");
    _multiList.insertVehicle("AAA3", "PR", "Cascavel", "Ford", "3", "2018");
    _multiList.insertVehicle("AAA4", "RJ", "Rio de Janeiro", "Ford", "4", "1982");
    _multiList.insertVehicle("AAA5", "RJ", "Rio de Janeiro", "Ford", "1", "2005");
    _multiList.insertVehicle("AAA6", "SP", "Sao Paulo", "Ford", "9", "1992");
    _multiList.insertVehicle("AAA7", "MG", "Ouro Preto", "Ford", "9", "1998");

    //VW vehicles
    _multiList.insertVehicle("AAB1", "SC", "Florianopolis", "VW", "2", "2012");
    _multiList.insertVehicle("AAB2", "SC", "Florianopolis", "VW", "8", "2011");
    _multiList.insertVehicle("AAB3", "PR", "Curitiba", "VW", "0", "2019");
    _multiList.insertVehicle("AAB4", "RS", "Porto Alegre", "VW", "2", "2002");
    _multiList.insertVehicle("AAB5", "RS", "Porto Alegre", "VW", "1", "2016");
    _multiList.insertVehicle("AAB6", "RS", "Caxias", "VW", "7", "2011");
    _multiList.insertVehicle("AAB7", "BA", "Salvador", "VW", "2", "2011");
    _multiList.insertVehicle("AAB8", "BA", "Salvador", "VW", "6", "2016");

    //GM vehicles
    _multiList.insertVehicle("ABA1", "SC", "Itajai", "GM", "3", "2004");
    _multiList.insertVehicle("ABA2", "SC", "Itajai", "GM", "3", "2004");
    _multiList.insertVehicle("ABA3", "SC", "Joinville", "GM", "2", "2001");
    _multiList.insertVehicle("ABA4", "SC", "Palhoca", "GM", "7", "2000");
    _multiList.insertVehicle("ABA5", "PR", "Cascavel", "GM", "1", "2000");
    _multiList.insertVehicle("ABA6", "RJ", "Niteroi", "GM", "2", "2001");
    _multiList.insertVehicle("ABA7", "SP", "Sao Paulo", "GM", "4", "2003");
    _multiList.insertVehicle("ABA8", "SP", "Taubate", "GM", "8", "2012");
    _multiList.insertVehicle("ABA9", "MA", "Manaus", "GM", "0", "2002");

    //Volvo vehicles
    _multiList.insertVehicle("BAA1", "RJ", "Niteroi", "Volvo", "0", "2008");
    _multiList.insertVehicle("BAA2", "RJ", "Niteroi", "Volvo", "0", "2018");
    _multiList.insertVehicle("BAA3", "RJ", "Cabo Frio", "Volvo", "0", "2012");
    _multiList.insertVehicle("BAA4", "RJ", "Duque de Caxias", "Volvo", "0", "2016");
    _multiList.insertVehicle("BAA5", "SP", "Avare", "Volvo", "0", "2010");
    _multiList.insertVehicle("BAA6", "SP", "Sao Paulo", "Volvo", "0", "2019");

    //Toyota vehicles
    _multiList.insertVehicle("ABB1", "SC", "Criciuma", "Toyota", "2", "2006");
    _multiList.insertVehicle("ABB2", "SC", "Criciuma", "Toyota", "3", "2016");
    _multiList.insertVehicle("ABB3", "SC", "Palhoca", "Toyota", "4", "2002");
    _multiList.insertVehicle("ABB4", "SC", "Joinville", "Toyota", "2", "2016");
    _multiList.insertVehicle("ABB5", "PR", "Londrina", "Toyota", "0", "2018");
    _multiList.insertVehicle("ABB6", "MG", "Belo Horizonte", "Toyota", "0", "2001");
    _multiList.insertVehicle("ABB7", "MG", "Uberaba", "Toyota", "5", "2004");
    _multiList.insertVehicle("ABB8", "CE", "Fortaleza", "Toyota", "6", "2016");
}

void System::run() {
    // builder -> paramtype 0
    // final -> paramtype 1
    // state -> paramtype 2
    // city -> paramtype 3
    LinkedList<Vehicle*>* fordList =_multiList.searchData("Ford", 0);
    std::cout << "Lista de Carros Ford:" << std::endl;
    std::cout << "" << std::endl;
    for (int pos = 0; pos < fordList->size(); pos++) {
        Vehicle* vehicle = fordList->at(pos);
        std::cout << "Placa:" << vehicle->get_plate() << " - " << vehicle->get_city() << "/" << vehicle->get_state() << " - Final #" << vehicle->get_final() <<std::endl;
    }
    std::cout << "" << std::endl;

    LinkedList<Vehicle*>* volvoList =_multiList.searchData("Volvo", 0);
    std::cout << "Lista de Carros Volvo:" << std::endl;
    std::cout << "" << std::endl;
    for (int pos = 0; pos < volvoList->size(); pos++) {
        Vehicle* vehicle = volvoList->at(pos);
        std::cout << "Placa:" << vehicle->get_plate() << " - " << vehicle->get_city() << "/" << vehicle->get_state() << " - Final #" << vehicle->get_final() <<std::endl;
    }
    std::cout << "" << std::endl;

    LinkedList<Vehicle*>* toyotaList =_multiList.searchData("Toyota", 0);
    std::cout << "Lista de Carros Toyota:" << std::endl;
    std::cout << "" << std::endl;
    for (int pos = 0; pos < toyotaList->size(); pos++) {
        Vehicle* vehicle = toyotaList->at(pos);
        std::cout << "Placa:" << vehicle->get_plate() << " - " << vehicle->get_city() << "/" << vehicle->get_state() << " - Final #" << vehicle->get_final() <<std::endl;
    }
    std::cout << "" << std::endl;

    LinkedList<Vehicle*>* vwList =_multiList.searchData("Ford", 0);
    std::cout << "Lista de Carros VW:" << std::endl;
    std::cout << "" << std::endl;
    for (int pos = 0; pos < vwList ->size(); pos++) {
        Vehicle* vehicle = vwList ->at(pos);
        std::cout << "Placa:" << vehicle->get_plate() << " - " << vehicle->get_city() << "/" << vehicle->get_state() << " - Final #" << vehicle->get_final() <<std::endl;
    }
    std::cout << "" << std::endl;

    LinkedList<Vehicle*>* gmList =_multiList.searchData("Ford", 0);
    std::cout << "Lista de Carros VW:" << std::endl;
    std::cout << "" << std::endl;
    for (int pos = 0; pos < gmList ->size(); pos++) {
        Vehicle* vehicle = gmList ->at(pos);
        std::cout << "Placa:" << vehicle->get_plate() << " - " << vehicle->get_city() << "/" << vehicle->get_state() << " - Final #" << vehicle->get_final() <<std::endl;
    }
    std::cout << "" << std::endl;

}

#endif //PROJETOFINAL_MULTILISTA_SYSTEM_H
