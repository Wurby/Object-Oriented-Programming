#ifndef ship_h
#define ship_h

#include "flyingObject.h"
#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

class Ship : public FlyingObject
{
 protected:
 
 public:
   virtual void draw();
   void applyThrust();
   void rotateRight();
   void rotateLeft();
   void triggerShield();
   void drawShield();
};

#endif /* ship_h */
