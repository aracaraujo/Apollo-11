//
//  star.hpp
//  Lab03
//
//  Created by Ara Cantanhede Araujo on 10/6/23./Users/wadewithers/Desktop/Fall 2023/Encapsulation Design/Apollo-11/acceleration.hpp
//
#pragma once

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
    
    // Set phase.
    void setPhase(unsigned char newPhase);
    
    // Get Position.
    unsigned char  getPhase();
    
    // Increment phase;
    void incrementPhase();
    
private:
    Point position;
    
    unsigned char phase;
};
