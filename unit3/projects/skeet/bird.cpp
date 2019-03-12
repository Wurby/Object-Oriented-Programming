/*************************************************************
 * File: bird.cpp
 * Author: Joshua Pearson
 *
 * Summary: base bird to be updated.
 *************************************************************/

#include "bird.h"

Bird::Bird()
{
    setAlive(true);
}
Bird::Bird(const Point & point)
{
    setAlive(true);
    setPoint(point);
}
