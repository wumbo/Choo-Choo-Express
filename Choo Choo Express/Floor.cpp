//
//  Floor.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 20/03/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <Gl/freeglut.h>

#include "App.h"
#include "Floor.h"

void Floor::draw()
{
    glColor4f(1, 1, 1, 1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, App::texId[0]);
    glBegin(GL_QUADS);
    
    for(int i = -10000; i < 10000; i+=30)
    {
        for(int j = -10000;  j < 10000; j+=30)
        {
            glTexCoord2d(0, 0); glVertex3f(i, 0.0, j);
            glTexCoord2d(0, 1); glVertex3f(i, 0.0, j+30);
            glTexCoord2d(1, 1); glVertex3f(i+30, 0.0, j+30);
            glTexCoord2d(1, 0); glVertex3f(i+30, 0.0, j);
        }
    }
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
}