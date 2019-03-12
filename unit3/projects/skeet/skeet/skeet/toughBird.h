//
//  toughBird.h
//  skeet
//
//  Created by Joshua Pearson on 3/12/19.
//  Copyright © 2019 Joshua Pearson. All rights reserved.
//

#ifndef toughBird_h
#define toughBird_h
#include "bird.h"

class toughBird : public Bird
{
protected:
    int hitPoints = 4;
public:
    toughBird();
    toughBird(Point & point);
    
    virtual void draw();
    virtual int hit();
    
    Point getPoint()
    {
        return position;
    }
    Velocity getVelocity()
    {
        return velocity;
    }
    
    void setPoint(const Point & point)
    {
        position = point;
    }
    void setVelocity(const Velocity & velocity)
    {
        this->velocity = velocity;
    }
};


#endif /* toughBird_h */
