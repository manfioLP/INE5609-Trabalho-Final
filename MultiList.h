//
// Created by poldera_sithgod on 26/11/18.
//

#ifndef MULTILISTA_H
#define MULTILISTA_H

#include <stdexcept> // C++ exceptions

#include "Vehicle.h"
#include "strucs/ArrayList.h"
#include "strucs/LinkedList.h"
#include "strucs/InnerLinkedList.h"


template<typename T>
class MultiList {
public:
    MultiList();

    ~MultiList();

    LinkedList<T*>* searchData(std::string param, int paramType);

    T searchData(std::string param1, int param1type, std::string param2, int param2type);

    void insertVehicle(std::string plate, std::string state, std::string city, std::string builder, std::string final,
                       std::string year);

    T removeVehicle(std::string plate);

    T& getVehicleByPlate(std::string plate);

    //showAll();

private:
    bool plateAlreadyExists(std::string plate);
    void insertIntoDirectory(Vehicle *vehicle, LinkedList<InnerLinkedList<Vehicle *> *>* directory, std::string subkey);
    LinkedList<T*>* searchDataByCity(std::string param);
    LinkedList<T*>* searchDataByState(std::string param);
    LinkedList<T*>* searchDataByFinal(std::string param);
    LinkedList<T*>* searchDataByBuilder(std::string param);
    LinkedList<InnerLinkedList<Vehicle *> *> &setAuxDirectory(int paramType);

    LinkedList<InnerLinkedList<Vehicle *> *> _builderDirectory{};
    LinkedList<InnerLinkedList<Vehicle *> *> _stateDirectory{};
    LinkedList<InnerLinkedList<Vehicle *> *> _cityDirectory{};
    LinkedList<InnerLinkedList<Vehicle *> *> _finalDirectory{};
    //Vehicle _vehicles[20];
};

template<typename T>
MultiList<T>::MultiList() {
//    _builderDirectory = new LinkedList<InnerLinkedList<Vehicle *> *>; //paramType 0
//    _finalDirectory = new LinkedList<InnerLinkedList<Vehicle *> *>; //paramType 1
//    _stateDirectory = new LinkedList<InnerLinkedList<Vehicle *> *>; //paramType 2
//    _cityDirectory = new LinkedList<InnerLinkedList<Vehicle *> *>; //paramType 3
}

template<typename T>
MultiList<T>::~MultiList() {
    int pos = 0;
    while (!_stateDirectory.empty()) {
        while (!_stateDirectory.at(pos)->empty()) {
            _cityDirectory.at(pos)->pop_front();
            _stateDirectory.at(pos)->pop_front();
            _finalDirectory.at(pos)->pop_front();
            _builderDirectory.at(pos)->pop_front();
        }
        _stateDirectory.pop_front();
    }
}

template <typename T>
T& MultiList<T>::getVehicleByPlate(const std::string plate) {
    for(int pos = 0; pos < _builderDirectory.size(); pos++) {
        for(int innerpos = 0; innerpos < _builderDirectory.at(pos)->size(); innerpos++){
            Vehicle* vehicle = _builderDirectory.at(pos)->at(innerpos);
            if (vehicle->get_plate() == plate)
                return vehicle;
        }
    }
    return false;
}

template<typename T>
void MultiList<T>::insertVehicle(const std::string plate, const std::string state, std::string city, std::string builder,
                                 std::string final, std::string year) {
    if(plateAlreadyExists(plate))
        throw std::invalid_argument("This plate already exists on the system!");

    Vehicle *vehicle = new Vehicle(plate, state, city, builder, final, year);

    insertIntoDirectory(vehicle, &_builderDirectory, vehicle->get_builder());
    insertIntoDirectory(vehicle, &_stateDirectory, vehicle->get_state());
    insertIntoDirectory(vehicle, &_finalDirectory, vehicle->get_final());
    insertIntoDirectory(vehicle, &_cityDirectory, vehicle->get_city());
}

template <typename T>
bool MultiList<T>::plateAlreadyExists(std::string plate) {
    for(int pos = 0; pos < _builderDirectory.size(); pos++) {
        for(int innerpos = 0; innerpos < _builderDirectory.at(pos)->size(); innerpos++){
            if (_builderDirectory.at(pos)->at(innerpos)->get_plate() == plate)
                return true;
        }
    }
    return false;
}

template<typename T>
void MultiList<T>::insertIntoDirectory(Vehicle *vehicle, LinkedList<InnerLinkedList<Vehicle *> *>* directory,
                                       const std::string subkey) {
    if (directory->empty()) {
        directory->push_back(new InnerLinkedList<Vehicle *>(subkey));
        directory->at(0)->push_front(vehicle);
    } else {
        bool inserted = false;
        for (auto pos = 0; pos < directory->size(); pos++) {
            if (directory->at(pos)->get_type() == subkey) {
                directory->at(pos)->push_front(vehicle);
                inserted = true;
            }
        }
        if (!inserted) {
            directory->push_front(new InnerLinkedList<Vehicle *>(subkey));
            directory->at(0)->push_front(vehicle);
        }
    }
}

