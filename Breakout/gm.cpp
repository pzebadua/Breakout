//
//  gm.cpp
//  Breakout
//
//  Created by Pablo Zebadúa on 23/04/16.
//  Copyright © 2016 Controversial Games. All rights reserved.
//

#include "gm.hpp"


GM::GM()
{
    points = POINTS;
    lives = LIVES;
    
}
void GM::setPoints(int p)
{
    points = p;
}
int GM::getPoints()
{
    return points;
}

void GM::setLives(int l)
{
    lives = l;
}
int GM::getLives()
{
    return lives;
}
void GM::drawLives()
{
    std::string hp = "Lives: " + std::to_string(lives);

    
    glPushMatrix();
    glScalef(.3, .3, 1);
    glTranslatef(6, -10, 0.0f);
    t3dDraw3D(hp, 0, 0, 0.2f);
    glPopMatrix();
    
}
void GM::drawPoints()
{
    std::string score = "Points: " + std::to_string(points);
    
    //Draw the strings along the sides of a square
    glPushMatrix();
    glScalef(.3, .3, 1);
    glTranslatef(-6, -10, 0.0f);
    t3dDraw3D(score, 0, 0, 0.2f);
    glPopMatrix();


}
void GM::modifyLives(int l)
{
    lives += l;
}
void GM::modifyPoints(int p)
{
    points += p;
}
void GM::drawScoreboard()
{
    glTranslatef(0.0f, 0.0f, -8.0f);
    
    GLfloat ambientColor[] = {0.4f, 0.4f, 0.4f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
    
    GLfloat lightColor0[] = {0.6f, 0.6f, 0.6f, 1.0f};
    GLfloat lightPos0[] = {-0.5f, 0.5f, 1.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    
    drawPoints();
    drawLives();
    
}
