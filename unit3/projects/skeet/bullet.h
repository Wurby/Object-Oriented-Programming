/*************************************************************
 * File: bullet.h
 * Author: Joshua Pearson
 *
 * Description: flying object extended class
 *************************************************************/

#ifndef BULLET_H
#define BULLET_H

#include "flyingObject.h"
#include <cmath>

#define BULLET_SPEED 10.0

class Bullet : public FlyingObject
{
  public:
    Bullet()
    {
        setAlive(true);
    }
    
    
   virtual void draw()
    {
        drawDot(getPoint());
    };
    
    void fire(const Point & point, const float & angle);

  private:
};

#endif
