#ifndef ship_h
#define ship_h

#include "flyingObject.h"
#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

class Ship : public FlyingObject
{
private:
  bool isShielded;
  bool thrust;

public:
  Ship() : thrust(false)
  {
  }
  virtual void draw();
  bool applyThrust();
  void setThrust(const bool &thrust) { this->thrust = thrust; }

  void rotateRight();
  void rotateLeft();
  // void setShielded(bool);
  // bool getShield() { return this->isShielded; };
  // void triggerShield();
  // void drawShield();
};

#endif /* ship_h */
