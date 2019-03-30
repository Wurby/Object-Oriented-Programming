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

// Here is your feedback for milestone 11. Hopefully by now you can see your asteroids program coming together into a cohesive game.

// As you wrap things up over the next two weeks, consider ways that you can go above and beyond, both in functionality and in code.
// (Consider that superior functionality will catch the eye of your classmates, but superior code quality will catch the eye of developers in charge of reviewing job applications).

// In particular, here are a few comments specific to your milestone 11 contribution:
// Rotation should probably not be in flyingObject, as it only applies to the rocks and ship.
// Consider using your game class from skeet and building off that to speed things up. You’re falling behind.
// In your case, I’d try to get a working version before doing any Above and Beyond(PowerUp).Good luck this week,

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
     this->velocity=velocity;
      
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
   void setRotation(const float & rotation)
   {
      this->rotation = rotation;
   }
};
#endif
