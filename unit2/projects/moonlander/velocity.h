/*************************************************************
 * File: velocity.h
 * Author: Joshua Pearson
 *
 * Description: 
 *************************************************************/

#ifndef VELOCITY_H

class Velocity
{
  private:
  public:
    Velocity();
    Velocity(float, float);
    float getDx();
    float getDy();
    void setDx(float);
    void setDy(float);
};

#endif