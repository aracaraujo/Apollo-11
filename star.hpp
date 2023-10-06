//
//  star.hpp
//  Lab03
//
//  Created by Ara Cantanhede Araujo on 10/6/23.
//

#ifndef star_hpp
#define star_hpp

#include <stdio.h>
#include "point.h"

#endif /* star_hpp */

class Star
{
public:
    // Default constructor.
    Star();
    
    // Non-default constructor.
    Star(Point position, int phase);
    
    // Set position.
    void setPosition(Point position);
    
    // Get Position.
    Point getPosition();
    
    // Set width.
    void setWidth(int newWidth);
    
    // Get width.
    int getWidth();
    
    // Set phase.
    void setPhase(int newPhase);
    
    // Get Position.
    unsigned char  getPhase();
    
private:
    Point position;
    
    int width = 5;
    
     unsigned char phase;
};
