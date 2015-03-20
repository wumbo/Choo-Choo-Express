//
//  App.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 19/03/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <GL/freeglut.h>

#include "App.h"
#include "Scene.h"

#include "loadTGA.h"

GLUquadric *App::q;
int App::texId[1];

void display();

App::App(int *pargc, char** argv)
{
    glutInit(pargc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    
    char title[] = "Choo Choo Express";
    this->newWindow(title, 800, 600);
    
    this->initGL();
}

void App::newWindow(char *title, int width, int height)
{
    glutInitWindowSize(width, height);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);
}

void App::initGL()
{
    // Load Texture ======================================================
    glBindTexture(GL_TEXTURE_2D, texId[0]);
    loadTGA("Textures/top.tga");
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    //====================================================================
    
    float grey[4] = {0.2, 0.2, 0.2, 1.0};
    float white[4]  = {1.0, 1.0, 1.0, 1.0};
    
    q = gluNewQuadric();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, grey);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialf(GL_FRONT, GL_SHININESS, 50);
    
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    
    glEnable(GL_LIGHT1);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.01);
    glLightfv(GL_LIGHT1, GL_AMBIENT, grey);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT1, GL_SPECULAR, white);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    gluQuadricDrawStyle(q, GLU_FILL);
    glClearColor (0.0, 0.0, 0.0, 0.0);  //Background colour
    
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(60., 1.0, 10.0, 1000.0);    //Perspective projection
}

void App::mainLoop()
{
    glutDisplayFunc(display);
    glutMainLoop();
}

void display()
{
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    Scene *scene = new Scene();
    scene->draw();
    
    glutSwapBuffers();
}