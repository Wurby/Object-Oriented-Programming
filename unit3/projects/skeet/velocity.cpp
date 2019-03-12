/*************************************************************
 * File: velocity.cpp
 * Author: Joshua Pearson
 *
 * Summary: Doesn't do anything... Yet.
 *************************************************************/

#include "velocity.h"

Velocity::Velocity() : dx(0.0), dy(0.0)
{}

Velocity::Velocity(const float & dx, const float & dy)
{
    this->dx = dx;
    this->dy = dy;
}
