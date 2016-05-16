
#include <GLUT/GLUT.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>

#include "ball.hpp"
#include "paddle.hpp"
#include "brick.hpp"
#include "gm.hpp"
#include "text3d.h"


#define RIGHT 1
#define LEFT -1
#define UP 1
#define DOWN -1

#define ROWS 3
#define COLUMNS 6
//std::cout<<value<<std::endl;

static int flag=1;
float camX=0.0, camY=0.0, camZ=24.0;
int angles[2] = {45,-45};

//ball(speed,x,y,dx,dy);
Ball ball(0.0,0.0,0.01,0.05);
//paddle(speed,x,y);
Paddle paddle(1.0,0.0,-5.0);
//enemy(speed,x,y);
Paddle enemy(0.08,0.0,25.0);

GM gameManager;

std::vector<Brick*> list;





float _angle = -30.0f;
float _scale;


void init(void)
{
    GLfloat mat_specular[] = { 0.6, 0.6, 0.6, 1.0 };
    GLfloat mat_ambient[] = {1.0,0.0,0.0,1.0};
    GLfloat mat_shininess[] = { 0.0 };
    GLfloat light_position[] = { 0.0, 5.0, 5.0, 1.0 };
    
    
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glShadeModel (GL_SMOOTH);
    
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glShadeModel (GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    t3dInit();
    //We create the bricks and push them into a list
    Brick *ptrBrick;
    for (int i =0; i < ROWS; i++)
    {
        for (int j =0; j < COLUMNS; j++)
        {
            ptrBrick = new Brick (1 , j*2-5, i+3);
            list.push_back(ptrBrick);
        }
    }
    
}


void deleteFromList(int i)
{
    
    
    //we add some points
    gameManager.setPoints(gameManager.getPoints()+list[i]->getPoints());

    //We delete the bircks from the list (1 less brick to destroy)
    list.erase(list.begin()+i);
    
    //winning condition
    if (list.empty())
    {
        std::cout<<"Winner"<<std::endl;
        std::cout<<"Total Points: "<<gameManager.getPoints()<<std::endl;
        if (gameManager.getELives() <= 0)
        {
            exit(0);
        }
    }

}

double radian(double deg){
    return deg * (3.14159265/ 180);
}

void checkCollisionUp(float x, float y)
{
    for (int i =0; i < list.size(); i++)
    {
        if ((y-ball.getRadius()) <= list[i]->getSizeUp() && (y+ball.getRadius()) >= list[i]->getSizeDown() && x <= list[i]->getSizeRight() && x >= list[i]->getSizeLeft()){
            
            //if there is a collision with the brick delete the brick from the list
            deleteFromList(i);
            
            flag=0;
        
        }
    }
    if ((y-ball.getRadius()) <= enemy.getSizeUp() && (y+ball.getRadius()) >= enemy.getSizeDown() && x <= enemy.getSizeRight() && x >= enemy.getSizeLeft()){
        float collisionPoint = paddle.getX()-ball.getX();
        if (collisionPoint >= -1.5 && collisionPoint < -0.9)
        {
            ball.setVelocityX(0.1);
        }else if (collisionPoint >= -0.9 && collisionPoint < -0.3)
        {
            ball.setVelocityX(-0.05);
            
        }else if (collisionPoint >= -0.3 && collisionPoint < 0.0)
        {
            ball.setVelocityX(-0.01);
            
        }
        else if (collisionPoint >= 0.0 && collisionPoint < 0.3)
        {
            ball.setVelocityX(0.01);
            
        }
        else if (collisionPoint > 0.3 && collisionPoint <= 0.6)
        {
            ball.setVelocityX(0.05);
            
        }
        else if (collisionPoint > 0.6 && collisionPoint <= 1.5)
        {
            ball.setVelocityX(-0.1);
        }
        flag=0;
        
    }

    if(y>10.0)
    {
        flag=0;
        
        gameManager.setPoints(gameManager.getPoints()+3);
        gameManager.modifyELives(-1);

        if (gameManager.getELives() <= 0)
        {
            std::cout<<"Winner, Chicken Dinner"<<std::endl;
            std::cout<<"Points: " << gameManager.getPoints() <<std::endl;

            if (list.empty()){
                exit(0);
            }
        }
        ball.reset(0.0,0.0,0.05,0.05);


        
    }

}

void checkCollisionDown(float x, float y)
{
    for (int i =0; i < list.size(); i++)
    {
        if ((y+ball.getRadius()) <= list[i]->getSizeUp() && (y-ball.getRadius()) >= list[i]->getSizeDown() && x <= list[i]->getSizeRight() && x >= list[i]->getSizeLeft())
        {
                deleteFromList(i);
                flag=1;
        }
    }
        //if the ball is in the border or inside the paddle throw it up

    if (y <= paddle.getSizeUp() && y >= paddle.getSizeDown() && x <= paddle.getSizeRight() && x >= paddle.getSizeLeft()){
        float collisionPoint = paddle.getX()-ball.getX();
        if (collisionPoint >= -1.5 && collisionPoint < -0.9)
        {
            ball.setVelocityX(0.1);
        }else if (collisionPoint >= -0.9 && collisionPoint < -0.3)
        {
            ball.setVelocityX(0.05);

        }else if (collisionPoint >= -0.3 && collisionPoint < 0.0)
        {
            ball.setVelocityX(-0.01);
            
        }
        else if (collisionPoint >= 0.0 && collisionPoint < 0.3)
        {
            ball.setVelocityX(0.01);
            
        }
        else if (collisionPoint > 0.3 && collisionPoint <= 0.6)
        {
            ball.setVelocityX(-0.05);
            
        }
        else if (collisionPoint > 0.6 && collisionPoint <= 1.5)
        {
            ball.setVelocityX(-0.1);
        }
        flag=1;
        
    }else if(y<-6.5)
    {
        
        gameManager.modifyLives(-1);
        //Reset Ball position
        ball.reset(0.0,0.0,0.05,0.05);
        //Check if game is over
        if (gameManager.getLives() == 0){
            exit(0);
        }
        //Maybe add a timer here for the ball to wait 
        
    }

}

void moveEnemy()
{
    if (ball.getX()>enemy.getX()){
        enemy.setX(RIGHT);
    }else
    {
        enemy.setX(LEFT);
    }

}

void drawBricks()
{
    for (int i =0; i < list.size(); i++)
    {
        list[i]->drawBrick();
    }
}
void update()
{
    //direction managmentcc
    if(flag)
    {
        moveEnemy();
        ball.setY(UP);
        ball.setX(UP);
        checkCollisionUp(ball.getX(),ball.getY());
        
    }else if(!flag)
    {
        ball.setY(DOWN);
        ball.setX(DOWN);
        checkCollisionDown(ball.getX(),ball.getY());
    }
    //std::cout<<"VX: "<< ball.getVelocityX() <<std::endl;
    //std::cout<<"VY: "<< ball.getVelocityY() <<std::endl;

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f (1.0, 1.0, 1.0);
    

    glPushMatrix();
    //Erase Later
    gluLookAt (camX, camY, camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    gameManager.createScene();
    glTranslatef(0.0, -1.5, 0.0);
    
    drawBricks(); //Put into bricks class later
    glColor3f (1.0, 0.0, 0.0);
    enemy.drawPaddle();
    glColor3f (0.0, 0.0, 1.0);
    paddle.drawPaddle();
    ball.drawBall();
    glPopMatrix();
    //we set this outside of the pop so we can keep it next to the camara
    gameManager.drawScoreboard();
    
    glutSwapBuffers ();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(45.0, (GLfloat) w/(GLfloat) h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
}
void simulate()
{
    update();
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 'q':
            exit(0);
            break;
        case 'c':
            camX++;
            glutPostRedisplay();
            break;
        case 'C':
            camX--;
            glutPostRedisplay();
            break;
        case 'v':
            camY++;
            glutPostRedisplay();
            break;
        case 'V':
            camY--;
            glutPostRedisplay();
            break;
        case 'b':
            camZ++;
            glutPostRedisplay();
            break;
        case 'B':
            camZ--;
            glutPostRedisplay();
            break;
        case 'd':
        case 'D':
            paddle.setX(RIGHT);
            glutPostRedisplay();
            break;
        case 'a':
        case 'A':
            paddle.setX(LEFT);
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(simulate);

    glutMainLoop();
    return 0;
}
