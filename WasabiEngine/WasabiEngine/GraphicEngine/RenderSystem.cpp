/* 
 * File:   RenderSystem.cpp
 * Author: Fran_2
 * 
 * Created on 21 de febrero de 2011, 18:58
 */

#include "RenderSystem.h"
#include "Camera.h"
#include <iostream>

using namespace WasabiEngine;

RenderSystem::RenderSystem() : ambientLightColor(0.5, 0.5, 0.5, 1.0) {
    fogConf.mode = FOG_LINEAR;
    fogConf.density = 1.0;
    fogConf.linearStart = 30.0;
    fogConf.linearEnd = 100.0;
    fogConf.colour = ColourValue::BLACK;

    fogMode[0] = GL_EXP;
    fogMode[1] = GL_EXP2;
    fogMode[2] = GL_LINEAR;
}

RenderSystem::~RenderSystem() {
}

void RenderSystem::setVideoMode(const GraphicEngineConf& conf) {
    /* Create OpenGL screen */
    if (SDL_SetVideoMode(conf.width, conf.height, 0, SDL_OPENGL) == NULL) {
        fprintf(stderr, "Unable to create OpenGL screen: %s\n", SDL_GetError());
        SDL_Quit();
        exit(2);
    }

    /* Set the title bar in environments that support it */
    SDL_WM_SetCaption(conf.wmCaption.c_str(), NULL);

    /* Init OpenGL */
    glViewport(0, 0, conf.width, conf.height);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // This Will Clear The Background Color To Black
    glClearDepth(1.0); // Enables Clearing Of The Depth Buffer
    glEnable(GL_DEPTH_TEST); // Enables Depth Testing
    glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations
    glShadeModel(GL_SMOOTH); // Enables Smooth Color Shading
    glEnable(GL_LIGHTING);
    glEnable(GL_CULL_FACE); //Enables Culling

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // Reset The Projection Matrix

    gluPerspective(45.0f, (GLfloat) conf.width / (GLfloat) conf.height, 1.f, 100.0f); // Calculate The Aspect Ratio Of The Window

    glMatrixMode(GL_MODELVIEW);
}

void RenderSystem::render(SceneNode* rootNode, Camera* camera) {
    std::stack<SceneNode*> sceneStack;
    SceneNode* node;
    std::stack<unsigned int> childrenCounterStack;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer 
    glLoadIdentity(); // Reset The View

    //applying lights
    applyLighting();

    // applying fog
    applyFog();

    // render scene
    camera->renderObject();

    // draw axis
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glBegin(GL_LINES);
    // Eje Y
    glColor4f(0.2, 0.8, 0.0, 0.8);

    glVertex3f(0.00, 0.0, 0.0);
    glVertex3f(0.00, 3.0, 0.0);
    glVertex3f(0.00, 3.0, 0.0);
    glVertex3f(0.05, 2.7, 0.0);
    glVertex3f(0.00, 3.0, 0.0);
    glVertex3f(-0.05, 2.7, 0.0);

    // Eje X
    glColor4f(0.2, 0.0, 0.8, 0.8);

    glVertex3f(0.0, 0.01, 0.0);
    glVertex3f(3.0, 0.01, 0.0);
    glVertex3f(3.0, 0.01, 0.0);
    glVertex3f(2.7, 0.06, 0.0);
    glVertex3f(3.0, 0.01, 0.0);
    glVertex3f(2.7, -0.06, 0.0);

    // Eje Z
    glColor4f(0.8, 0.2, 0.0, 0.8);

    glVertex3f(0.0, 0.01, 0.0);
    glVertex3f(0.0, 0.01, 3.0);
    glVertex3f(0.0, 0.01, 3.0);
    glVertex3f(0.0, 0.06, 2.7);
    glVertex3f(0.0, 0.01, 3.0);
    glVertex3f(0.0, -0.06, 2.7);
    glEnd();

    node = rootNode;
    while (node != NULL) {
        glPushMatrix();
        childrenCounterStack.push(node->children.size());
        node->renderNode();
        std::list<SceneNode*>::reverse_iterator it;
        for (it = node->children.rbegin(); it != node->children.rend(); it++)
            sceneStack.push((*it));
        unsigned int nChildren = childrenCounterStack.top();
        childrenCounterStack.pop();
        while (nChildren == 0) {
            glPopMatrix();
            if (childrenCounterStack.empty())
                break;
            nChildren = childrenCounterStack.top();
            childrenCounterStack.pop();
        }
        childrenCounterStack.push(nChildren - 1);
        if (sceneStack.empty())
            node = NULL;
        else {
            node = sceneStack.top();
            sceneStack.pop();
        }
    }

    // swap buffers to display, since we're double buffered.
    SDL_GL_SwapBuffers();
    int glError = glGetError();
    if (glError != GL_NO_ERROR)
        std::cerr << "Rendered frame state: " << gluErrorString(glError) << std::endl;
}

void RenderSystem::setAmbientLight(const ColourValue& colour, const WasVec3d& position) {
    ambientLightColor = colour;
    ambientLightPosition = position;
}

void RenderSystem::setFog(FogMode mode, const ColourValue& colour, float density, float linearStart, float linearEnd) {
    fogConf.mode = mode;
    fogConf.colour = colour;
    fogConf.density = density;
    fogConf.linearStart = linearStart;
    fogConf.linearEnd = linearEnd;
}

void RenderSystem::applyLighting() {
    //FIXME: Esto no esta bien aplicado, deberia estar unido al arbol de transformaciones.
    float intensity_ambient[4] = {ambientLightColor.getRed(), ambientLightColor.getGreen(), ambientLightColor.getBlue(), ambientLightColor.getAlpha()};
    float intensity_diffuse[4] = {0.4, 0.4, 0.4, 1.0};
    float intensity_specular[4] = {0.2f, 0.2f, 0.2f, 1.0};
    float position[3] = {ambientLightPosition.x, ambientLightPosition.y, ambientLightPosition.z};

    // Habilita los materiales
    glEnable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT, GL_AMBIENT, intensity_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, intensity_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, intensity_specular);

    glLightfv(GL_LIGHT0, GL_AMBIENT, intensity_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, intensity_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, intensity_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_LIGHT0);
}

void RenderSystem::applyFog() {
    // FIXME: trastear con el fog_hint y el clearColor
    if (fogConf.mode != FOG_NONE) {
        float color[4] = {fogConf.colour.getRed(), fogConf.colour.getGreen(), fogConf.colour.getBlue(), fogConf.colour.getAlpha()};
        //glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // We'll Clear To The Color Of The Fog ( Modified )

        glFogi(GL_FOG_MODE, fogMode[fogConf.mode]); // Fog Mode
        glFogfv(GL_FOG_COLOR, color); // Set Fog Color
        glFogf(GL_FOG_DENSITY, fogConf.density); // How Dense Will The Fog Be
        glHint(GL_FOG_HINT, GL_DONT_CARE); // Fog Hint Value
        // depth only work when is linear
        glFogf(GL_FOG_START, fogConf.linearStart); // Fog Start Depth
        glFogf(GL_FOG_END, fogConf.linearEnd); // Fog End Depth
        glEnable(GL_FOG); // Enables GL_FOG
    } else
        glDisable(GL_FOG);
}
