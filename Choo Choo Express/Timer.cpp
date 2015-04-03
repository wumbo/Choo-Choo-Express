//
//  Timer.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 2/04/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <GL/freeglut.h>

#include "Timer.h"
#include "Train.h"
#include "Scene.h"
#include "Person.h"
#include "Signal.h"

void trainTimer(int value)
{
    if (value == 0 || value == 200) {
        Signal::color = GREEN;
        Train::theta += 2;
        glutPostRedisplay();
        value = 0;
    }
    if (Train::theta == 340) {
        Signal::color = RED;
        value++;
    }
    if (Train::theta == 360) {
        Train::theta = 0;
    }
    glutTimerFunc(25, trainTimer, value);
}

void carTimer(int value)
{
    if (Scene::currentCar->dist >-300)
        Scene::currentCar->dist -= 2;
    else
        Scene::currentCar = new Car(300);
    glutPostRedisplay();
    glutTimerFunc(25, carTimer, 0);
}

void personTimer(int value)
{
    if (value == -1) {
        if (Person::armRot == -90) {
            value = 1;
        } else {
            Person::armRot -= 3;
        }
    } else {
        if (Person::armRot == 0) {
            value = -1;
        } else {
            Person::armRot += 3;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(25, personTimer, value);
}