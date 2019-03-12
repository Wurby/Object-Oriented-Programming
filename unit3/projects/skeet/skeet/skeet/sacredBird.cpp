//
//  sacredBird.cpp
//  skeet
//
//  Created by Joshua Pearson on 3/12/19.
//  Copyright © 2019 Joshua Pearson. All rights reserved.
//

#include "sacredBird.h"


sacredBird::sacredBird()
{
    setAlive(true);
}
sacredBird::sacredBird(Point & point)
{
    setAlive(true);
    setPoint(point);
}

void sacredBird::draw()
{
    drawSacredBird(position, sb_radius);
}
int sacredBird::hit()
{
    setAlive(false);
    return -5;
}
