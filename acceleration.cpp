//
//  acceleration.cpp
//  Lab03
//
//  Created by Arã Araújo on 10/5/23.
//

#include "acceleration.hpp"
#include <cmath>
#define GRAVITY -1.625


Acceleration::Acceleration(){
    setAcceleration(0.0);
    
    setVerticalAcceleration(GRAVITY);
    
    // Set horizontal accelertaion.
    setHorizontalAcceleration(0.0);
}

/*********************************************************************
 * ACCELERATION constructor
 * This is the default constructor of the acceleration class.
 ************************************************************************/
Acceleration::Acceleration(Angle angle){
    // Set acceleration.
    setAcceleration(0.0);
    
    setVerticalAcceleration(computeVerticalAcceleration(0.0,angle.getRadians()));
    
    // Set horizontal accelertaion.
    setHorizontalAcceleration(computeHorizontalAcceleration(0.0,angle.getRadians()));
}

/*********************************************************************
 * ACCELERATION constructor
 * This is a non-default constructo for the acceleration class.
 ************************************************************************/
Acceleration::Acceleration(double force, double mass, Angle angle){
    // Calculating acceleration.
    double computedAcceleration = force / mass;
    
    // Set acceleration.
    setAcceleration(computedAcceleration);
    
    setVerticalAcceleration(computeVerticalAcceleration(0.0,angle.getRadians()));
    
    // Set horizontal accelertaion.
    setHorizontalAcceleration(computeHorizontalAcceleration(0.0,angle.getRadians()));
}

/*********************************************************************
 * SET ACCELERATION
 * This is method will set a new value to acceleration.
 ************************************************************************/
void Acceleration::setAcceleration(double acceleration){
    // Set acceleration to new value.
    this->acceleration = acceleration;
}

/*********************************************************************
 * GET ACCELERATION
 * This is method will return the current value of the acceleration.
 ************************************************************************/
double Acceleration::getAcceleration(){
    // Returning acceleration.
    return this->acceleration;
}

/*********************************************************************
 * SET VERTICAL ACCELERATION
 * This method will set up the vertical component of the acceleration.
 ************************************************************************/
void Acceleration::setVerticalAcceleration(double newVerticalComponent){
    
    // Change the vertical acceleration for the new value.
    this->verticalAcceleration = newVerticalComponent;
}

/*********************************************************************
 * GET VERTICAL ACCELERATION
 * This method will return the vertical component of the acceleration.
 ************************************************************************/
double Acceleration::getVerticalAcceleration(){
    // Returning vertical acceleration component.
    return this->verticalAcceleration;
}

/*********************************************************************
 * SET HORIZONTAL ACCELERATION
 * This method will set up the horizontal component of the acceleration.
 ************************************************************************/
void Acceleration::setHorizontalAcceleration(double newHorizontalComponent){
    
    // Change the vertical acceleration for the new value.
    this->horizontalAcceleration = newHorizontalComponent;
}

/*********************************************************************
 * GET HORIZONTAL ACCELERATION
 * This method will return the horizontal component of the acceleration.
 ************************************************************************/
double Acceleration::getHorizontalAcceleration(){
    // Returning horizontal component value.
    return this->horizontalAcceleration;
}

/*********************************************************************
 * COMPUTE VERTICAL ACCELERATION
 * This method will calculate the vertical componente of the acceleration.
 ************************************************************************/
double Acceleration::computeVerticalAcceleration(double acceleration, double radians){
    
    // Vertical component.
    double vertialComponent;
    
    // Calculate vertical component.
    vertialComponent = (cos(-radians) * acceleration);
    
    // Returning vertical component.
    return vertialComponent;
}

/*********************************************************************
 * COMPUTE HORIZONTAL ACCELERATION
 * This method will calculate the horizontal componente of the acceleration.
 ************************************************************************/
double Acceleration::computeHorizontalAcceleration(double acceleration, double radians){
    
    // Vertical component.
    double horizontalComponent;
    
    // Calculate vertical component.
    horizontalComponent = sin(-radians) * acceleration;
    
    // Returning vertical component.
    return horizontalComponent;
}
