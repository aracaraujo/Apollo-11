/*************************************************************
 * 1. Name:
 *      Wade Withers and Ara Araujo
 * 2. Assignment Name:
 *      Practice 03: Angle Class
 * 3. Assignment Description:
 *      A class to represent an angle
 * 4. What was the hardest part? Be as specific as possible.
 *      Creating the copy constructor correctly. 
 * 5. How long did it take for you to complete the assignment?
 *      30 minutes
 **************************************************************/

#pragma once

#define TWO_PI 6.28318530718

#include <math.h>   // for floor()
#include <iostream> // for cout
#include <cassert>  // for assert()
using namespace std;

class TestAngle;

/************************************
 * ANGLE
 ************************************/
class Angle
{
    
   friend TestAngle;

private:

    // Angle in radians.
    double radians;

    /************************************
     Take an angle in radians and normalize it so its between
     0 and 2pi.
     ************************************/
    double normalize(double radians) const
    {

        // Find modulo of radians.
        double normalizedRadians = fmod(radians, TWO_PI);
      
        // Add 2pi to radians if under 0.
        if (normalizedRadians < 0) {
            return normalizedRadians + TWO_PI;
        }
        
        return normalizedRadians;
    }

    /************************************
     Take an angle in degrees and normalize it so its between 0
     and 360.
     ************************************/
    double normalizeDegrees(double degrees) const
    {

        // Normalize the angle so its between 0 and 360 degrees.
        double normalizedDegrees = fmod(degrees, 360);

        // Add 360 to angle if it is less than 0.
        if (normalizedDegrees < 0) {
            return normalizedDegrees + 360;
        }

        return normalizedDegrees;
    }

    /************************************
     Take angle in radians and convert it to degrees.
     ************************************/
    double convertToDegrees(double radians) const
    {

        // Normalize radians if not between 0 and 2pi.
        if (radians > TWO_PI || radians < 0)
        {
            radians = normalize(radians);
        }
      
        // Radians to degrees.
        double degrees = (radians * 180) / M_PI;
       
        return degrees;
    }

    /************************************
     Take angle in degrees and convert to radians.
     ************************************/
    double convertToRadians(double degrees) const
    {

        // Normalize degrees if not between 0 and 360.
        if (degrees > 360 || degrees < 0)
        {
            degrees = normalizeDegrees(degrees);
        }

        // Converting degrees to radians.
        double radians = ((degrees / 360) * (TWO_PI));

        return radians;
    }

public:
    
    /************************************
     Default Constructor
     ************************************/
    Angle() {
        this->radians = 0.0;
    }
    
    /************************************
     Non-default Constructor
     ************************************/
    Angle(double degrees) {
        this->radians = convertToRadians(degrees);
    }
    
    /************************************
     Copy Constructor
     ************************************/
    Angle(const Angle & rhs) {
        this->radians = rhs.radians;
    }
    
    /************************************
     Get angle in degrees.
     ************************************/
    double getDegrees() const
    {

        // Convert radians to degrees.
        return convertToDegrees(radians);
    }

    /************************************
     Get angle in radians.
     ************************************/
    double getRadians() const
    {
        // Return angle in radians.
        return radians;
    }

    /************************************
     Set attribute to new angle in degrees.
     ************************************/
    void setDegrees(double degrees)
    {

        // Normalize degrees if not between 0 and 360.
        if (degrees > 360 || degrees < 0)
        {
            degrees = normalizeDegrees(degrees);
        }

        // Set radians attribute to new angle in degrees.
        this->radians = convertToRadians(degrees);
    }

    /************************************
     Set attribute to new angle in radians.
     ************************************/
    void setRadians(double newRadians)
    {

      // Normalize radians if not between 0 to 2pi.
      if (newRadians > TWO_PI || newRadians < 0)
      {
          newRadians = normalize(newRadians);
      }

      // Set radians attribute to new radians angle.
      this->radians = newRadians;
    }

    /************************************
     Display angle in degrees to 1 decimal place.
     ************************************/
    void display(ostream &out) const
    {
        out.setf(ios::fixed);     // "fixed" means don't use scientific notation
        out.setf(ios::showpoint); // "showpoint" means always show the decimal point
        out.precision(1);         // Set the precision to 1 decimal place of accuracy.

        // Display angle in degrees.
        out << convertToDegrees(radians) << "degrees";
    }
};

