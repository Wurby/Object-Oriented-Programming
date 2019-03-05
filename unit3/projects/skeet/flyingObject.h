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

class FlyingObject
{
private:
public:
  Point position;
  Velocity velocity;
  bool isAlive();
  void kill();
  void advance();
  Point getPoint();
};
#endif