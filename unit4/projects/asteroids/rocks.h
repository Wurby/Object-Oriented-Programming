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
 public:
   virtual void draw() = 0;

   // xtras
   // void randomImpact();
};

class SmallAsteroid : public Asteroid
{
   virtual void draw();
};

class MediumAsteroid : public Asteroid
{
   virtual void draw();
};

class LargeAsteroid : public Asteroid
{
   virtual void draw();
};

#endif /* rocks_h */
