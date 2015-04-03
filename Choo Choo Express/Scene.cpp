//
//  Scene.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 19/03/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include "Scene.h"
#include "App.h"
#include "Floor.h"
#include "Train.h"
#include "Skybox.h"
#include "Station.h"
#include "Car.h"
#include "Person.h"
#include "House.h"
#include "Tower.h"
#include "Tunnel.h"
#include "Signal.h"

#include <math.h>

int Scene::cam_hgt = 50;
float Scene::cam_rot = 0;
int Scene::camx = 0;
int Scene::camy = 0;
camera_angle_t Scene::cameraAngle = OVERHEAD;
Car *Scene::currentCar = new Car(300);

void Scene::draw()
{
    float lgt_pos[] = {50000.0f, 50000.0f, 50000.0f, 1.0f};
    
    if (cameraAngle == OVERHEAD) {
        float camx = sin(cam_rot) > 0 ? sin(cam_rot)*100 : sin(cam_rot)*100;
        float camz = cos(cam_rot) > 0 ? cos(cam_rot)*100 : cos(cam_rot)*100;
        gluLookAt(camx, cam_hgt, camz, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    } else if (cameraAngle == DRIVER) {
        gluLookAt(-120*sin((Train::theta+5)*3.14/180), 10, -120*cos((Train::theta+5)*3.14/180), -120*sin((Train::theta+10)*3.14/180), 9, -120*cos((Train::theta+10)*3.14/180), 0, 1, 0);
    } else if (cameraAngle == PLATFORM) {
        gluLookAt(80, 20, -127, 0, -40, 0, 0, 1, 0);
    } else if (cameraAngle == WHEEL) {
        gluLookAt(-113*sin((Train::theta-5)*3.14/180), 10, -113*cos((Train::theta-5)*3.14/180), -120*sin((Train::theta+50)*3.14/180), 9, -120*cos((Train::theta+50)*3.14/180), 0, 1, 0);
    } else if (cameraAngle == CITY) {
        gluLookAt(200, 140, -250, -40, 70, -300, 0, 1, 0);
    }
    
    glLightfv(GL_LIGHT0, GL_POSITION, lgt_pos);
    
    glColor4f(1.0, 1.0, 1.0, 1.0);
    
    Skybox *skybox = new Skybox();
    skybox->draw();
    
    Floor *floor = new Floor();
    floor->draw();
    
    // Road
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, App::texId[6]);
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    for (int i = -9600; i < 9600; i+=15) {
        glTexCoord2f(0, 0);    glVertex3f(-15, 0.1, i);
        glTexCoord2f(1, 0);    glVertex3f(15, 0.1, i);
        glTexCoord2f(1, 1);    glVertex3f(15, 0.1, i+15);
        glTexCoord2f(0, 1);    glVertex3f(-15, 0.1, i+15);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
    
    Station *station = new Station();
    station->draw();
    
    Train *train = new Train();
    train->draw();
    
    currentCar->draw();
    
    Person *person = new Person();
    person->draw();
    
    House *house1 = new House(-250);
    house1->draw();
    
    House *house2 = new House(-300);
    house2->draw();
    
    House *house3 = new House(-350);
    house3->draw();
    
    Tower *tower1 = new Tower(-250);
    tower1->draw();
    
    Tower *tower2 = new Tower(-300);
    tower2->draw();
    
    Tower *tower3 = new Tower(-350);
    tower3->draw();
    
    Tunnel *tunnel = new Tunnel();
    tunnel->draw();
    
    Signal *signal = new Signal();
    signal->draw();
}