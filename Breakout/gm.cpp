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
    elives = LIVES;
    
}
void GM::setPoints(int p)
{
    points = p;
}
int GM::getPoints()
{
    return points;
}
void GM::setELives(int l)
{
    elives = l;
}
int GM::getELives()
{
    return elives;
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
void GM::drawELives()
{
    std::string hp = "Lives: " + std::to_string(elives);
    
    
    glPushMatrix();
    glColor3f (1.0, 0.0, 0.0);
    glScalef(.3, .3, 1);
    glTranslatef(6, 10, 0.0f);
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
void GM::modifyELives(int l)
{
    elives += l;
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
    drawELives();

    
}
void GM::createBorders()
{
    glPushMatrix();
        glTranslatef(-7.0, 1.25, 0.0);
        glScalef(.5, 18, 1);
        glutSolidCube (1.0);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(7.0, 1.25, 0.0);
        glScalef(.5, 18, 1);
        glutSolidCube (1.0);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, 10.0, 0.0);
        glScalef(14, .5, 1);
        glutSolidCube (1.0);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.0, -7.5, 0.0);
        glScalef(14, .5, 1);
        glutSolidCube (1.0);
    glPopMatrix();
    
    
}
void GM::createBackground()
{
    
    //Fondo
    glPushMatrix();
        std::string nombreM = "Ball2.tga";
        char *cstr = new char[nombreM.length() + 1];
        strcpy(cstr, nombreM.c_str());
        Texture ItemTexture;
    
        //Aqui
        if(LoadTGA(&ItemTexture, cstr)){
            glGenTextures(1, &ItemTexture.texID);
            glBindTexture(GL_TEXTURE_2D, ItemTexture.texID);
            glTexImage2D(GL_TEXTURE_2D, 0, ItemTexture.bpp / 8, ItemTexture.width, ItemTexture.height, 0, ItemTexture.type, GL_UNSIGNED_BYTE, ItemTexture.imageData);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
            glEnable(GL_TEXTURE_2D);
        
            if (ItemTexture.imageData)
                free(ItemTexture.imageData);
        }
    
        delete cstr;
        drawBorders();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    
}
float GM::updateCam()
{
    if (z<=-13)
    {
        z=-13;
    }else
    {
        z--;
    }
    return z;
}
void GM::createScene()
{
    createBorders();
    createBackground();
    
}

void GM::drawBorders()
{
    glTranslatef(0.0, 1.4, -3.0);
    glBegin(GL_QUADS);                      // Draw A Quad
        glVertex3f(-11.0f, 14.0f, 0.0f);              // Top Left
        glVertex3f( 11.0f, 14.0f, 0.0f);              // Top Right
        glVertex3f( 11.0f,-14.0f, 0.0f);              // Bottom Right
        glVertex3f(-11.0f,-14.0f, 0.0f);              // Bottom Left
    glEnd();
}
void GM::drawPause()
{

}


