//
//  App.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 19/03/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <GL/freeglut.h>
#include <string>

#include "App.h"
#include "Scene.h"
#include "Camera.h"
#include "Texture.h"
#include "Timer.h"

GLUquadric *App::q;
GLuint App::texId[NUM_TEXTURES];
string App::texPath = "/Users/simon/Documents/Xcode/Choo Choo Express/Choo Choo Express/";

void display();

App::App(int *pargc, char** argv)
{
    glutInit(pargc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    
    char title[] = "Choo Choo Express";
    this->newWindow(title, 800, 600);
    
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    
    glutTimerFunc(25, trainTimer, 0);
    glutTimerFunc(25, carTimer, 0);
    glutTimerFunc(25, personTimer, -1);
    
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
    glGenTextures(NUM_TEXTURES, texId);
    // Load Texture ======================================================
    glBindTexture(GL_TEXTURE_2D, texId[0]);
    Texture(BMP, texPath + "floor.bmp");
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    // *** left ***
    glBindTexture(GL_TEXTURE_2D, texId[1]);
    Texture(BMP, texPath + "left.bmp");
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    // *** front ***
    glBindTexture(GL_TEXTURE_2D, texId[2]);
    Texture(BMP, texPath + "front.bmp");
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    // *** right ***
    glBindTexture(GL_TEXTURE_2D, texId[3]);
    Texture(BMP, texPath + "right.bmp");
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    // *** back***
    glBindTexture(GL_TEXTURE_2D, texId[4]);
    Texture(BMP, texPath + "back.bmp");
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    // *** top ***
    glBindTexture(GL_TEXTURE_2D, texId[5]);
    Texture(TGA, texPath + "top.tga");
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    glBindTexture(GL_TEXTURE_2D, texId[6]);
    Texture(BMP, texPath + "road.bmp");
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glBindTexture(GL_TEXTURE_2D, texId[7]);
    Texture(BMP, texPath + "brick.bmp");
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //====================================================================
    
    float grey[4] = {0.2, 0.2, 0.2, 1.0};
    float white[4]  = {1.0, 1.0, 1.0, 1.0};
    
    q = gluNewQuadric();
    
    // Lighting ==========================================================
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, grey);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialf(GL_FRONT, GL_SHININESS, 50);
    //====================================================================
    
    // Fog ===============================================================
    //glEnable(GL_FOG);
    //float fogColor[3]={0.8, 0.8, 0.8};
    //glFogfv(GL_FOG_COLOR, fogColor);
    //glFogi(GL_FOG_MODE, GL_LINEAR);
    //glFogf(GL_FOG_START, 50.0);
    //glFogf(GL_FOG_END, 12000.0);
    //glFogf(GL_FOG_DENSITY, 1.0);
    //====================================================================
    
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    gluQuadricDrawStyle(q, GLU_FILL);
    glClearColor (0, 0, 0, 0);  //Background colour
    
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(60., 1.0, 10.0, 100000.0);    //Perspective projection
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
    
    //glutPostRedisplay();
    glutSwapBuffers();
}