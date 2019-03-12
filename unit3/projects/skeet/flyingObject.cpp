/*************************************************************
 * File: flyingobject.cpp
 * Author: Joshua Pearson
 *
 * Summary: Doesn't do anything... Yet.
 *************************************************************/

#include "flyingObject.h"

void FlyingObject::advance()
{
    position.addX(velocity.getDx());
    position.addY(velocity.getDy());
    
   // position.setX(position.getX() + velocity.getDx());
    
}
void FlyingObject::kill()
{
    alive = false;
}


