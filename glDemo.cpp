/*************************************************************
 * 1. Name:
 *      Ara Araujo and Wade Withers
 * 2. Assignment Name:
 *      Lab 04: Apollo 11 Visuals
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      Building the lander and making sure all parts were correctly connected.
 * 5. How long did it take for you to complete the assignment?
 *      3 hours.
 *****************************************************************/

/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "angle.h"
#include "lander.hpp"
#include "star.hpp"
#include <vector>

#define MASS 15103.000   // Weight of moon lander
#define GRAVITY -1.625   // Acceleration due to gravity
#define THRUST 45000.000 // Force due to thrust
#define TIME 0.1

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(const Point& ptUpperRight) :
          angle(Angle()),
          ptStar(ptUpperRight.getX() - 20.0, ptUpperRight.getY() - 20.0),
          ptLM(random(20,380), ptUpperRight.getY() - 10),
          ground(ptUpperRight), lander(ptLM), stars(createStars())
   {

      phase = random(0, 255);
   }
    
    // This function will return a vector that contains 50 stars.
    vector<Star> createStars(){
        vector<Star> stars;
        
        while(stars.size() < 50){
            Point position = Point(random(10,390),random(10,390));
            // Checking that the position is not on the ground.
            if (!ground.hitGround(position, 1)){
                unsigned char phase = random(0,255);
                Star star = Star(position,phase);
                stars.push_back(star);
            }
        }
        return stars;
    }
    
   /*************************************
      Function to check if lander has landed. If lander hit lander pad
      at less than 4 m/s then the lander has successfully landed.
   *************************************/
   bool isLanded() {
       
       if (ground.onPlatform(lander.getPosition(), 20) && lander.getTotalVelocity() <= 4) {
           return true;
       }
       
       return false;
       
   }

   // this is just for test purposes.  Don't make member variables public!
   Point ptLM;           // location of the LM on the screen
   Point ptUpperRight;   // size of the screen
   Angle angle;         // angle the LM is pointing
   unsigned char phase;  // phase of the star's blinking
   Ground ground;
   Point ptStar;
   Lander lander;
   vector<Star> stars;

};
/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void * p)
{
    
   ogstream gout;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL.
   Demo * pDemo = (Demo *)p;
    
    pDemo->lander.updateHorizontalAcceleration(0.0);
    if (!pDemo->ground.hitGround(pDemo->lander.getPosition(), 20)) {
        if (pDemo->lander.getAcceleration().getVerticalAcceleration() > 0){
            pDemo->lander.updateAccelerationDueGravity();
        }else{
            pDemo->lander.resetToGravity();
        }
        
        // move the ship around
        if (pUI->isRight()){
            pDemo->lander.rotateLander(0.1);
        }
        if (pUI->isLeft()){
            pDemo->lander.rotateLander(-0.1);
        }
        if (pUI->isUp())
            pDemo->lander.moveDown();
        if (pUI->isDown()) {
            pDemo->lander.updateAccelerationDueThrust();
        }
    
        // Update lander's speed and position.
        pDemo->lander.updateVelocity();
        pDemo->lander.computeDistance();
    }
    else if (pDemo->isLanded()){
        gout.setPosition(Point(200.0, 200.0));
        gout << "The ship has landed!\n";
    
    }
    else {
        gout.setPosition(Point(200.0, 200.0));
        gout << "The ship has Crashed!\n";
    }
    
        
    

   // draw the ground
   pDemo->ground.draw(gout);
    
   // draw the lander and its flames
   gout.drawLander(pDemo->lander.getPosition() /*position*/, pDemo->lander.getAngle().getRadians() /*angle*/);
   if (pDemo->lander.getTank().get() > 0) {
        gout.drawLanderFlames(pDemo->lander.getPosition(), pDemo->lander.getAngle().getRadians(), /*angle*/
                              pUI->isDown(), pUI->isLeft(), pUI->isRight());
   }

   // Display fuel on screen.
   gout.setPosition(Point(20.0, 370.0));
   gout << "Fuel: " << pDemo->lander.getTank().get() << " lbs" << "\n";
    
   // Dispaly Altitude on screen.
   gout.setPosition(Point(20.0, 350.0));
   gout << "Altitude: " << pDemo->lander.getPosition().getY() << " meters" << "\n";
    
   // Display Speed on screen.
   gout.setPosition(Point(20.0, 330.0));
   gout << "Speed: " << pDemo->lander.getTotalVelocity() << " m/s" << "\n";
    
    /*gout.setPosition(Point(20.0, 200));
    gout << "Vertical Acceleration: "<< pDemo->lander.getAcceleration().getVerticalAcceleration() << "\n";
    gout.setPosition(Point(20.0, 175));
    gout <<"Horizontal Acceleration: "<< pDemo->lander.getAcceleration().getHorizontalAcceleration() << "\n";
    gout.setPosition(Point(20.0, 150));
    gout << "Vertical Velocity: "<< pDemo->lander.getVelocity().getVerticalVelocity() << "\n";
    gout.setPosition(Point(20.0, 125));
    gout << "Horizontal Velocity: "<< pDemo->lander.getVelocity().getHorizontalVelocity() << "\n";*/

//    gout.setPosition(Point(20.0, 100));
//    gout << pDemo->lander.getVelocity().getTotalVelocity() << "\n";
    // Draw the stars in the sky.
    for (auto &star : pDemo->stars){
        star.incrementPhase();
        gout.drawStar(star.getPosition(), star.getPhase());
    }

}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char ** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Point ptUpperRight(400.0, 400.0);
   Interface ui(0, NULL,
                "Open GL Demo",
                 ptUpperRight);

   // Initialize the game class
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);

   return 0;
}
