//
//  Scene.h
//  Choo Choo Express
//
//  Created by Simon Crequer on 19/03/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#ifndef __Choo_Choo_Express__Scene__
#define __Choo_Choo_Express__Scene__

#include <stdio.h>

#include "Car.h"

enum camera_angle_t {
    OVERHEAD,
    DRIVER,
    WHEEL,
    PLATFORM,
    CITY
};

class Scene
{
private:
    
public:
    static int cam_hgt;
    static float cam_rot;
    static int camx;
    static int camy;
    static camera_angle_t cameraAngle;
    static Car *currentCar;
    void draw();
};

#endif /* defined(__Choo_Choo_Express__Scene__) */
