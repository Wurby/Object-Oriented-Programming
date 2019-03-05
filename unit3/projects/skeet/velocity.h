/*************************************************************
 * File: velocity.h
 * Author: Joshua Pearson
 *
 * Description: Velocity class
 *************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
 private:
   float dx;
   float dy;

 public:
   Velocity();
   Velocity(float, float);
   float getDx() const { return dx; }
   float getDy() const { return dy; }
   void setDx(float) {}
   void setDy(float) {}
};

#endif