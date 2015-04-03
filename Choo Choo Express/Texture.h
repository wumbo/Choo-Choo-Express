//
//  Texture.h
//  Choo Choo Express
//
//  Created by Simon Crequer on 23/03/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#ifndef __Choo_Choo_Express__Texture__
#define __Choo_Choo_Express__Texture__

#include <stdio.h>
#include <string>

using namespace std;

enum tex_filetype_t {
    BMP,
    TGA
};

class Texture
{
private:
    void loadBMP(string filename);
    void loadTGA(string filename);
public:
    Texture(tex_filetype_t filetype, string filename);
};

#endif /* defined(__Choo_Choo_Express__Texture__) */
