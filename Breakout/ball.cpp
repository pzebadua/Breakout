//
//  ball.cpp
//  Breakout
//
//  Created by Pablo Zebadúa on 23/04/16.
//  Copyright © 2016 Controversial Games. All rights reserved.
//

#include "ball.hpp"

Ball::Ball(double x, double y,double vx, double vy)
{
    coordsX = x;
    coordsY = y;
    velocity_x = vx;
    velocity_y = vy;
    last_direction = coordsX > 0 ? 1 : coordsX == 0 ? 0 : -1;
    
}
void Ball::setX(double x)
{
    coordsX = coordsX + (x * velocity_x);

    //Checks the limits of the paddle
    if (coordsX > LIMIT)
    {
        velocity_x = velocity_x * -1;
    } else if (coordsX < -LIMIT)
    {
        velocity_x = velocity_x * -1;

    }
    
}
double Ball::getX()
{
    return coordsX;
}
void Ball::setY(float y)
{
    coordsY = coordsY + (y * velocity_y);
}
float Ball::getY()
{
    return coordsY;
}

void Ball::setVelocityX(float x)
{
    velocity_x = x;
}
float Ball::getVelocityX()
{
    return velocity_x;
}
void Ball::setVelocityY(float y)
{
    velocity_y = y;
}
float Ball::getVelocityY()
{
    return velocity_y;
}
void Ball::setLastDirection(int i)
{
    last_direction = i;
}
int Ball::getLastDirection()
{
    return last_direction;
}
float Ball::getRadius()
{
    return radius;
}
void Ball::setRadius(float r)
{
    radius = r;
}

void Ball::reset(double x, double y,double vx, double vy)
{
    coordsX = x;
    coordsY = y;
    velocity_x = vx;
    velocity_y = vy;
    last_direction = coordsX > 0 ? 1 : coordsX == 0 ? 0 : -1;
    
}
void Ball::drawBall()
{
    
    glPushMatrix();
    
    glTranslatef(coordsX,coordsY,0.0);
    
    glutWireSphere(radius,16,16);
    
    glPopMatrix();
}