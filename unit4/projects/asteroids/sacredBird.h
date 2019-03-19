//
//  sacredBird.h
//  skeet
//
//  Created by Joshua Pearson on 3/12/19.
//  Copyright © 2019 Joshua Pearson. All rights reserved.
//

#ifndef sacredBird_h
#define sacredBird_h

#include "bird.h"


class sacredBird : public Bird
{
protected:
public:
    
    sacredBird();
    sacredBird(Point & point);
    
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

#endif /* sacredBird_h */
