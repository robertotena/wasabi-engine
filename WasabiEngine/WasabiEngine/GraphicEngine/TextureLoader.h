/* 
 * File:   TextureLoader.h
 * Author: Roberto
 *
 * Created on 2 de marzo de 2011, 20:59
 */

#ifndef TEXTURELOADER_H
#define	TEXTURELOADER_H

#include <string>
#include <iostream>
#include <stdio.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>
#include <WasabiEngine/Utils/PropertyMap.h>

namespace WasabiEngine
{

class TextureLoader {
private:
    static PropertyMap<unsigned int, std::string> textureMap;
public:
    static unsigned int load(const std::string& file);
    static void unloadAll();
};

}

#endif	/* TEXTURELOADER_H */

