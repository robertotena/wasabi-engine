/* 
 * File:   CEGUISystem.cpp
 * Author: Roberto
 * 
 * Created on 26 de abril de 2011, 23:35
 */

#include "CEGUISystem.h"

using namespace WasabiEngine;

CEGUISystem::CEGUISystem() {
}

CEGUISystem::CEGUISystem(const CEGUISystem& orig) {
    // Singleton, not allowed
}

CEGUISystem::~CEGUISystem() {
}

void CEGUISystem::init()
{
    /* Initialize CEGUI */
    CEGUI::OpenGLRenderer::bootstrapSystem(CEGUI::OpenGLRenderer::TTT_NONE); //I don't know why, but NONE gives us the best frame rate in our PCs.
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

    // Add the main GUI system's root
    CEGUI::WindowManager::getSingleton().destroyAllWindows();
    rootWindow = CEGUI::WindowManager::getSingleton().createWindow("DefaultGUISheet", "WasabiRoot");
    CEGUI::System::getSingleton().setGUISheet(rootWindow);
}

void CEGUISystem::finish()
{
    CEGUI::WindowManager::getSingleton().destroyAllWindows();
    CEGUI::OpenGLRenderer::destroySystem();
    rootWindow = NULL;
}

bool CEGUISystem::isInitted()
{
    return rootWindow != NULL;
}

void CEGUISystem::setWindowScheme(const std::string schemePath)
{
    CEGUI::SchemeManager::getSingleton().create(schemePath);
    CEGUI::System::getSingleton().setDefaultMouseCursor("Vanilla-Images", "MouseArrow");
}

CEGUI::Window* CEGUISystem::loadWindowLayout(const std::string layoutPath)
{
    return CEGUI::WindowManager::getSingleton().loadWindowLayout(layoutPath);
}

void CEGUISystem::attachToRoot(CEGUI::Window* window) {
    rootWindow->addChildWindow(window);
}

void CEGUISystem::destroyWindow(CEGUI::Window* window)
{
    rootWindow->removeChildWindow(window);
    CEGUI::WindowManager::getSingleton().destroyWindow(window);
}

void CEGUISystem::destroyAllWindows()
{
    if(isInitted())
    {
        CEGUI::WindowManager::getSingleton().destroyAllWindows();
        rootWindow = CEGUI::WindowManager::getSingleton().createWindow("DefaultGUISheet", "WasabiRoot");
        CEGUI::System::getSingleton().setGUISheet(rootWindow);
    }
}

void CEGUISystem::setMouseCursor(const std::string mouseScheme)
{
    CEGUI::System::getSingleton().setDefaultMouseCursor(mouseScheme, "MouseArrow");
    SDL_ShowCursor(SDL_DISABLE);
}

void CEGUISystem::render()
{
    if(isInitted())
    {
        static float lastTimePulse = 0.001 * WasabiTime::getTicks();
        float now = 0.001 * WasabiTime::getTicks();
        CEGUI::System::getSingleton().injectTimePulse(now - lastTimePulse); //CEGUI needs the time in seconds
        glDisable(GL_LIGHTING);
        CEGUI::System::getSingleton().renderGUI();
        lastTimePulse = now;
    }
}
