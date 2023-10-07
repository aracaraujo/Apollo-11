//
//  lander.cpp
//  Lab03
//
//  Created by Wade Withers on 10/6/23.
//

#include "lander.hpp"

// Constructors
Lander::Lander() {
    this->position = Point(0.0, 0.0);
    this->angle = Angle();
    this->acceleration = Acceleration();
    this->velocity = Velocity();
    this->tank = Fuel();
}
Lander::Lander(Point position) {
    this->position = position;
    this->angle = Angle();
    this->acceleration = Acceleration();
    this->velocity = Velocity();
    this->tank = Fuel();
}

// Getters
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

void Lander::setPosition(Point position) {
    this->position = position;
}

// Setters
void setAcceleration(Acceleration acceleration);
void setVelocity(Velocity velocity);
void Lander::setAngle(Angle angle) {
    this->angle = angle;
}
void setTank(Fuel tank);

void updatePosition();
void updateAcceleration();
void burnFuel(double fuel);
void Lander::rotateLander(double angle) {
    double currentRadians = this->angle.getRadians();
    this->angle.setRadians(currentRadians - angle);
}
double computeDistance(double positionComponent, double velocityComponent);
void Lander::moveUp(){
    this->position.addY(-1.0);
}
void Lander::moveDown(){
    this->position.addY(1.0);
}
