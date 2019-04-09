#ifndef rocks_h
#define rocks_h

#include "flyingObject.h"

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

class Asteroid : public FlyingObject
{
 protected:
   float rotation;

 public:
   virtual void draw() = 0;
   float getRotation() const
   {
      return rotation;
   }
   void setRotation(const float &rotation)
   {
      this->rotation = rotation;
   }
   virtual void hit();

   // xtras
   // void randomImpact();
};

class SmallAsteroid : public Asteroid
{
 public:
   SmallAsteroid(Point &point);
   virtual void draw();
   virtual void hit();
};

class MediumAsteroid : public Asteroid
{
 public:
   MediumAsteroid(Point &point);
   virtual void draw();
   virtual void hit();
};

class LargeAsteroid : public Asteroid
{
 public:
   LargeAsteroid(Point &point);
   virtual void draw();
   virtual void hit();
};

#endif /* rocks_h */
