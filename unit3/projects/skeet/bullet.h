/*************************************************************
 * File: bullet.h
 * Author: Joshua Pearson
 *
 * Description: flying object extended class
 *************************************************************/

#include "flyingObject.h"

class Bullet : public FlyingObject
{
  public:
    void draw();
    void fire(Point point, float angle);

  private:
};