/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
#include <iterator>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5

/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game ::Game(Point tl, Point br)
    : topLeft(tl), bottomRight(br), ship(br)
{
   //create large asteroids
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game ::~Game()
{

   for (int i = 0; i < asteroids.size(); i++)
   {
      if (asteroids[i] != NULL)
      {
         delete asteroids[i];
         asteroids[i] = NULL;
      }
   }
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game ::advance()
{
   advanceBullets();
   advanceAsteroids();

   handleCollisions();
   cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game ::advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i]->isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i]->advance();

         if (!isOnScreen(bullets[i]->getPoint()))
         {
            // the bullet has left the screen
            bullets[i]->kill();
         }
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE asteroids
 *
 * 1. If there is no asteroids, create one with some probability
 * 2. If there are asteroids, and they're alive, advance them
 * 3. Check if the asteroids has gone of the screen, and if so, wrap them.
 **************************************************************************/
void Game ::advanceAsteroids()
{
   //check each asteroid.
   for (int i = 0; i < asteroids.size(); i++)
   {
      //make sure it's an asteroid.
      if (asteroids[i] == NULL)
      {
         asteroids.push_back(createAsteroid());
      }
      else
      {
         // we have asteroids, make sure they're alive

         if (asteroids[i]->isAlive())
         {
            // move it forward
            asteroids[i]->advance();

            // check if the asteroid has gone off the screen
            if (!isOnScreen(asteroids[i]->getPoint()))
            {
               // figure out screen wrapping, currently they die.
               asteroids[i]->kill();
            }
         }
      }
   }
}

/**************************************************************************
 * GAME :: CREATE asteroids
 * Create a asteroids of a random type according to the rules of the game.
 **************************************************************************/
Asteroid *Game ::createAsteroid()
{
   Asteroid *newAsteroid = NULL;

   // TODO: Fill this in

   Point randomPoint = new Point(random(0, 100), random(0, 100));
   // Create a tempority random Point randomPoint
   newAsteroid = new Asteroid(randomPoint); //BUG: Not sure what is going on here. fix!
   //newasteroids = new asteroids();

   return newAsteroid;
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game ::isOnScreen(const Point &point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a asteroids and a bullet.
 **************************************************************************/
void Game ::handleCollisions()
{
   // now check for a hit (if it is close enough to any live bullets)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i]->isAlive())
      {
         // this bullet is alive, see if its too close

         // check if the asteroids is at this point (in case it was hit)
         if (asteroids != NULL && asteroids->isAlive())
         {
            // BTW, this logic could be more sophisiticated, but this will
            // get the job done for now...
            if (fabs(bullets[i].getPoint().getX() - asteroids->getPoint().getX()) < CLOSE_ENOUGH && fabs(bullets[i].getPoint().getY() - asteroids->getPoint().getY()) < CLOSE_ENOUGH)
            {
               //we have a hit!

               // hit the asteroids
               int points = asteroids->hit();
               score += points;

               // the bullet is dead as well
               bullets[i].kill();
            }
         }
      } // if bullet is alive

   } // for bullets
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate asteroids)
 **************************************************************************/
void Game ::cleanUpZombies()
{
   // check for dead asteroids
   //TODO: Add for loop to check each asteroid.
   if (asteroids != NULL && !asteroids->isAlive())
   {
      // the asteroids is dead, but the memory is not freed up yet

      // TODO: Clean up the memory used by the asteroids
      delete &asteroids;
      asteroids = NULL;
   }

   // Look for dead bullets

   vector<Bullet>::iterator bulletIt = bullets->begin();
   while (bulletIt != bullets.end())
   {
      Bullet *bullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;

      if (!bullet.isAlive())
      {
         // If we had a list of pointers, we would need to delete the memory here...

         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game ::handleInput(const Interface &ui)
{
   // Change the direction of the ship
   if (ui.isLeft())
   {
      ship.rotateLeft();
   }

   if (ui.isRight())
   {
      ship.rotateRight();
   }

   // Check for "Spacebar
   if (ui.isSpace())
   {
      Bullet *newBullet;
      newBullet->fire(ship.getPoint(), ship.getRotation(), ship.getVelocity());

      bullets.push_back(newBullet);
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game ::draw(const Interface &ui)
{
   // draw the asteroids

   /* TODO: Check if you have a valid asteroid and if it's alive
   then call its draw method */
   // TODO: Loop the asteroids.
   if (asteroids != NULL && !asteroids->isAlive())
   {
      asteroids->draw();
   }
   // draw the ship
   ship.draw();

   // draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i]->isAlive())
      {
         bullets[i]->draw();
      }
   }

   // Put the score on the screen
   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);

   drawNumber(scoreLocation, score);
}

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game ::getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                   obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                   obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));

      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();

      float distSquared = (xDiff * xDiff) + (yDiff * yDiff);

      distMin = min(distMin, distSquared);
   }

   return sqrt(distMin);
}
