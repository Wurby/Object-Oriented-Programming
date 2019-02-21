/*************************************************************
 * File: velocity.h
 * Author: Joshua Pearson
 *
 * Description: 
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
  Velocity(const float &, const float &);
  float getDx() const { return dx; }
  float getDy() const { return dy; }
  void setDx(const float &) {}
  void setDy(const float &) {}
};

#endif