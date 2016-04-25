//
//  paddle.hpp
//  Breakout
//
//  Created by Pablo Zebadúa on 23/04/16.
//  Copyright © 2016 Controversial Games. All rights reserved.
//

#ifndef paddle_hpp
#define paddle_hpp

#include <stdio.h>
#include <GLUT/GLUT.h>
#include <stdlib.h>
#include <cmath>        // std::abs

#define LIMIT 6
#define SIZE_ADJUSTMENT .75
class Paddle
{
private:
    float speed;
    double coordsX;
    double coordsY;
    float size = 1.5;
    
public:
    Paddle(float s , double x, double y);
    void setX(double x);
    double getX();
    void setY(float y);
    float getY();
    void setSpeed(float s);
    float getSpeed();
    float getSizeRight();
    float getSizeLeft();
    float getSizeUp();
    float getSizeDown();
    void drawPaddle();
};

#endif /* paddle_hpp */
