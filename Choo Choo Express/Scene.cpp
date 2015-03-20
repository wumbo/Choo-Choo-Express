//
//  Scene.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 19/03/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include "Scene.h"
#include "App.h"

void Scene::draw()
{
    float lgt_pos[] = {0.0f, 50.0f, 0.0f, 1.0f};  //light0 position (directly above the origin)
    
    gluLookAt (-80, 50, 180, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glLightfv(GL_LIGHT0, GL_POSITION, lgt_pos);    //light position
    glColor4f(0.2, 0.2, 0.2, 1.0);
    
    float white[4] = {1., 1., 1., 1.};
    float black[4] = {0};
    glColor4f(0.7, 0.7, 0.7, 1.0);
    glNormal3f(0.0, 1.0, 0.0);
    glMaterialfv(GL_FRONT, GL_SPECULAR, black);  //No specular reflections from the floor.
    
    //The floor is made up of several tiny squares on a 200x200 grid. Each square has a unit size.
    glBegin(GL_QUADS);
    for(int i = -200; i < 200; i++)
    {
        for(int j = -200;  j < 200; j++)
        {
            glVertex3f(i, 0.0, j);
            glVertex3f(i, 0.0, j+1);
            glVertex3f(i+1, 0.0, j+1);
            glVertex3f(i+1, 0.0, j);
        }
    }
    glEnd();
    
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);  //Enable specular reflections for remaining objects
    
    glPushMatrix();
    glTranslatef(0, 20, 0);
    glutSolidTeapot(20);
    
    glPopMatrix();
}