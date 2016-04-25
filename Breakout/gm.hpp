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


#define LIVES 3
#define POINTS 0

class GM
{
private:
    int lives;
    int points;
    void drawLives();
    void drawPoints();


public:
    
    GM();
    void setPoints(int x);
    int getPoints();
    void setLives(int y);
    int getLives();
    void modifyLives(int l);
    void modifyPoints(int p);

    void drawScoreboard();
    


    
};
#endif /* gm_hpp */
