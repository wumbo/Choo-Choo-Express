//
//  Station.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 2/04/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <GL/freeglut.h>

#include "Station.h"
#include "App.h"

void Station::draw()
{
    glPushMatrix();
    
    glRotatef(330, 0, 1, 0);
    glTranslatef(0, 0, -145);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, App::texId[7]);
    glBegin(GL_QUADS);
    {
        // Main building ================
        glTexCoord2f(0, 0);     glVertex3f(-20, 0, 0);
        glTexCoord2f(1, 0);     glVertex3f(20, 0, 0);
        glTexCoord2f(1, 1);     glVertex3f(20, 30, 0);
        glTexCoord2f(0, 1);     glVertex3f(-20, 30, 0);
        
        glTexCoord2f(0, 0);
        glVertex3f(20, 0, 0);
        glTexCoord2f(1, 0);
        glVertex3f(20, 0, -30);
        glTexCoord2f(1, 1);
        glVertex3f(20, 30, -30);
        glTexCoord2f(0, 1);
        glVertex3f(20, 30, 0);
        
        glTexCoord2f(0, 0);
        glVertex3f(20, 0, -30);
        glTexCoord2f(1, 0);
        glVertex3f(-20, 0, -30);
        glTexCoord2f(1, 1);
        glVertex3f(-20, 30, -30);
        glTexCoord2f(0, 1);
        glVertex3f(20, 30, -30);
        
        glTexCoord2f(0, 0);
        glVertex3f(-20, 0, -30);
        glTexCoord2f(1, 0);
        glVertex3f(-20, 0, 0);
        glTexCoord2f(1, 1);
        glVertex3f(-20, 30, 0);
        glTexCoord2f(0, 1);
        glVertex3f(-20, 30, -30);
        
        glTexCoord2f(0, 0);
        glVertex3f(-20, 30, 0);
        glTexCoord2f(1, 0);
        glVertex3f(20, 30, 0);
        glTexCoord2f(1, 1);
        glVertex3f(20, 30, -30);
        glTexCoord2f(0, 1);
        glVertex3f(-20, 30, -30);
        // ==============================
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    glColor4f(0.3, 0.3, 0.3, 1);
    glBegin(GL_QUADS);
    {
        // Platform =====================
        glNormal3f(0, 0, 1);
        glVertex3f(-20, 0, 15);
        glVertex3f(20, 0, 15);
        glVertex3f(20, 8, 15);
        glVertex3f(-20, 8, 15);
        
        glNormal3f(1, 0, 0);
        glVertex3f(20, 0, 15);
        glVertex3f(20, 0, 0);
        glVertex3f(20, 8, 0);
        glVertex3f(20, 8, 15);
        
        glNormal3f(0, 0, -1);
        glVertex3f(20, 0, 0);
        glVertex3f(-20, 0, 0);
        glVertex3f(-20, 8, 0);
        glVertex3f(20, 8, 0);
        
        glNormal3f(-1, 0, 0);
        glVertex3f(-20, 0, 0);
        glVertex3f(-20, 0, 15);
        glVertex3f(-20, 8, 15);
        glVertex3f(-20, 8, 0);
        
        glNormal3f(0, 1, 0);
        glVertex3f(-20, 8, 15);
        glVertex3f(20, 8, 15);
        glVertex3f(20, 8, 0);
        glVertex3f(-20, 8, 0);
        // ==============================
    }
    glEnd();
    
    glPopMatrix();
}