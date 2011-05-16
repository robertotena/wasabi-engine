/* 
 * File:   GraphicEngine.h
 * Author: fran
 *
 * Created on 21 de noviembre de 2010, 17:10
 */

#ifndef GRAPHICENGINE_H
#define	GRAPHICENGINE_H

#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <WasabiEngine/Utils/MathUtil.h>
#include <WasabiEngine/Utils/ResourceFactory.h>
#include <WasabiEngine/Utils/PropertyMap.h>
#include <WasabiEngine/EventEngine/EventEngine.h>
#include <WasabiEngine/GraphicEngine/LightPoint.h>
#include <WasabiEngine/GraphicEngine/GraphicObject.h>
#include <WasabiEngine/GraphicEngine/SceneManager.h>
#include <WasabiEngine/GraphicEngine/GraphicEngineConf.h>
#include <WasabiEngine/GraphicEngine/GUI/CEGUISystem.h>

namespace WasabiEngine {

    /**
     * Facade to Graphic Engine. It allows to create and render graphic objects.
     */
    class GraphicEngine {
    private:
        static const int DEFAULT_INITIAL_CAPACITY = 512;
        ResourceFactory<GraphicObject> objectFactory;
        PropertyMap<GraphicObject*> propertyMap;
        GraphicEngine(const GraphicEngine& orig);
        SceneManager sceneManager;
        
        void destroyObjects();
    public:
        GraphicEngine();
        void setVideoMode(const GraphicEngineConf& conf);
        ~GraphicEngine();
        /**
         * Obtains the item with the ID "id" or NULL if it not exists.
         * @param id The id of the object
         * @return The object or NULL if it not exists.
         */
        GraphicObject* getItem(const int& id);
        /**
         * Creates a graphic object with an ID "id"
         * @param id The id of the object
         * @return The created object
         */
        GraphicObject* createObject(const int& id);
        /**
         * Destroys a GraphicObject
         * @param object The object to destroy
         */
        void destroyObject(GraphicObject* object);
        /**
         * Creates a camera.
         * @param name The name of the camera
         * @return The camera object
         */
        Camera* createCamera(const std::string& name);
        void destroyCamera(Camera* camera);
        void destroyCamera(const std::string& name);
        void setActiveCamera(Camera* camera);
        void setActiveCamera(const std::string& name);
        Camera* getCamera(const std::string& name);
        Camera* getActiveCamera();
        void setWorldGeometry(const std::string& filePath);
        void setAmbientLight(const ColourValue& colour, const WasVec3d& position);
        LightPoint* createLightPoint();
        SpotLight* createSpotLight();
        void destroyLight(Light* light);
        
        /**
         * Render a frame
         */
        void render();
        /**
         * Initializes the engine
         */
        void init();
        /**
         * Clears the engine contents
         */
        void finish();
        static GraphicEngine* getInstance();

        friend class GraphicObject;
    };

    inline GraphicObject* GraphicEngine::getItem(const int& id) {
        GraphicObject** obj = propertyMap.get(id);
        if (obj != NULL)
            return *obj;
        return NULL;
    }

    inline GraphicEngine* GraphicEngine::getInstance() {
        static GraphicEngine instance;
        return &instance;
    }
}

#endif	/* GRAPHICENGINE_H */
