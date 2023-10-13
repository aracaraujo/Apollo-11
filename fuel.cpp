//
//  fuel.cpp
//  Lab03
//
//  Created by Ara Cantanhede Araujo on 10/6/23.
//

#include "fuel.hpp"

/*********************************************************************
 * FUEL constructor
 * This is the default constructor of the fuel class.
 ************************************************************************/
Fuel::Fuel(){
    set(5000);
}

/*********************************************************************
 * FUEL constructor
 * This is the non-default constructor of the fuel class.
 ************************************************************************/
Fuel::Fuel(double fuel){
    set(fuel);
}

/*********************************************************************
 * SET
 * This method will set a new value for the fuel.
 ************************************************************************/
void Fuel::set(double newFuel){
    this->fuel = newFuel;
}

/*********************************************************************
 * GET
 * This method will return the value of fuel.
 ************************************************************************/
double Fuel::get(){
    return this->fuel;
}


