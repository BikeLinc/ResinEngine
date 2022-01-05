/*****************************************************************//**
 * \file   Texture.h
 * \brief  Loads a image's texture into memory via the SOIL2 Image 
 *         Loading Library. Based on learnopengl.com and sonar 
 *         system's modern opengl tutorials on texture loading.
 *
 * \author Lincoln Scheer
 * \date   March 26 2021
***********************************************************************/

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GLFW/glfw3.h>
#include <SOIL2/SOIL2.h>

class Texture {
public:
    GLuint data;
    
    /**
     * Set member data to image texture.
     * 
     * \param imagePath
     */
    Texture(const char* imagePath) {
        data = loadTexture(imagePath);
    }

private:

    /**
     * Set texture paramaters for wrapping, minimizing and magnifying texture.
     * 
     */
    void setTextureParamaters() {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }

    /**
     * Load image from image's path into memory and return image texture;
     * 
     * \param imagePath
     * \return 
     */
    GLuint loadTexture(const char* imagePath) {
        GLuint texture;
        int width, height;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        setTextureParamaters();
        unsigned char* image = SOIL_load_image(imagePath, &width, &height, 0, SOIL_LOAD_RGBA);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        glGenerateMipmap(GL_TEXTURE_2D);
        SOIL_free_image_data(image);
        glBindTexture(GL_TEXTURE_2D, 0);
        return texture;
    }
};

#endif /* TEXTURE_H */