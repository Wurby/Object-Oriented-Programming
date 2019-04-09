#include "rocks.h"
// BUG: velocity isn't set for any asteroid, and direction of travel?
/*
*  Small Asteroid:
*/
void SmallAsteroid::draw()
{
   static int rotation = SMALL_ROCK_SPIN;
   rotation += SMALL_ROCK_SPIN;
   drawSmallAsteroid(this->getPoint(), rotation);
}
SmallAsteroid::SmallAsteroid(Point &point)
{
   setPoint(point);
   draw();
}
// TODO: virtual void hit()

/*
*  Medium Asteroid:
*/
void MediumAsteroid::draw()
{
   static int rotation = MEDIUM_ROCK_SPIN;
   rotation += MEDIUM_ROCK_SPIN;
   drawMediumAsteroid(this->getPoint(), rotation);
}
MediumAsteroid::MediumAsteroid(Point &point)
{
   setPoint(point);
   draw();
}
// TODO: virtual void hit()
/*
*  Large Asteroid:
*/
void LargeAsteroid::draw()
{
   static int rotation = BIG_ROCK_SPIN;
   rotation += BIG_ROCK_SPIN;
   drawLargeAsteroid(this->getPoint(), rotation);
}

LargeAsteroid::LargeAsteroid(Point &point)
{
   setPoint(point);
   draw();
}
// TODO: virtual void hit()