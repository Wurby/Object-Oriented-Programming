/*************************************************************
 * File: flyingobject.h
 * Author: Joshua Pearson
 *
 * Description: flying object class
 *************************************************************/

#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class FlyingObject
{
protected:
  Point position;
  Velocity velocity;
  bool alive;
    
public:
    
 
  void kill();
  void advance();
  virtual void draw() = 0;
  Point getPoint() const
    {
        return position;
    }
    Velocity getVelocity() const
    {
        return velocity;
    }
    bool isAlive() const
    {
        return alive;
    }
    
    //setters
    void setPoint(const Point & point)
    {
        position = point;
    }
    void setVelocity(const Velocity & velocity)
    {
        this->velocity = velocity;
    }
    void setAlive(const bool & alive)
    {
        this->alive = alive;
    }
};
#endif
