//
//  Train.h
//  Choo Choo Express
//
//  Created by Simon Crequer on 1/04/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#ifndef __Choo_Choo_Express__Train__
#define __Choo_Choo_Express__Train__

#include <stdio.h>

class Train
{
private:
    void track(float radius);
    void tracks();
    void base();
    void engine();
    void wagon();
public:
    void draw();
    static int theta; // Position of trian on tracks
};

#endif /* defined(__Choo_Choo_Express__Train__) */
