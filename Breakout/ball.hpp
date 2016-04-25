//
//  ball.hpp
//  Breakout
//
//  Created by Pablo Zebadúa on 23/04/16.
//  Copyright © 2016 Controversial Games. All rights reserved.
//

#ifndef ball_hpp
#define ball_hpp


#include <stdio.h>
#include <GLUT/GLUT.h>
#include <stdlib.h>
#include <cmath>  
#include <iostream>
#define LIMIT 6


class Ball
{
private:
    double radius = 0.4;
    double coordsX;
    double coordsY;
    float velocity_x;
    float velocity_y;
    int last_direction;
public:
    
    Ball(double x, double y, double vx, double vy);
    void setX(double x);
    double getX();
    void setY(float y);
    float getY();
    void setVelocityX(float x);
    float getVelocityX();
    void setVelocityY(float y);
    float getVelocityY();
    void setLastDirection(int i);
    int getLastDirection();
    float getRadius();
    void setRadius(float r);
    void drawBall();
    void reset(double x, double y, double vx, double vy);

    
    
};

#endif /* ball_hpp */
