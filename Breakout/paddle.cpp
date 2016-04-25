//
//  paddle.cpp
//  Breakout
//
//  Created by Pablo Zebadúa on 23/04/16.
//  Copyright © 2016 Controversial Games. All rights reserved.
//

#include "paddle.hpp"

Paddle::Paddle(float s,double x, double y)
{
    speed = s;
    coordsX = x;
    coordsY = y;
}
void Paddle::setX(double x)
{
    coordsX += speed * x;
    //Checks the limits of the paddle
    if(std::abs (coordsX) > LIMIT)
    {
        //Is it positive or negative ?
        int sign = coordsX > 0 ? 1 : coordsX == 0 ? 0 : -1;
        
        //Set to the limit by multiplying the sign
        coordsX= LIMIT * sign;
    }
}
double Paddle::getX()
{
    return coordsX;
}
void Paddle::setY(float y)
{
    coordsY = y;
}
float Paddle::getY()
{
    return coordsY;
}
void Paddle::setSpeed(float s)
{
    speed = s;
}
float Paddle::getSpeed()
{
    return speed;
}
float Paddle::getSizeRight()
{
    return coordsX + 1.5;
}
float Paddle::getSizeLeft()
{
    return coordsX - 1.5;
}
float Paddle::getSizeUp()
{
    return 1 + coordsY * .33;
}
float Paddle::getSizeDown()
{
    return coordsY * .33;
}
void Paddle::drawPaddle()
{
    
    glPushMatrix();
    glScalef(1.0, 0.33, 1.0);
    glTranslatef(coordsX, coordsY, 0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glutWireCube (3.0);
    glPopMatrix();
}