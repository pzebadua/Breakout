//
//  gm.hpp
//  Breakout
//
//  Created by Pablo Zebadúa on 23/04/16.
//  Copyright © 2016 Controversial Games. All rights reserved.
//

#ifndef gm_hpp
#define gm_hpp

#include <stdio.h>
#include <GLUT/GLUT.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "text3d.h"
#include "Texture.h"

#define LIVES 3
#define POINTS 0

class GM
{
private:
    int lives;
    int elives;
    int points;
    void drawLives();
    void drawELives();
    void drawPoints();
    void createBorders();
    void createBackground();
    void drawBorders();
    int z = 0.0;


public:
    
    GM();
    void setPoints(int x);
    int getPoints();
    void setELives(int y);
    int getELives();
    void setLives(int y);
    int getLives();
    void modifyELives(int l);
    void modifyLives(int l);
    void modifyPoints(int p);
    void createScene();
    void drawScoreboard();
    float updateCam();
    void drawPause();


    
};
#endif /* gm_hpp */
