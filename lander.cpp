//
//  lander.cpp
//  Lab03
//
//  Created by Wade Withers on 10/6/23.
//

#include "lander.hpp"
#define TWO_PI 6.28318530718
#include <cmath>

/************************************************************************
 * GROUND constructor
 * Ground default constructor.
 ************************************************************************/
Lander::Lander() {
    // Setting up all the properties.
    this->position = Point(0.0, 0.0);
    this->angle = Angle();
    this->acceleration = Acceleration();
    this->velocity = Velocity();
    this->tank = Fuel();
}

/************************************************************************
 * GROUND constructor
 * Ground non-default constructor
 ************************************************************************/
Lander::Lander(Point position) {
    // Setting up all the properties.
    this->position = position;
    this->angle = Angle(0.0);
    this->acceleration = Acceleration();
    this->velocity = Velocity();
    this->tank = Fuel();
}

/************************************************************************
 * Getters
 * The following methods are the getters for all the properties.
 ************************************************************************/
Point Lander::getPosition() {
    return position;
}
Acceleration getAcceleration();
Velocity getVelocity();
Angle Lander::getAngle() {
    return angle;
}

Fuel Lander::getTank() {
    return tank;
}

/************************************************************************
 * Setters
 * The following methods are the getters for all the properties.
 ************************************************************************/
void Lander::setPosition(Point position) {
    this->position = position;
}

void setAcceleration(Acceleration acceleration);
void setVelocity(Velocity velocity);
void Lander::setAngle(Angle angle) {
    this->angle = angle;
}
void setTank(Fuel tank);

/************************************************************************
 * UPDATE POSITION
 * This method will update the position of the rocket.
 ************************************************************************/
void updatePosition();

/************************************************************************
 * UPDATE ACCELERATION
 * This method will update the acceleration of the rocket.
 ************************************************************************/
void updateAcceleration();

/************************************************************************
 * BURN FUEL
 * This method will burn the fuel when the rocket rotates or when the thrust is activated.
 ************************************************************************/
void burnFuel(double fuel);

/************************************************************************
 * ROTATE LANDER
 * This method will rotate the ship by updating the angle.
 ************************************************************************/
void Lander::rotateLander(double angle) {
    double currentRadians = this->angle.getRadians();
    this->angle.setRadians(currentRadians - angle);
}

/************************************************************************
 * COMPUTE DISTANCE.
 * This method will compute the distance that the rocket moved given a speed.
 ************************************************************************/
double computeDistance(double positionComponent, double velocityComponent);

/************************************************************************
 * MOVE UP.
 * This method will move the rocket up.
 ************************************************************************/
void Lander::moveUp(){
    this->position.addY(-1.0);
}

/************************************************************************
 * MOVE DOWN.
 * This method will move the rocket down..
 ************************************************************************/
void Lander::moveDown(){
    this->position.addY(1.0);
}
