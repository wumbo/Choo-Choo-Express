//
//  App.h
//  Choo Choo Express
//
//  Created by Simon Crequer on 19/03/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#ifndef __Choo_Choo_Express__App__
#define __Choo_Choo_Express__App__

#include <stdio.h>
#include <GL/freeglut.h>
#include <string>

#define NUM_TEXTURES 8

class App
{
private:
    void newWindow(char *title, int width, int height);
    void initGL();
public:
    static GLUquadric *q;
    static GLuint texId[NUM_TEXTURES];
    static std::string texPath;
    App(int *argc, char** argv);
    void mainLoop();
};

#endif /* defined(__Choo_Choo_Express__App__) */
