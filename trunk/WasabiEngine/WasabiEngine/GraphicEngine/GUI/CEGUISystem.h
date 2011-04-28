/* 
 * File:   CEGUISystem.h
 * Author: Roberto
 *
 * Created on 26 de abril de 2011, 23:35
 */

#ifndef CEGUISYSTEM_H
#define	CEGUISYSTEM_H

#include <SDL/SDL_opengl.h>
#include <cegui/CEGUI.h>
#include <cegui/CEGUISchemeManager.h>
#include <cegui/RendererModules/OpenGL/CEGUIOpenGLRenderer.h>
#include <WasabiEngine/GraphicEngine/GUI/CEGUIKeyboardInjectorHandler.h>
#include <WasabiEngine/GraphicEngine/GUI/CEGUIResizeInjectorHandler.h>
#include <WasabiEngine/GraphicEngine/GUI/CEGUIMouseMotionInjectorHandler.h>
#include <WasabiEngine/GraphicEngine/GUI/CEGUIMouseButtonInjectorHandler.h>

namespace WasabiEngine
{

class CEGUISystem {
private:
    CEGUI::Window* rootWindow;
    CEGUIKeyboardInjectorHandler keyboardInjector;
    CEGUIResizeInjectorHandler resizeInjector;
    CEGUIMouseMotionInjectorHandler mouseMotionInjector;
    CEGUIMouseButtonInjectorHandler mouseButtonInjector;

    CEGUISystem(const CEGUISystem& orig);
    CEGUISystem();
    /**
     * Initializes the system
     */
    void init();
    /**
     * Clears the system contents
     */
    void finish();
     /**
     * Render the GUI
     */
    void render();
public:
    ~CEGUISystem();
    bool isInitted();
    static CEGUISystem* getInstance();
    /**
     * Loads and sets a CEGUI window scheme.
     * @param schemePath Path to the scheme
     */
    void setWindowScheme(const std::string schemePath);
    /**
     * Loads a CEGUI window layout.
     * @param layoutPath Path to the layout
     */
    CEGUI::Window* loadWindowLayout(const std::string layoutPath);
    void attachToRoot(CEGUI::Window* window);
    /**
     * Destroys a CEGGUI Window
     * @param window the window to destroy
     */
    void destroyWindow(CEGUI::Window* window);
    /**
     * Destroys all CEGUI windows.
     */
    void destroyAllWindows();
    /**
     * Loads a mouse cursor
     * @param mouseScheme Name of the CEGUI imageSet
     */
    void setMouseCursor(const std::string mouseScheme);
    
    friend class GraphicEngine;
    friend class RenderSystem;
};

inline CEGUISystem* CEGUISystem::getInstance() {
    static CEGUISystem instance;
    return &instance;
}

}

#endif	/* CEGUISYSTEM_H */

