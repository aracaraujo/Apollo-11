//
//  fuel.hpp
//  Lab03
//
//  Created by Ara Cantanhede Araujo on 10/6/23.
//

#ifndef fuel_hpp
#define fuel_hpp

#include <stdio.h>

#endif /* fuel_hpp */

class Fuel
{
public:
    // Default constructor.
    Fuel();
    
    // Non-default constructor.
    Fuel(double fuel);
    
    // Set fuel.
    void set(double newFuel);
    
    // Get fuel.
    double get();
    
private:
    double fuel;
};
