#include "rocks.h"

// Put your Rock methods here

void SmallAsteroid::draw()
{
   static int rotation = SMALL_ROCK_SPIN;
   rotation += SMALL_ROCK_SPIN;
   drawSmallAsteroid(this->getPoint(), rotation);
}
void MediumAsteroid::draw()
{
   static int rotation = MEDIUM_ROCK_SPIN;
   rotation += MEDIUM_ROCK_SPIN;
   drawMediumAsteroid(this->getPoint(), rotation);
}
void LargeAsteroid::draw()
{
   static int rotation = BIG_ROCK_SPIN;
   rotation += BIG_ROCK_SPIN;
   drawLargeAsteroid(this->getPoint(), rotation);
}