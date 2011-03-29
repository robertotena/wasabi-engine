/* 
 * File:   RenderSystem.h
 * Author: Fran_2
 *
 * Created on 21 de febrero de 2011, 18:58
 */

#ifndef RENDERSYSTEM_H
#define	RENDERSYSTEM_H

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <stack>
#include <WasabiEngine/GraphicEngine/ColourValue.h>
#include <WasabiEngine/GraphicEngine/SceneNode.h>
#include <WasabiEngine/GraphicEngine/GraphicEngineConf.h>
#include <WasabiEngine/GraphicEngine/Camera.h>

namespace WasabiEngine {
    
    typedef struct {
        FogMode mode;
        ColourValue colour;
        float density;
        float linearStart;
        float linearEnd;
    } FogConf;

    class RenderSystem {
    private:
        FogConf fogConf;
        unsigned int fogMode[3];
        ColourValue ambientLightColor;
        WasVec3d ambientLightPosition;
        void applyLighting();
        void applyFog();
    public:
        RenderSystem();
        ~RenderSystem();
        void render(SceneNode* rootNode, Camera* camera);
        void setVideoMode(const GraphicEngineConf& conf);
        void setAmbientLight(const ColourValue& colour, const WasVec3d& position);
        void setFog(FogMode mode=FOG_NONE, const ColourValue& colour=ColourValue::WHITE, float density=1.0, float linearStart=0.0, float linearEnd=1.0);
    };
}

#endif	/* RENDERSYSTEM_H */

