//
//  Skybox.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 2/04/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <GL/freeglut.h>

#include "Skybox.h"
#include "App.h"

void Skybox::draw()
{
    glEnable(GL_TEXTURE_2D);
    
    ////////////////////// LEFT WALL ///////////////////////
    glBindTexture(GL_TEXTURE_2D, App::texId[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);  glVertex3f(-10000, 0, 10000);
    glTexCoord2f(1,0);  glVertex3f(-10000, 0, -10000);
    glTexCoord2f(1,1);  glVertex3f(-10000, 10000, -10000);
    glTexCoord2f(0,1);  glVertex3f(-10000, 10000, 10000);
    glEnd();
    
    ////////////////////// FRONT WALL ///////////////////////
    glBindTexture(GL_TEXTURE_2D, App::texId[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);  glVertex3f(-10000,  0, -10000);
    glTexCoord2f(1,0);  glVertex3f(10000, 0, -10000);
    glTexCoord2f(1,1);  glVertex3f(10000, 10000, -10000);
    glTexCoord2f(0,1);  glVertex3f(-10000,  10000, -10000);
    glEnd();
    
    ////////////////////// RIGHT WALL ///////////////////////
    glBindTexture(GL_TEXTURE_2D, App::texId[3]);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);  glVertex3f(10000,  0, -10000);
    glTexCoord2f(1,0);  glVertex3f(10000, 0, 10000);
    glTexCoord2f(1,1);  glVertex3f(10000, 10000,  10000);
    glTexCoord2f(0,1);  glVertex3f(10000,  10000,  -10000);
    glEnd();
    
    
    ////////////////////// REAR WALL ////////////////////////
    glBindTexture(GL_TEXTURE_2D, App::texId[4]);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);glVertex3f( 10000, 0, 10000);
    glTexCoord2f(1,0);glVertex3f(-10000, 0,  10000);
    glTexCoord2f(1,1);glVertex3f(-10000, 10000,  10000);
    glTexCoord2f(0,1);glVertex3f( 10000, 10000, 10000);
    glEnd();
    
    /////////////////////// TOP /////4/////////////////////
    glBindTexture(GL_TEXTURE_2D, App::texId[5]);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);glVertex3f(-10000, 10000, -10000);
    glTexCoord2f(1,0);glVertex3f(10000, 10000,  -10000);
    glTexCoord2f(1,1);glVertex3f(10000, 10000,  10000);
    glTexCoord2f(0,1);glVertex3f(-10000, 10000, 10000);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}