template<typename T>
T MultiList<T>::removeVehicle(const std::string plate) {
    T removedVehicle;
    bool removed = false;
    for (int pos = 0; pos < _stateDirectory.size(); pos++) {
        for (int innerpos = 0; innerpos < _stateDirectory.at(pos)->size(); innerpos++) {
            Vehicle v = _stateDirectory.at(pos)->at(innerpos);
            if (v.get_plate() == plate) {
                _stateDirectory.at(pos)->remove(&v);
                removedVehicle = v;
                removed = true;
            }
        }
    }
    if (removed)
        return removedVehicle;
    throw std::out_of_range("This vehicle plate isn't on the system");
}

template<typename T>
LinkedList<T*>* MultiList<T>::searchData(const std::string param, int paramType) {
    switch (paramType) {
        case 0:
            return searchDataByBuilder(param);
        case 1:
            return searchDataByFinal(param);
        case 2:
            return searchDataByState(param);
        case 3:
            return searchDataByCity(param);
    }
}

template<typename T>
LinkedList<T*>* MultiList<T>::searchDataByBuilder(std::string param) {
    for (int pos = 0; pos < _builderDirectory.size(); pos++) {
        if (_builderDirectory.at(pos)->at(0)->get_builder() == param)
            return _builderDirectory.at(pos);
    }
}

template<typename T>
LinkedList<T*>* MultiList<T>::searchDataByState(std::string param) {
    for (int pos = 0; pos < _stateDirectory.size(); pos++) {
        if (_stateDirectory.at(pos)->at(0)->get_builder() == param)
            return _stateDirectory.at(pos);
    }
}

template<typename T>
LinkedList<T*>* MultiList<T>::searchDataByCity(std::string param) {
    for (int pos = 0; pos < _cityDirectory.size(); pos++) {
        if (_cityDirectory.at(pos)->at(0)->get_builder() == param)
            return _cityDirectory.at(pos);
    }
}

template<typename T>
LinkedList<T*>* MultiList<T>::searchDataByFinal(std::string param) {
    for (int pos = 0; pos < _finalDirectory.size(); pos++) {
        if (_finalDirectory.at(pos)->at(0)->get_builder() == param)
            return _finalDirectory.at(pos);
    }
}

template<typename T>
T MultiList<T>::searchData(const std::string param1, int param1type, const std::string param2, int param2type) {
    LinkedList<InnerLinkedList<Vehicle *> *> *dir1 = setAuxDirectory(param1type);
    LinkedList<InnerLinkedList<Vehicle *> *> *dir2 = setAuxDirectory(param2type);

    InnerLinkedList<Vehicle *> *subdir1;
    InnerLinkedList<Vehicle *> *subdir2;

    LinkedList<Vehicle*>* vehiclesMatched = new LinkedList<Vehicle*>;

    // set subdirectories
    for(int pos = 0; pos < dir1->size(); pos++) {
        if (dir1->at(pos)->get_type() == param1)
            subdir1 = dir1->at(pos);
        if (dir2->at(pos)->get_type() == param2)
            subdir2 = dir2->at(pos);
    }

    //compare subdirectories
    if (subdir1->size() <= subdir2->size()) {
        for (int pos = 0; pos < subdir1->size(); pos++) {
            for (int pos2 = 0; pos2 < subdir2->size(); pos2++) {
                if (subdir1->at(pos) == subdir2->at(pos2)) //comparação esta correta? tem que comparar endereço de memória
                    vehiclesMatched->push_front(subdir1->at(pos));
            }
        }
    } else {
        for (int pos = 0; pos < subdir2->size(); pos++) {
            for (int pos2 = 0; pos2 < subdir1->size(); pos2++) {
                if (subdir2->at(pos) == subdir1->at(pos2)) //comparação esta correta? tem que comparar endereço de memória
                    vehiclesMatched->push_front(subdir2->at(pos));
            }
        }
    }

    return vehiclesMatched;
}

template<typename T>
LinkedList<InnerLinkedList<Vehicle *> *> &MultiList<T>::setAuxDirectory(int paramType) {
    switch (paramType) {
        case 0:
            return &_builderDirectory;
        case 1:
            return &_finalDirectory;
        case 2:
            return &_stateDirectory;
        case 3:
            return &_cityDirectory;
    }
}

template <typename T>
T getParamDataValue(LinkedList<InnerLinkedList<Vehicle *>*>* directory, int position, int paramType) {
    switch (paramType) {
        case 0:
            return directory->at(position)->at(0)->get_builder();
        case 1:
            return directory->at(position)->at(0)->get_final();
        case 2:
            return directory->at(position)->at(0)->get_state();
        case 3:
            return directory->at(position)->at(0)->get_city();
    }
}

#endif //MULTILISTA_H
