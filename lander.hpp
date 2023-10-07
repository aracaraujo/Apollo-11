//
//  lander.hpp
//  Lab03
//
//  Created by Wade Withers on 10/6/23.
//
#pragma once

#ifndef lander_hpp
#define lander_hpp

#include <stdio.h>
#include "point.h"
#include "acceleration.hpp"
#include "velocity.hpp"
#include "angle.h"
#include "fuel.hpp"

#endif /* lander_hpp */

class Lander {
private:
    Point position;
    Acceleration acceleration;
    Velocity velocity;
    Angle angle;
    Fuel tank;
    
public:
    // Constructors
    Lander();
    Lander(Point position);
    
    // Getters.
    Point getPosition();
    Acceleration getAcceleration();
    Velocity getVelocity();
    Angle getAngle();
    Fuel getTank();
    
    // Setters
    void setPosition(Point point);
    void setAcceleration(Acceleration acceleration);
    void setVelocity(Velocity velocity);
    void setAngle(Angle angle);
    void setTank(Fuel tank);
    
    // Update the rocket position.
    void updatePosition();
    
    // Move rocket up.
    void moveUp();
    
    // Move rocket down.
    void moveDown();
    
    // Update rocket acceleration.
    void updateAcceleration();
    
    // Burn the fuel when rocket rotates or moves.
    void burnFuel(double fuel);
    
    // Rotate the rocket by updating the angle.
    void rotateLander(double angle);
    
    // Compute distance that the rocket moved.
    double computeDistance(double positionComponent, double velocityComponent);
    
};
