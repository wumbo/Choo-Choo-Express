//
//  Tower.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 2/04/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <GL/freeglut.h>

#include "Tower.h"

Tower::Tower(int dist)
{
    this->dist = dist;
}

void Tower::draw()
{
    glColor4f(0.5, 0.5, 0.5, 1.0);
    
    glPushMatrix();
    glTranslatef(-40, 0, dist);
    
    glBegin(GL_QUADS);
    {
        glNormal3f(0, 0, -1);
        glVertex3f(-15, 0, 0);
        glVertex3f(15, 0, 0);
        glVertex3f(15, 140, 0);
        glVertex3f(-15, 140, 0);
        
        glNormal3f(1, 0, 0);
        glVertex3f(15, 0, 0);
        glVertex3f(15, 0, -20);
        glVertex3f(15, 140, -20);
        glVertex3f(15, 140, 0);
        
        glNormal3f(0, 0, 1);
        glVertex3f(15, 0, -20);
        glVertex3f(-15, 0, -20);
        glVertex3f(-15, 140, -20);
        glVertex3f(15, 140, -20);
        
        glNormal3f(-1, 0, 0);
        glVertex3f(-15, 0, -20);
        glVertex3f(-15, 0, 0);
        glVertex3f(-15, 140, 0);
        glVertex3f(-15, 140, -20);
        
        glNormal3f(0, 1, 0);
        glVertex3f(-15, 140, 0);
        glVertex3f(15, 140, 0);
        glVertex3f(15, 140, -20);
        glVertex3f(-15, 140, -20);
    }
    glEnd();
    
    glMaterialf(GL_FRONT, GL_SHININESS, 10);
    glColor4f(0.8, 0.8, 0, 1);
    glPushMatrix();
    glTranslatef(0, 145, -10);
    glutSolidTeapot(10);
    glPopMatrix();
    glMaterialf(GL_FRONT, GL_SHININESS, 50);
    
    glPopMatrix();
    
    glNormal3f(0, 1, 0);
}