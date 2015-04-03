//
//  Tunnel.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 2/04/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include "Tunnel.h"
#include "App.h"

void Tunnel::draw()
{
    glColor4f(0.2, 0.2, 0.2, 1);
    glPushMatrix();
    glTranslatef(0, 0, 150);
    gluCylinder(App::q, 20, 20, 700, 30, 30);
    glPopMatrix();
}