//
//  Person.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 2/04/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <GL/freeglut.h>

#include "Person.h"

int Person::armRot = 0;

void Person::draw()
{
    glPushMatrix();
    glRotatef(333, 0, 1, 0);
    glTranslatef(0, 8, -135);
    glScalef(1.5, 1.5, 1.5);
    
    glColor3f(1., 0.78, 0.06);		//Head
    glPushMatrix();
    glTranslatef(0, 7.7, 0);
    glutSolidCube(1.4);
    glPopMatrix();
    
    glColor3f(1., 0., 0.);			//Torso
    glPushMatrix();
    glTranslatef(0, 5.5, 0);
    glScalef(3, 3, 1.4);
    glutSolidCube(1);
    glPopMatrix();
    
    glColor3f(0., 0., 1.);			//Right leg
    glPushMatrix();
    glTranslatef(-0.8, 2.2, 0);
    glScalef(1, 4.4, 1);
    glutSolidCube(1);
    glPopMatrix();
    
    glColor3f(0., 0., 1.);			//Left leg
    glPushMatrix();
    glTranslatef(0.8, 2.2, 0);
    glScalef(1, 4.4, 1);
    glutSolidCube(1);
    glPopMatrix();
    
    glColor3f(0., 0., 1.);			//Right arm
    glPushMatrix();
    glTranslatef(-2, 5, 0);
    glScalef(1, 4, 1);
    glutSolidCube(1);
    glPopMatrix();
    
    glColor3f(0., 0., 1.);			//Left arm
    glPushMatrix();
    glTranslatef(2, 6.5, 0);
    glRotatef(armRot, 1, 0, 0);
    glTranslatef(-2, -6.5, 0);
    glTranslatef(2, 5, 0);
    glScalef(1, 4, 1);
    glutSolidCube(1);
    glPopMatrix();
    
    glPopMatrix();
    
    glNormal3f(0, 1, 0);
}