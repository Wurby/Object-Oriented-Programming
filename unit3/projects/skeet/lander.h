/*************************************************************
 * File: lander.h
 * Author: Joshua Pearson
 *
 * Description: The Lander Class.
 *************************************************************/
#ifndef LANDER_H
#define LANDER_H
#include "velocity.h"
#include "point.h"
#include "uiDraw.h"

class Lander
{
private:
  bool aliveState;
  int fuelLevel;
  bool thrustState;
  bool landedState;
  Point point;
  Velocity velocity;

public:
  // seperate by getter, setter, etc.
  Lander();
  Point getPoint() const;
  Velocity getVelocity() const;
  int getFuel() const;
  bool isAlive();
  bool isLanded();
  bool canThrust();

  void setLanded(bool);
  void setAlive(bool);
  void setFuel(int);

  void applyGravity(float);
  void applyThrustLeft();
  void applyThrustRight();
  void applyThrustBottom();
  void advance();
  void draw();
};

#endif