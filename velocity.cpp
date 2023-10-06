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

// Default constructor
Velocity::Velocity() : verticalVelocity(0.0), horizontalVelocity(0.0), totalVelocity(0.0) {}

// Non-default constructor
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
double Velocity::computeVerticalVelocity(Angle angle) {
    
    // New verticalComponent variable.
    double verticalVelocity;

    // Calculate vertical component.
    verticalVelocity = cos(angle.getRadians()) * totalVelocity;

    // Returning vertical component.
    return verticalVelocity;
    
}

/************************
Compute horizontal velocity from total velocity and angle.
***********************/
double Velocity::computeHorizontalVelocity(Angle angle) {
    
    // New verticalVelocity variable.
    double horizontalVelocity;

    // Calculate vertical component.
    horizontalVelocity = sin(angle.getRadians()) * totalVelocity;

    // Returning horizontal component.
    return horizontalVelocity;
    
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
