//
//  brick.cpp
//  Breakout
//
//  Created by Pablo Zebadúa on 23/04/16.
//  Copyright © 2016 Controversial Games. All rights reserved.
//

#include "brick.hpp"

Brick::Brick(int p , double x, double y)
{
    visible = 1;
    points = p;
    
    setColor(p);

    coordsX = x;
    coordsY = y;
}
void Brick::setX(double x)
{
    coordsX = x;
}
double Brick::getX()
{
    return coordsX;
}
void Brick::setY(double y)
{
    coordsY = y;
}
double Brick::getY()
{
    return coordsY;
}
void Brick::setVisible(int v)
{
    visible = v;
}
int Brick::getVisible()
{
    return visible;
}
void Brick::setPoints(int p)
{
    points = p;
}
int Brick::getPoints()
{
    return points;
}
float Brick::getSizeRight()
{
    return coordsX + 1;
}
float Brick::getSizeLeft()
{
    return coordsX - 1;
}
float Brick::getSizeUp()
{
    return coordsY + .5;
}
float Brick::getSizeDown()
{
    return coordsY - .5;
}
void Brick::drawBrick()
{
    
    glPushMatrix();
    glTranslatef(coordsX, coordsY, 0);
    glScalef(1.0, 0.5, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glColor3f (R, G, B);
    glutSolidCube (size*2);
    glPopMatrix();
}

void Brick::setColor(int i)
{
    
    switch (i) {
        case 1:
            R=1.0;
            G=1.0;
            B=0.6;
            break;
        case 2:
            R=0.627;
            G=0.125;
            B=0.94;
            break;
        case 3:
            R=0.67;
            G=1.0;
            B=0.18;
            break;

    }
}
