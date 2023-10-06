//
//  star.cpp
//  Lab03
//
//  Created by Ara Cantanhede Araujo on 10/6/23.
//

#include "star.hpp"
#include "point.h"


Star::Star(){
    this->position = Point(0.0,0.0);
}

// Non-default constructor.
Star::Star(Point position, int phase){
    this->position = position;
    this->phase = phase;
}

// Set position.
void Star::setPosition(Point newPosition){
    this->position = newPosition;
}

// Get Position.
Point Star::getPosition(){
    return this->position;
}

// Set width.
void Star::setWidth(int newWidth){
    this->width = newWidth;
}

// Get width.
int Star::getWidth(){
    return this->width;
}

// Set phase.
void Star::setPhase(int newPhase){
    this->phase = newPhase;
}

// Get Position.
int Star::getPhase(){
    return this->phase;
}



