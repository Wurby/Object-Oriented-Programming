#include "ship.h"

void Ship::draw()
{
   drawShip(this->position, this->rotation, thrust);
}
bool Ship::applyThrust() //mega flawed, this needs to take direction into account (obviously)
{
   setThrust(true);

   float dx = THRUST_AMOUNT * (-sin(M_PI / 180.0 * rotation));
   float dy = THRUST_AMOUNT * (cos(M_PI / 180.0 * rotation));
   this->velocity.setDx(dx);
   this->velocity.setDy(dy);

   return thrust;
}
void Ship::rotateRight() // needs to be tested.
{
   this->setRotation(this->getRotation() + 2);
}
void Ship::rotateLeft() // same as above
{
   this->setRotation(this->getRotation() - 2);
}

//xtras:

// void triggerShield()
// {
//    this->setShielded(true);
// }

// void Ship::drawShield()
// {
//    drawCircle(this->getRotation(), 12);
// }