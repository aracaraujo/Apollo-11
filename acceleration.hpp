//
//  acceleration.hpp
//  Lab03
//
//  Created by Arã Araújo on 10/5/23.
//
#pragma once

#ifndef acceleration_hpp
#define acceleration_hpp

#include <stdio.h>
#include "angle.h"

#endif /* acceleration_hpp */

/***********************************************************
 * ACCELERATION
 * The acceleration class
 ***********************************************************/
class Acceleration
{
public:
    Acceleration();
    // Default constructor.
    Acceleration(Angle angle);
    
    // Non-default constructor.
    Acceleration(double force, double mass, Angle angle);
    
    // Set acceleration.
    void setAcceleration(double acceleration);
    
    // Get acceleration.
    double getAcceleration();
    
    // Set vertical acceleration.
    void setVerticalAcceleration(Angle angle);
    
    // Get vertical acceleration.
    double getVerticalAcceleration();
    
    // Set horizontal acceleration.
    void setHorizontalAcceleration(Angle angle);
    
    // Get horizontal acceleration.
    double getHorizontalAcceleration();
    
    // Update acceleration due thrust.
    void updateAccelerationDueThrust();
    
private:
    // Computer vertical componente of the acceleration.
    /*
     This is different then the design because I'm not passing the
     acceleration. We will use the acceleration itself.
     */
    double computeVerticalAcceleration(double radians);
    
    // Compute horizontal componente of the acceleration.
    /*
     This is different then the design because I'm not passing the
     acceleration. We will use the acceleration itself.
     */
    double computeHorizontalAcceleration(double radians);
    
    // This is the total acceleration.
    double acceleration;
    
    // This is the vertical component of the acceleration.
    double verticalAcceleration;
    
    // This is the horizontal component of the acceleration.
    double horizontalAcceleration;
};
