//
//  StandardBird.cpp
//  skeet
//
//  Created by Joshua Pearson on 3/12/19.
//  Copyright © 2019 Joshua Pearson. All rights reserved.
//

#include "standardBird.h"


standardBird::standardBird()
{
    setAlive(true);
}
standardBird::standardBird(Point & point)
{
    setAlive(true);
    setPoint(point);
}

void standardBird::draw()
{
    drawCircle(position, sb_radius);
}
int standardBird::hit()
{
    setAlive(false);
    return 1;
}
