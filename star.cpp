//
//  star.cpp
//  Lab03
//
//  Created by Ara Cantanhede Araujo on 10/6/23.
//
#pragma once

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

// Set phase.
void Star::setPhase(unsigned char newPhase){
    this->phase = newPhase;
}

// Get Position.
unsigned char Star::getPhase(){
    return this->phase;
}

void Star::incrementPhase(){
    this->phase = getPhase() + 1;
}

