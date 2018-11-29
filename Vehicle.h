//
// Created by poldera_sithgod on 26/11/18.
//

#ifndef PROJETOFINAL_MULTILISTA_VEHICLE_H
#define PROJETOFINAL_MULTILISTA_VEHICLE_H

#include <string>

class Vehicle {
public:
    Vehicle(std::string plate, std::string state, std::string city, std::string builder, std::string final, std::string year);

    const std::string &get_builder() const;

    void set_builder(const std::string &_builder);

    const std::string &get_plate() const;

    void set_plate(const std::string &_plate);

    const std::string &get_state() const;

    void set_state(const std::string &_state);

    const std::string &get_final() const;

    void set_final(const std::string &_final);

    const std::string &get_city() const;

    void set_city(const std::string &_city);

    const std::string &get_year() const;

    void set_year(const std::string &_year);

    ~Vehicle();

    std::string builder();
    std::string plate();
    std::string state();
    std::string city();
    int final();

private:
    std::string _builder;
    std::string _plate;
    std::string _state;
    std::string _final;
    std::string _city;
    std::string _year;
};

Vehicle::Vehicle(std::string plate, std::string state, std::string city, std::string builder, std::string final, std::string year):
        _city{city},
        _year{year},
        _plate{plate},
        _final{final},
        _state{state},
        _builder{builder},
{}

const std::string &Vehicle::get_builder() const {
    return _builder;
}

void Vehicle::set_builder(const std::string &_builder) {
    Vehicle::_builder = _builder;
}

const std::string &Vehicle::get_plate() const {
    return _plate;
}

void Vehicle::set_plate(const std::string &_plate) {
    Vehicle::_plate = _plate;
}

const std::string &Vehicle::get_state() const {
    return _state;
}

void Vehicle::set_state(const std::string &_state) {
    Vehicle::_state = _state;
}

const std::string &Vehicle::get_final() const {
    return _final;
}

void Vehicle::set_final(const std::string &_final) {
    Vehicle::_final = _final;
}

const std::string &Vehicle::get_city() const {
    return _city;
}

void Vehicle::set_city(const std::string &_city) {
    Vehicle::_city = _city;
}

const std::string &Vehicle::get_year() const {
    return _year;
}

void Vehicle::set_year(const std::string &_year) {
    Vehicle::_year = _year;
}

#endif //PROJETOFINAL_MULTILISTA_VEHICLE_H
