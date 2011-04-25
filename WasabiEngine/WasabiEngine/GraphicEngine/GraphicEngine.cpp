/* 
 * File:   GraphicEngine.cpp
 * Author: fran
 * 
 * Created on 21 de noviembre de 2010, 17:10
 */

#include <list>

#include "GraphicEngine.h"
#include "WasabiEngine/EventEngine/EventEngine.h"

using namespace WasabiEngine;

GraphicEngine::GraphicEngine() {
}

GraphicEngine::GraphicEngine(const GraphicEngine& orig) {
    //Not allowed
}

GraphicEngine::~GraphicEngine() {
}

void GraphicEngine::setVideoMode(const GraphicEngineConf& conf) {
    sceneManager.renderSystem.setVideoMode(conf);
}

void GraphicEngine::setWorldGeometry(const std::string& filePath) {
    sceneManager.setWorldGeometry(filePath);
}

void GraphicEngine::setAmbientLight(const ColourValue& colour, const WasVec3d& position) {
    sceneManager.setAmbientLight(colour, position);
}

void GraphicEngine::render() {
    sceneManager.render();
}

GraphicObject* GraphicEngine::createObject(const int& id) {
    GraphicObject* object = objectFactory.createResource();
    object->setId(id);
    object->prepare();
    propertyMap.set(id, object);
    return object;
}

void GraphicEngine::destroyObject(GraphicObject* object) {
    propertyMap.remove(object->getId());
    objectFactory.returnResource(object);
}

Camera* GraphicEngine::createCamera(const std::string& name) {
    return sceneManager.createCamera(name);
}

void GraphicEngine::destroyCamera(Camera* camera) {
    sceneManager.destroyCamera(camera);
}

void GraphicEngine::destroyCamera(const std::string& name) {
    sceneManager.destroyCamera(name);
}

Camera* GraphicEngine::getActiveCamera() {
    return sceneManager.getActiveCamera();
}

void GraphicEngine::setActiveCamera(Camera* camera) {
    sceneManager.setActiveCamera(camera);
}

void GraphicEngine::setActiveCamera(const std::string& name) {
    sceneManager.setActiveCamera(name);
}

Camera* GraphicEngine::getCamera(const std::string& name) {
    return sceneManager.getCamera(name);
}

void GraphicEngine::setWindowScheme(const std::string schemePath) {
    CEGUI::SchemeManager::getSingleton().create(schemePath);
    CEGUI::System::getSingleton().setDefaultMouseCursor("Vanilla-Images", "MouseArrow");
}

CEGUI::Window* GraphicEngine::setWindowLayout(const std::string layoutPath) {
    CEGUI::WindowManager::getSingleton().destroyAllWindows();
    CEGUI::Window* myRoot = CEGUI::WindowManager::getSingleton().loadWindowLayout(layoutPath);
    CEGUI::System::getSingleton().setGUISheet(myRoot);
    return myRoot;
}

void GraphicEngine::destroyWindow(CEGUI::Window* window) {
    CEGUI::WindowManager::getSingleton().destroyWindow(window);
}

void GraphicEngine::destroyAllWindows() {
    CEGUI::WindowManager::getSingleton().destroyAllWindows();
}

void GraphicEngine::setMouseCursor(const std::string mouseScheme) {
    CEGUI::System::getSingleton().setDefaultMouseCursor(mouseScheme, "MouseArrow");
    SDL_ShowCursor(SDL_DISABLE);
}

void GraphicEngine::init() {
    /* Initialize SDL for video output. Watch out! It needs that SDL_Init() has been called first */
    if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    // Initialize SDL image formats to support
    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    int initted = IMG_Init(flags);
    if ((initted & flags) != flags) {
        fprintf(stderr, "IMG_Init: Failed to init required jpg and png support!\n");
        fprintf(stderr, "IMG_Init: %s\n", IMG_GetError());
    }

    GraphicEngineConf defaultConf;
    defaultConf.width = 800;
    defaultConf.height = 600;
    defaultConf.wmCaption = "WasabiEngine";
    setVideoMode(defaultConf);

    /* Initialize CEGUI */
    CEGUI::OpenGLRenderer::bootstrapSystem();
    CEGUI::DefaultResourceProvider* rp = static_cast<CEGUI::DefaultResourceProvider*> (CEGUI::System::getSingleton().getResourceProvider());
    rp->setResourceGroupDirectory("global", "Resources/GUI/");
    rp->setDefaultResourceGroup("global");
    //    if(! CEGUI::FontManager::getSingleton().isDefined( "DejaVuSans-10" ) )
    //         CEGUI::FontManager::getSingleton().createFreeTypeFont( "DejaVuSans-10", 1, true, "DejaVuSans.ttf", "Fonts" );
    //    if(! CEGUI::FontManager::getSingleton().isDefined( "SoulMission-m" ) )
    //         CEGUI::FontManager::getSingleton().createFreeTypeFont( "SoulMission-m", 1, true, "SoulMission.ttf", "Fonts" );
    //    if(! CEGUI::FontManager::getSingleton().isDefined( "SoulMission-l" ) )
    //         CEGUI::FontManager::getSingleton().createFreeTypeFont( "SoulMission-l", 1, true, "SoulMission.ttf", "Fonts" );
    CEGUI::FontManager::getSingleton().create("DejaVuSans-10.font");
    CEGUI::FontManager::getSingleton().create("SoulMission-m.font");
    CEGUI::System::getSingleton().setDefaultFont("SoulMission-m");
    EventEngine::getInstance()->addHandler(&keyboardInjector);
    EventEngine::getInstance()->addHandler(&resizeInjector);
    EventEngine::getInstance()->addHandler(&mouseMotionInjector);
    EventEngine::getInstance()->addHandler(&mouseButtonInjector);
}

void GraphicEngine::finish() {
    TextureLoader::unloadAll();
    MeshMap::unloadAll();
    destroyObjects();
    CEGUI::WindowManager::getSingleton().destroyAllWindows();
    CEGUI::OpenGLRenderer::destroySystem();
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void GraphicEngine::destroyObjects() {
    std::list<GraphicObject*> graphicObjects = propertyMap.getItems();
    std::list<GraphicObject*>::iterator it;
    for (it = graphicObjects.begin(); it != graphicObjects.end(); it++)
        destroyObject(*(it));
}
