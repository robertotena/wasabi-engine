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
#include <map>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>
namespace WasabiEngine
{

class TextureLoader {
private:
    static std::map<std::string, unsigned int> textureMap;
    static unsigned int bind(unsigned int textureId, const std::string& file);
public:
    static unsigned int load(const std::string& file);
    static void reload();
    static void unloadAll();
};

}

#endif	/* TEXTURELOADER_H */

