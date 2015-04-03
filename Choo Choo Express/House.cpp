//
//  House.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 2/04/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <gl/freeglut.h>

#include "House.h"

House::House(int dist)
{
    this->dist = dist;
}

void House::draw()
{
    glColor4f(0.8, 0.1, 0.1, 1.0);
    
    glPushMatrix();
    glTranslatef(45, 0, dist);
    
    glBegin(GL_QUADS);
    {
        glNormal3f(0, 0, -1);
        glVertex3f(-20, 0, 0);
        glVertex3f(20, 0, 0);
        glVertex3f(20, 30, 0);
        glVertex3f(-20, 30, 0);
        
        glNormal3f(1, 0, 0);
        glVertex3f(20, 0, 0);
        glVertex3f(20, 0, -20);
        glVertex3f(20, 30, -20);
        glVertex3f(20, 30, 0);
        
        glNormal3f(0, 0, 1);
        glVertex3f(20, 0, -20);
        glVertex3f(-20, 0, -20);
        glVertex3f(-20, 30, -20);
        glVertex3f(20, 30, -20);
        
        glNormal3f(-1, 0, 0);
        glVertex3f(-20, 0, -20);
        glVertex3f(-20, 0, 0);
        glVertex3f(-20, 30, 0);
        glVertex3f(-20, 30, -20);
    }
    glEnd();
    
    glColor4f(0.5, 0.5, 0.5, 1);
    glBegin(GL_QUADS);
    {
        glNormal3f(-1, 1, 0);
        glVertex3f(-20, 30, -20);
        glVertex3f(-20, 30, 0);
        glVertex3f(0, 45, 0);
        glVertex3f(0, 45, -20);
        
        glNormal3f(1, 1, 0);
        glVertex3f(20, 30, 0);
        glVertex3f(20, 30, -20);
        glVertex3f(0, 45, -20);
        glVertex3f(0, 45, 0);
    }
    glEnd();
    
    glBegin(GL_TRIANGLES);
    {
        glNormal3f(0, 0, 1);
        glVertex3f(-20, 30, 0);
        glVertex3f(20, 30, 0);
        glVertex3f(0, 45, 0);
        
        glNormal3f(0, 0, -1);
        glVertex3f(20, 30, -20);
        glVertex3f(-20, 30, -20);
        glVertex3f(0, 45, -20);
    }
    glEnd();
    
    glPopMatrix();
    
    glNormal3f(0, 1, 0);
}