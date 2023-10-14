//
//  velocity.cpp
//  Lab03
//
//  Created by Wade Withers on 10/6/23.
//

#include "velocity.hpp"
#include "acceleration.hpp"
#include "angle.h"

#include <cmath> // For cos and sin functions.

#define TIME = 0.1 // Time interval.

/************************************************************************
 * VELOCITY  constructor
 * Create a new velocity object.
 ************************************************************************/
Velocity::Velocity() : verticalVelocity(0.0), horizontalVelocity(0.0), totalVelocity(0.0) {}

/************************************************************************
 * VELOCITY  constructor
 * Non-default constructor.
 ************************************************************************/
Velocity::Velocity(double verticalVelocity, double horizontalVelocity, double totalVelocity) {
    this->verticalVelocity = verticalVelocity;
    this->horizontalVelocity = horizontalVelocity;
    this->totalVelocity = totalVelocity;
}

/************************
Compute velocity due to acceleration.
************************/
double Velocity::computeVelocityFromAcceleration(Acceleration acceleration, double time) {
    
    // New velocite variable.
    double newVelocity;

    // Calculating new velocite according to acceleration applied.
    newVelocity = totalVelocity + (acceleration.getAcceleration() * time);

    // Returning new velocity.
    return newVelocity;
    
}

/************************
Compute vertical velocity from total velocity and angle.
***********************/
double Velocity::computeVerticalVelocity(double verticalAcceleration) {
    

    // Calculate vertical component.
    double newVerticalVelocity = verticalVelocity + (verticalAcceleration * 0.1);

    // Returning vertical component.
    return newVerticalVelocity;
    
}

/************************
Compute horizontal velocity from total velocity and angle.
***********************/
double Velocity::computeHorizontalVelocity(double horizontalAcceleration) {

    // Calculate vertical component.
    double newHorizontalVelocity = horizontalVelocity + (horizontalAcceleration * 0.1);

    // Returning horizontal component.
    return newHorizontalVelocity;
    
}

double Velocity::computeTotalVelocity() {
    
    // Calculate total velocity using pythagorean theorem.
    // Must be a positive number or will return a domain error.
    double totalVelocity = sqrt((horizontalVelocity * horizontalVelocity) + (verticalVelocity * verticalVelocity));

    // returning total component
    return totalVelocity;
}

// Setters
void Velocity::setVerticalVelocity(double verticalVelocity) {
    this->verticalVelocity = verticalVelocity;
}

void Velocity::setHorizontalVertical(double horizontalVelocity) {
    this->horizontalVelocity = horizontalVelocity;
}

void Velocity::setTotalVelocity(double totalVelocity) {
    this->totalVelocity = totalVelocity;
}


// Getters
double Velocity::getVerticalVelocity() const {
    return verticalVelocity;
}

double Velocity::getHorizontalVelocity() const {
    return horizontalVelocity;
}

double Velocity::getTotalVelocity() const {
    return totalVelocity;
}
