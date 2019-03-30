/*************************************************************
 * File: bullet.cpp
 * Author: Joshua Pearson
 *
 * Summary: Doesn't do anything... Yet.
 *************************************************************/
#include "bullet.h"

void Bullet::fire(const Point &point, const float &angle, const Velocity &velocity)
{
    setPoint(point);
    float dx = BULLET_SPEED * (-cos(M_PI / 180.0 * angle));
    float dy = BULLET_SPEED * (sin(M_PI / 180.0 * angle));
    this->velocity.setDx(dx);
    this->velocity.setDy(dy);
}
