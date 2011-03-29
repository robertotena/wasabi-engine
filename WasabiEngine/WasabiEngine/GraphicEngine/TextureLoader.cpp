/* 
 * File:   TextureLoader.cpp
 * Author: Roberto
 * 
 * Created on 2 de marzo de 2011, 20:59
 */

#include "TextureLoader.h"

using namespace WasabiEngine;

PropertyMap<unsigned int, std::string> TextureLoader::textureMap;

unsigned int TextureLoader::load(const std::string& file) {
    unsigned int textureId;
    unsigned int* id = textureMap.get(file);
    if (id != NULL)
        return *id;

    SDL_Surface *image;
    SDL_RWops* rwop;
    GLint format;
    rwop = SDL_RWFromFile(file.data(), "rb");
    image = IMG_LoadJPG_RW(rwop);
    if (image == NULL) {
        std::cerr << "Can not load the texture file " << file << std::endl;
        return GL_INVALID_VALUE;
    }

    //Check that the image's width is a power of 2
    if ((image->w & (image->w - 1)) != 0) {
        std::cerr << "Warning: " << file << " width is not a power of 2" << std::endl;
    }
    //Also check if the height is a power of 2
    if ((image->h & (image->h - 1)) != 0) {
        std::cerr << "Warning: " << file << " height is not a power of 2" << std::endl;
    }
    //Get the number of channels in the SDL surface
    switch (image->format->BytesPerPixel) {
        case 4: // contains an alpha channel
            if (image->format->Rmask == 0x000000ff)
                format = GL_RGBA;
            else
                format = GL_BGRA;
            break;
        case 3:// no alpha channel
            if (image->format->Rmask == 0x000000ff)
                format = GL_RGB;
            else
                format = GL_BGR;
            break;
        default:
            std::cerr << "Warning: " << file << "is not truecolor. Aborting." << std::endl;
            return GL_INVALID_VALUE;
    }

    glGenTextures(1, &textureId);
    textureMap.set(file, textureId);
    glBindTexture(GL_TEXTURE_2D, textureId); // Typical Texture Generation Using Data From The Bitmap
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Linear Filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // Linear Filtering
    glTexImage2D(GL_TEXTURE_2D, 0, image->format->BytesPerPixel, image->w, image->h, 0, format, GL_UNSIGNED_BYTE, image->pixels); // Generate The Texture
    // GL_NEAREST  en lugar de linear si va muy justo

    SDL_FreeSurface(image);

    return textureId;
}

void TextureLoader::unloadAll() {
    textureMap.clear();
    std::list<unsigned int> textureList = textureMap.getItems();
    for (std::list<unsigned int>::iterator it = textureList.begin(); it != textureList.end(); it++)
        glDeleteTextures(1, &(*it));
}
