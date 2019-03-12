//
//  toughBird.cpp
//  skeet
//
//  Created by Joshua Pearson on 3/12/19.
//  Copyright © 2019 Joshua Pearson. All rights reserved.
//

#include "toughBird.h"


toughBird::toughBird()
{
    setAlive(true);
}
toughBird::toughBird(Point & point)
{
    setAlive(true);
    setPoint(point);
}

void toughBird::draw()
{
    
    drawToughBird(position, tb_radius, hitPoints -1);
}
int toughBird::hit()
{
    hitPoints--;
    return 1;
}
