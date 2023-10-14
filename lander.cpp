//
//  lander.cpp
//  Lab03
//
//  Created by Wade Withers on 10/6/23.
//

#include "lander.hpp"
#include <iostream>
#define TWO_PI 6.28318530718
#define TIME 0.1
#define MASS 15103.000   // Weight of moon lander
#define GRAVITY -1.625   // Acceleration due to gravity
#define THRUST 45000.000 // Force due to thrust
#include <cmath>

/************************************************************************
 * LANDER constructor
 * Lander default constructor.
 ************************************************************************/
Lander::Lander() {
    // Setting up all the properties.
    this->position = Point(0.0, 400.0);
    this->angle = Angle();
    this->acceleration = Acceleration();
    this->velocity = Velocity();
    this->tank = Fuel();
}

/************************************************************************
 * LANDER constructor
 * Lander non-default constructor
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

Acceleration Lander::getAcceleration() {
    return acceleration;
}

Velocity Lander::getVelocity() {
    return velocity;
}

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

void Lander::setAcceleration(Acceleration acceleration) {
    this->acceleration = acceleration;
}

void Lander::setVelocity(Velocity velocity) {
    this->velocity = velocity;
}

void Lander::setAngle(Angle angle) {
    this->angle = angle;
}

void Lander::setTank(Fuel tank) {
    this->tank = tank;
}

/************************************************************************
 * UPDATE POSITION
 * This method will update the position of the rocket.
 ************************************************************************/
void updatePosition();

/************************************************************************
 * UPDATE ACCELERATION
 * This method will update the acceleration of the rocket.
 ************************************************************************/
void Lander::updateAccelerationDueThrust() {
    
    // Calculate accerleration in meters/second^2 from second law of motion.
    double newAcceleration = THRUST / MASS;
    
    acceleration.setVerticalAcceleration(acceleration.getVerticalAcceleration() + acceleration.computeVerticalAcceleration(newAcceleration,angle.getRadians()));
    
    acceleration.setHorizontalAcceleration(acceleration.getHorizontalAcceleration() + acceleration.computeHorizontalAcceleration(newAcceleration,angle.getRadians()));
    
}

void Lander::updateAccelerationDueGravity(){
    acceleration.setVerticalAcceleration(acceleration.getVerticalAcceleration() + GRAVITY);
}

void Lander::updateHorizontalAcceleration(double newAcceleration) {
    acceleration.setHorizontalAcceleration(newAcceleration);
}

void Lander::resetToGravity(){
    acceleration.setVerticalAcceleration(GRAVITY);
}

void Lander::updateVelocity() {
    
    double newVerticalVelocity = velocity.computeVerticalVelocity(acceleration.getVerticalAcceleration());
    
    double newHorizontalVelocity = velocity.computeHorizontalVelocity(acceleration.getHorizontalAcceleration());

    // Returning new velocity.
    velocity.setVerticalVelocity(newVerticalVelocity);
    
    velocity.setHorizontalVertical(newHorizontalVelocity);
}

/************************************************************************
 * BURN FUEL
 * This method will burn the fuel when the rocket rotates or when the thrust is activated.
 ************************************************************************/
void Lander::burnFuel(double fuelBurned) {
    double fuelAmount = tank.get();
    tank.set(fuelAmount - fuelBurned);
    
}

/************************************************************************
 * ROTATE LANDER
 * This method will rotate the ship by updating the angle.
 ************************************************************************/
void Lander::rotateLander(double angle) {
    if (tank.get() >= 1) {
        double currentRadians = this->angle.getRadians();
        this->angle.setRadians(currentRadians - angle);
        burnFuel(1);
    }
}

/************************************************************************
 * COMPUTE DISTANCE.
 * This method will compute the distance that the rocket moved given a speed.
 ************************************************************************/
void Lander::computeDistance() {
    
//     Calculate new position.
    double distanceX = position.getX() + (velocity.getHorizontalVelocity() * 0.1) + (0.5 * acceleration.getHorizontalAcceleration() * (0.1 * 0.1));
    double distanceY = position.getY() + (velocity.getVerticalVelocity() * 0.1) + (0.5 * acceleration.getVerticalAcceleration() * (0.1 * 0.1));
    
    std::cout << distanceX << endl;
    std::cout << distanceX << endl;
    position.setX(distanceX);
    position.setY(distanceY);

}

/************************************************************************
 * MOVE UP.
 * This method will move the rocket up.
 ************************************************************************/
void Lander::moveDown(){
    this->position.addY(-1.0);
}

/************************************************************************
 * MOVE DOWN.
 * This method will move the rocket down..
 ************************************************************************/
void Lander::moveUp(){
    if (tank.get() >= 10) {
//        this->position.addY(1.0);
        burnFuel(10);
    }
}

void Lander::setAccelerationtoGravity(){
    acceleration.setAcceleration(GRAVITY);
}
