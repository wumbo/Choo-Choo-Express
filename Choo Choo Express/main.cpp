//
//  main.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 19/03/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <iostream>

#include "App.h"
#include <GL/freeglut.h>

int main(int argc, char * argv[])
{
    App *app = new App(&argc, argv);
    app->mainLoop();
    
    return 0;
}
