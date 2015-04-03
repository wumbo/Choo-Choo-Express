//
//  Signal.h
//  Choo Choo Express
//
//  Created by Simon Crequer on 2/04/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#ifndef __Choo_Choo_Express__Signal__
#define __Choo_Choo_Express__Signal__

#include <stdio.h>

enum sig_color_t {
    RED,
    GREEN
};

class Signal
{
private:
    
public:
    void draw();
    static sig_color_t color;
};

#endif /* defined(__Choo_Choo_Express__Signal__) */
