/*************************************************************
 * File: bird.h
 * Author: Joshua Pearson
 *
 * Description: flying object extended class
 *************************************************************/
#ifndef BIRD_H
#define BIRD_H
#include "flyingObject.h"

constexpr int sb_radius = 15;
constexpr int tb_radius = 20;

/*************
 * Class: extends flying object.
 * Basis of the birds.
 **************/
class Bird : public FlyingObject
{
public:
    /*******
     * Constructors
     * Constructs an instance of a "bird" ready for adjustment by children.
     ********/
    
    Bird();
    Bird(const Point & point);
    
  virtual void draw() = 0;
    virtual int hit() = 0;

protected:
    
};
#endif
