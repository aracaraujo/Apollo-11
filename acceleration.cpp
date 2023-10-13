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
    setAcceleration(GRAVITY, Angle(0.0));
    setVerticalAcceleration(Angle());
    
    // Set horizontal accelertaion.
    setHorizontalAcceleration(Angle());
}

/*********************************************************************
 * ACCELERATION constructor
 * This is the default constructor of the acceleration class.
 ************************************************************************/
Acceleration::Acceleration(Angle angle){
    // Set acceleration.
    setAcceleration(GRAVITY, angle);
    
    // Set vertical acceleration.
    setVerticalAcceleration(angle);
    
    // Set horizontal accelertaion.
    setHorizontalAcceleration(angle);
}

/*********************************************************************
 * ACCELERATION constructor
 * This is a non-default constructo for the acceleration class.
 ************************************************************************/
Acceleration::Acceleration(double force, double mass, Angle angle){
    // Calculating acceleration.
    double computedAcceleration = force / mass;
    
    // Set acceleration.
    setAcceleration(computedAcceleration, angle);
    
    // Set vertical acceleration.
    setVerticalAcceleration(angle);
    
    // Set horizontal accelertaion.
    setHorizontalAcceleration(angle);
}

/*********************************************************************
 * SET ACCELERATION
 * This is method will set a new value to acceleration.
 ************************************************************************/
void Acceleration::setAcceleration(double acceleration, Angle angle){
    // Set acceleration to new value.
    this->acceleration = acceleration;
    this->setVerticalAcceleration(angle);
    this->setVerticalAcceleration(angle);
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
void Acceleration::setVerticalAcceleration(Angle angle){
    // Set vertical componente value.
    double verticalComponent;
    
    // Calculating vertical acceleration.
    verticalComponent = computeVerticalAcceleration(angle.getRadians());
    
    // Change the vertical acceleration for the new value.
    this->verticalAcceleration = verticalComponent;
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
void Acceleration::setHorizontalAcceleration(Angle angle){
    // Set horizontal component value.
    double horizontalComponent;
    
    // Calculating vertical acceleration.
    horizontalComponent = computeHorizontalAcceleration(angle.getRadians());
    
    // Change the vertical acceleration for the new value.
    this->horizontalAcceleration = horizontalComponent;
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
 * UPDATE ACCELERATION DUE THRUST
 * This method will update the acceleration when the thrust is activated.
 ************************************************************************/
void Acceleration::updateAccelerationDueThrust(){
    
}

/*********************************************************************
 * COMPUTE VERTICAL ACCELERATION
 * This method will calculate the vertical componente of the acceleration.
 ************************************************************************/
double Acceleration::computeVerticalAcceleration(double radians){
    
    // Vertical component.
    double vertialComponent;
    
    // Calculate vertical component.
    vertialComponent = cos(radians) * this->acceleration;
    
    // Returning vertical component.
    return vertialComponent;
}

/*********************************************************************
 * COMPUTE HORIZONTAL ACCELERATION
 * This method will calculate the horizontal componente of the acceleration.
 ************************************************************************/
double Acceleration::computeHorizontalAcceleration(double radians){
    
    // Vertical component.
    double horizontalComponent;
    
    // Calculate vertical component.
    horizontalComponent = sin(radians) * this->acceleration;
    
    // Returning vertical component.
    return horizontalComponent;
}
