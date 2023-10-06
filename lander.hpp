//
//  lander.hpp
//  Lab03
//
//  Created by Wade Withers on 10/6/23.
//

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
    
    Point getPosition();
    Acceleration getAcceleration();
    Velocity getVelocity();
    Angle getAngle();
    Fuel getTank();
    
    void setPosition(Point point);
    void setAcceleration(Acceleration acceleration);
    void setVelocity(Velocity velocity);
    void setAngle(Angle angle);
    void setTank(Fuel tank);
    
    void updatePosition();
    void moveUp();
    void moveDown();
    void updateAcceleration();
    void burnFuel(double fuel);
    void rotateLander(double angle);
    double computeDistance(double positionComponent, double velocityComponent);
    
};
