/*************************************************************
 * File: lander.h
 * Author: Joshua Pearson
 *
 * Description: 
 *************************************************************/
#ifndef LANDER_H
#include "velocity.h"
#include "point.h"

class Lander
{
 private:
   bool aliveState;
   int fuelLevel;
   bool thrustState;
   bool landedState;

 public:
   Lander();
   Point getPoint() const;
   Velocity getVelocity() const;
   bool isAlive();
   bool isLanded();
   int getFuel();
   bool canThrust();
   void setLanded(bool);
   void setAlive(bool);
   void setFuel(int);
   void applyGravity(float);
   void applyThrustLeft();
   void applyThrustRight();
   void applyThrustBottom();
   void advance();
   void draw();
};

#endif