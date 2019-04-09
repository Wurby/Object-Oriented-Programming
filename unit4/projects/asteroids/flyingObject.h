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

// TODO: Rotation should not be in flyingObject, as it only applies to the rocks and ship.

class FlyingObject
{
 protected:
   Point position;
   Velocity velocity;
   bool alive;
   float rotation;

 public:
   //contructors
   FlyingObject()
   {
      position.setX(random(0, 201));
      position.setY(random(0, 201));
   }
   FlyingObject(Point &position, Velocity &velocity, float &rotation)
   {
      this->position = position;
      this->velocity = velocity;

      setAlive(true);
      setRotation(rotation);
   }

   //methods
   void kill();
   void advance();
   virtual void draw() = 0;

   // getters
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
   float getRotation() const
   {
      return rotation;
   }

   // setters
   void setPoint(const Point &point)
   {
      position = point;
   }
   void setVelocity(const Velocity &velocity)
   {
      this->velocity = velocity;
   }
   void setAlive(const bool &alive)
   {
      this->alive = alive;
   }
   void setRotation(const float &rotation)
   {
      this->rotation = rotation;
   }
};
#endif
