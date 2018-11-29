//
// Created by poldera_sithgod on 26/11/18.
//

#ifndef PROJETOFINAL_MULTILISTA_SYSTEM_H
#define PROJETOFINAL_MULTILISTA_SYSTEM_H

#include "Vehicle.h"
#include "strucs/ArrayList.h"
#include "strucs/LinkedList.h"
#include "strucs/InnerLinkedList.h"


template <typename T>
class MultiList {
public:
    MultiList();
    ~MultiList();
    T searchData(T param);
    T searchData(T param1, T param2);
    void insertData(std::string plate, std::string state, std::string city, std::string builder, std::string final, std::string year);
    T removeData(T data);
    LinkedList<Vehicle>* getDirectory(std::string key);
    Vehicle[] showAll();
private:
    ArrayList<LinkedList<Vehicle>> _directories{4u};
    void insertIntoDirectory(Vehicle* vehicle, LinkedList<InnerLinkedList<Vehicle*>*> directory, std::string subkey);

    LinkedList<InnerLinkedList<Vehicle*>*> _builderDirectory;
    LinkedList<InnerLinkedList<Vehicle*>*> _stateDirectory;
    LinkedList<InnerLinkedList<Vehicle*>*> _cityDirectory;
    LinkedList<InnerLinkedList<Vehicle*>*> _finalDirectory;
    ArrayList<Vehicle*> _vehicles;
};

template <typename T>
MultiList<T>::MultiList() {
    _builderDirectory = new LinkedList<InnerLinkedList<Vehicle*>*>;
    _finalDirectory = new LinkedList<InnerLinkedList<Vehicle*>*>;
    _stateDirectory = new LinkedList<InnerLinkedList<Vehicle*>*>;
    _cityDirectory = new LinkedList<InnerLinkedList<Vehicle*>*>;
    _vehicles = new ArrayList<Vehicle*>;
}

template <typename T>
void MultiList<T>::insertData(std::string plate, std::string state, std::string city, std::string builder, std::string final, std::string year) {
    Vehicle* vehicle = new Vehicle(plate, state, city, builder, final, year);

    insertIntoDirectory(vehicle, _builderDirectory, vehicle->get_builder());
    insertIntoDirectory(vehicle, _stateDirectory, vehicle->get_state());
    insertIntoDirectory(vehicle, _finalDirectory, vehicle->get_final());
    insertIntoDirectory(vehicle, _cityDirectory, vehicle->get_city());
}

template <typename T>
void MultiList<T>::insertIntoDirectory(Vehicle* vehicle, LinkedList<InnerLinkedList<Vehicle*>*> directory, std::string subkey) {
    if (directory.empty()) {
        directory.push_back(new InnerLinkedList<Vehicle *>(subkey));
        directory.at(0)->push_front(vehicle);
    }
    else {
        bool inserted = false;
        for (auto pos = 0; pos < directory.size(); pos++) {
            if (directory.at(pos)->get_type().compare(subkey) == 0) {
                directory.at(pos)->push_front(vehicle);
                inserted = true;
            }
        }
        if (!inserted) {
            directory.push_front(new InnerLinkedList<Vehicle*>(subkey));
            directory.at(0)->push_front(vehicle);
        }
    }
}

#endif //PROJETOFINAL_MULTILISTA_SYSTEM_H
