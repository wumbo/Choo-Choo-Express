//
//  Keyboard.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 22/03/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <GL/freeglut.h>

#include "Camera.h"
#include "Scene.h"
#include <stdio.h>
#include <iostream>

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 'v':
            if (Scene::cameraAngle == OVERHEAD)
                Scene::cameraAngle = DRIVER;
            else if (Scene::cameraAngle == DRIVER)
                Scene::cameraAngle = WHEEL;
            else if (Scene::cameraAngle == WHEEL)
                Scene::cameraAngle = PLATFORM;
            else if (Scene::cameraAngle == PLATFORM)
                Scene::cameraAngle = CITY;
            else if (Scene::cameraAngle == CITY)
                Scene::cameraAngle = OVERHEAD;
            break;
    }
    glutPostRedisplay();
}

void special(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            Scene::cam_hgt += 2;
            break;
        case GLUT_KEY_LEFT:
            Scene::cam_rot -= 0.03;
            break;
        case GLUT_KEY_DOWN:
            if (Scene::cam_hgt > 10)
                Scene::cam_hgt -= 2;
            break;
        case GLUT_KEY_RIGHT:
            Scene::cam_rot += 0.03;
            break;
    }
    
    glutPostRedisplay();
}