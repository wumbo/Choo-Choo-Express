//
//  Car.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 2/04/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <GL/freeglut.h>

#include "Car.h"

Car::Car(int dist)
{
    this->dist = dist;
}

void Car::draw()
{
    glColor4f(0.8, 0.1, 0.1, 1.0);
    
    glPushMatrix();
    glTranslatef(-7, 0, dist);
    
    glBegin(GL_QUADS);
    {
        glNormal3f(0, 0, -1);
        glVertex3f(-5, 0, 0);
        glVertex3f(5, 0, 0);
        glVertex3f(5, 10, 0);
        glVertex3f(-5, 10, 0);
        
        glNormal3f(1, 0, 0);
        glVertex3f(5, 0, 0);
        glVertex3f(5, 0, -20);
        glVertex3f(5, 10, -20);
        glVertex3f(5, 10, 0);
        
        glNormal3f(0, 0, 1);
        glVertex3f(5, 0, -20);
        glVertex3f(-5, 0, -20);
        glVertex3f(-5, 10, -20);
        glVertex3f(5, 10, -20);
        
        glNormal3f(-1, 0, 0);
        glVertex3f(-5, 0, -20);
        glVertex3f(-5, 0, 0);
        glVertex3f(-5, 10, 0);
        glVertex3f(-5, 10, -20);
        
        glNormal3f(0, 1, 0);
        glVertex3f(-5, 10, 0);
        glVertex3f(5, 10, 0);
        glVertex3f(5, 10, -20);
        glVertex3f(-5, 10, -20);
    }
    glEnd();
    
    glPopMatrix();
}