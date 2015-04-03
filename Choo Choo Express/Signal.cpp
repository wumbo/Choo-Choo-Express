//
//  Signal.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 2/04/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <GL/freeglut.h>

#include "Signal.h"

sig_color_t Signal::color = GREEN;

void Signal::draw()
{
    glPushMatrix();
    glTranslatef(20, 0, -100);
    glRotatef(90, 0, 1, 0);
    
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glColor4f(0.5, 0.5, 0.5, 1);
    glutSolidCylinder(1, 20, 30, 30);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 20, 0);
    glScalef(3, 8, 3);
    glutSolidCube(1);
    glPushMatrix(); // Green light
    glTranslatef(0, 0.3, 0);
    glScalef(1, 0.5, 1);
    if (color == GREEN)
        glColor4f(0, 1, 0, 1);
    else
        glColor4f(0.3, 0.3, 0.3, 1);
    glutSolidCylinder(0.3, 1, 30, 30);
    glPopMatrix();
    glPushMatrix(); // Red light
    glTranslatef(0, -0.3, 0);
    glScalef(1, 0.5, 1);
    if (color == RED)
        glColor4f(1, 0, 0, 1);
    else
        glColor4f(0.3, 0.3, 0.3, 1);
    glutSolidCylinder(0.3, 1, 30, 30);
    glPopMatrix();
    glPopMatrix();
    
    glPopMatrix();
    
    glNormal3f(0, 1, 0);
}