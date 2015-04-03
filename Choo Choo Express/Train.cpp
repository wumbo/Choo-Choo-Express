//
//  Train.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 1/04/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <GL/freeglut.h>
#include <math.h>

#include "Train.h"
#include "App.h"
#include "Scene.h"

int Train::theta = 0;

// Draws a single train track of a given radius
void Train::track(float radius)
{
    float angle1,angle2, ca1,sa1, ca2,sa2;
    float x1,z1, x2,z2, x3,z3, x4,z4;  //four points of a quad
    float toRad=3.14159265/180.0;  //Conversion from degrees to radians
    
    glBegin(GL_QUADS);
    for(int i = 0; i < 360; i += 5)    //5 deg intervals
    {
        angle1 = i * toRad;       //Computation of angles, cos, sin etc
        angle2 = (i+5) * toRad;
        ca1=cos(angle1); ca2=cos(angle2);
        sa1=sin(angle1); sa2=sin(angle2);
        x1=(radius-0.5)*sa1; z1=(radius-0.5)*ca1;
        x2=(radius+0.5)*sa1; z2=(radius+0.5)*ca1;
        x3=(radius+0.5)*sa2; z3=(radius+0.5)*ca2;
        x4=(radius-0.5)*sa2; z4=(radius-0.5)*ca2;
        
        glNormal3f(0., 1., 0.);       //Quad 1 facing up
        glVertex3f(x1, 1.0, z1);
        glVertex3f(x2, 1.0, z2);
        glVertex3f(x3, 1.0, z3);
        glVertex3f(x4, 1.0, z4);
        
        glNormal3f(-sa1, 0.0, -ca1);   //Quad 2 facing inward
        glVertex3f(x1, 0.0, z1);
        glVertex3f(x1, 1.0, z1);
        glNormal3f(-sa2 ,0.0, -ca2);
        glVertex3f(x4, 1.0, z4);
        glVertex3f(x4, 0.0, z4);
        
        glNormal3f(sa1, 0.0, ca1);   //Quad 3 facing outward
        glVertex3f(x2, 1.0, z2);
        glVertex3f(x2, 0.0, z2);
        glNormal3f(sa2, 0.0, ca2);
        glVertex3f(x3, 0.0, z3);
        glVertex3f(x3, 1.0, z3);
    }
    glEnd();
}

// Draws the entire train tracks
void Train::tracks()
{
    glColor4f(0.2, 0.2, 0.3, 1.0);
    glMaterialf(GL_FRONT, GL_SHININESS, 10);
    track(115.0);   //Inner track has radius 115 units
    track(125.0);   //Outer track has radius 125 units
    glMaterialf(GL_FRONT, GL_SHININESS, 50);
}

// Draws the base of the train
void Train::base()
{
    glColor4f(0.2, 0.2, 0.2, 1.0);   //The base is nothing but a scaled cube!
    glPushMatrix();
    glTranslatef(0.0, 4.0, 0.0);
    glScalef(20.0, 2.0, 10.0);     //Size 20x10 units, thickness 2 units.
    glutSolidCube(1.0);
    glPopMatrix();
    
    glPushMatrix();					//Connector between wagons
    glTranslatef(11.0, 4.0, 0.0);
    glutSolidCube(2.0);
    glPopMatrix();
    
    //Wheels
    glColor4f(0.5, 0., 0., 1.0);
    glPushMatrix();
    glTranslatef(-8.0, 2.0, 5.1);
    gluDisk(App::q, 0.0, 2.0, 20, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8.0, 2.0, 5.1);
    gluDisk(App::q, 0.0, 2.0, 20, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-8.0, 2.0, -5.1);
    glRotatef(180.0, 0., 1., 0.);
    gluDisk(App::q, 0.0, 2.0, 20, 2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8.0, 2.0, -5.1);
    glRotatef(180.0, 0., 1., 0.);
    gluDisk(App::q, 0.0, 2.0, 20, 2);
    glPopMatrix();
}

// Draws the main part of the train
void Train::engine()
{
    base();
    
    //Cab
    glColor4f(0.8, 0.8, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(7.0, 8.5, 0.0);
    glScalef(6.0, 7.0, 10.0);
    glutSolidCube(1.0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(6.0, 14.0, 0.0);
    glScalef(4.0, 4.0, 8.0);
    glutSolidCube(1.0);
    glPopMatrix();
    
    //Boiler
    glPushMatrix();
    glColor4f(0.5, 0., 0., 1.0);
    glTranslatef(4.0, 10.0, 0.0);
    glRotatef(-90.0, 0., 1., 0.);
    gluCylinder(App::q, 5.0, 5.0, 14.0, 20, 5);
    glTranslatef(0.0, 0.0, 14.0);
    gluDisk(App::q, 0.0, 5.0, 20, 3);
    glColor4f(1.0, 1.0, 0.0, 1.0);
    glTranslatef(0.0, 4.0, 0.2);
    gluDisk(App::q, 0.0, 1.0, 20,2);  //headlight!
    glPopMatrix();
}

// Draws a wagon to go behind the train engine
void Train::wagon()
{
    base();
    
    glColor4f(0.7, 0.7, 0.8, 1.0);
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(0.0, 10.0, -10.0);
    glScalef(5.0, 5.0, 20.0);
    gluCylinder(App::q, 1.0, 1.0, 1.0, 16, 4);
    glPopMatrix();
}

// Draws the tracks and train for the scene
void Train::draw()
{
    tracks();
    
    glPushMatrix();
    glRotatef(theta, 0, 1.0, 0);
    glTranslatef(0, 1, -120);
    engine();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(theta - 10.5, 0, 1.0, 0);
    glTranslatef(0, 1, -120);
    wagon();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(theta - 21, 0, 1.0, 0);
    glTranslatef(0, 1, -120);
    wagon();
    glPopMatrix();
}