//
//  Texture.cpp
//  Choo Choo Express
//
//  Created by Simon Crequer on 23/03/15.
//  Copyright (c) 2015 Simon Crequer. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <GL/freeglut.h>

#include "Texture.h"

using namespace std;

Texture::Texture(tex_filetype_t filetype, string filename)
{
    switch (filetype) {
        case BMP:
            loadBMP(filename);
            break;
            
        case TGA:
            loadTGA(filename);
            break;
    }
}

void Texture::loadBMP(string filename)
{
    char* imageData;
    char header1[18], header2[24];
    short int planes, bpp;
    int wid, hgt;
    int nbytes, size, indx, temp;
    ifstream file( filename.c_str(), ios::in | ios::binary);
    if(!file)
    {
        cout << "*** Error opening image file: " << filename.c_str() << endl;
        exit(1);
    }
    file.read (header1, 18);		//Initial part of header
    file.read ((char*)&wid, 4);		//Width
    file.read ((char*)&hgt, 4);		//Height
    file.read ((char*)&planes, 2);	//Planes
    file.read ((char*)&bpp, 2);		//Bits per pixel
    file.read (header2, 24);		//Remaining part of header
    
    //		cout << "Width =" << wid << "   Height = " << hgt << " Bpp = " << bpp << endl;
    
    nbytes = bpp / 8;           //No. of bytes per pixels
    size = wid * hgt * nbytes;  //Total number of bytes to be read
    imageData = new char[size];
    file.read(imageData, size);
    //Swap r and b values
    for(int i = 0; i < wid*hgt;  i++)
    {
        indx = i*nbytes;
        temp = imageData[indx];
        imageData[indx] = imageData[indx+2];
        imageData[indx+2] = temp;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, 3, wid, hgt, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
    delete imageData;
}

void Texture::loadTGA(string filename)
{
    char id, cmap, imgtype, bpp, c_garb;
    char* imageData, temp;
    short int s_garb, wid, hgt;
    int nbytes, size, indx;
    ifstream file( filename.c_str(), ios::in | ios::binary);
    if(!file)
    {
        cout << "*** Error opening image file: " << filename.c_str() << endl;
        exit(1);
    }
    file.read (&id, 1);
    file.read (&cmap, 1);
    file.read (&imgtype, 1);
    if(imgtype != 2 && imgtype != 3 )   //2= colour (uncompressed),  3 = greyscale (uncompressed)
    {
        cout << "*** Incompatible image type: " << (int)imgtype << endl;
        exit(1);
    }
    //Color map specification
    file.read ((char*)&s_garb, 2);
    file.read ((char*)&s_garb, 2);
    file.read (&c_garb, 1);
    //Image specification
    file.read ((char*)&s_garb, 2);  //x origin
    file.read ((char*)&s_garb, 2);  //y origin
    file.read ((char*)&wid, 2);     //image width
    file.read ((char*)&hgt, 2);     //image height
    file.read (&bpp, 1);     //bits per pixel
    file.read (&c_garb, 1);  //img descriptor
    nbytes = bpp / 8;           //No. of bytes per pixels
    size = wid * hgt * nbytes;  //Total number of bytes to be read
    imageData = new char[size];
    file.read(imageData, size);
    if(nbytes > 2)   //swap R and B
    {
        for(int i = 0; i < wid*hgt;  i++)
        {
            indx = i*nbytes;
            temp = imageData[indx];
            imageData[indx] = imageData[indx+2];
            imageData[indx+2] = temp;
        }
    }
    
    switch (nbytes)
    {
        case 1:
            glTexImage2D(GL_TEXTURE_2D, 0, 1, wid, hgt, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, imageData);
            break;
        case 3:
            glTexImage2D(GL_TEXTURE_2D, 0, 3, wid, hgt, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
            break;
        case 4:
            glTexImage2D(GL_TEXTURE_2D, 0, 4, wid, hgt, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
            break;
    }
    delete imageData;
}