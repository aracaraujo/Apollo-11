//
//  velocity.hpp
//  Lab03
//
//  Created by Wade Withers on 10/6/23.
//

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
    
    double computeVelocityFromAcceleration(Acceleration acceleration, double time=1/10);
    double computeVerticalVelocity(Angle angle);
    double computeHorizontalVelocity(Angle angle);
    
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
    
};
