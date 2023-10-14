//
//  velocity.hpp
//  Lab03
//
//  Created by Wade Withers on 10/6/23.
//
#pragma once

#ifndef velocity_hpp
#define velocity_hpp

#include <stdio.h>
#include <cmath>
#include "acceleration.hpp"
#include "angle.h"

#endif /* velocity_hpp */

/************************
 The Velocity Class
 ************************/
class Velocity {
private:
    
    // Velocity variables
    double verticalVelocity;
    double horizontalVelocity;
    double totalVelocity;
    
    // Compute new velocity from an acceleration.
    double computeVelocityFromAcceleration(Acceleration acceleration, double time=1/10);

    
public:
    
    // Constructors
    Velocity();
    Velocity(double verticalVelocity, double horizontalVelocity, double totalVelocity);
    
    // Setters
    void setVerticalVelocity(double verticalVelocity);
    void setHorizontalVertical(double verticalHorizontal);
    void setTotalVelocity(double totalVelocity);
    
    // Getters
    double getVerticalVelocity() const;
    double getHorizontalVelocity() const;
    double getTotalVelocity() const;
    
    // Compute the vertical component of the velocity.
    double computeVerticalVelocity(double verticalAcceleration);
    
    // Compute the horizontal component of the velocity
    double computeHorizontalVelocity(double horizontalAcceleration);
    
};
