/*************************************************************
 * File: velocity.h
 * Author: Joshua Pearson
 *
 * Description: Velocity class
 *************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

/***************
 * Class: Velocity
 * this class determines an objects velocity
 ***************/
class Velocity
{
 private:
   float dx;
   float dy;

 public:
   Velocity();
   Velocity(const float & dx, const float & dy);
   float getDx() const { return dx; }
   float getDy() const { return dy; }
    void setDx(const float & dx) {this->dx = dx;}
    void setDy(const float & dy) {this->dy = dy;}
};

#endif
