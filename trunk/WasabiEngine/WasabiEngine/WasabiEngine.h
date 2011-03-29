/* 
 * File:   WasabiEngine.h
 * Author: Fran_2
 *
 * Created on 3 de diciembre de 2010, 19:34
 */

#ifndef WASABIENGINE_H
#define	WASABIENGINE_H

/* Game Engine */
#include <WasabiEngine/GameEngine/Actor.h>
#include <WasabiEngine/GameEngine/GameLoop.h>
#include <WasabiEngine/GameEngine/GameObject.h>
#include <WasabiEngine/GameEngine/GameObjectManager.h>
#include <WasabiEngine/GameEngine/GameSystemManager.h>
#include <WasabiEngine/GameEngine/QuitHandler.h>
#include <WasabiEngine/GameEngine/Scenery.h>
#include <WasabiEngine/GameEngine/SceneryFactory.h>
#include <WasabiEngine/GameEngine/SceneryDefinition.h>
#include <WasabiEngine/GameEngine/Sensor.h>
#include <WasabiEngine/GameEngine/SensorFactory.h>
#include <WasabiEngine/GameEngine/SensorHandler.h>
#include <WasabiEngine/GameEngine/GameWorld3D.h>

/* Event Engine */
#include <WasabiEngine/EventEngine/Event.h>
#include <WasabiEngine/EventEngine/EventEngine.h>
#include <WasabiEngine/EventEngine/EventHandler.h>
#include <WasabiEngine/EventEngine/EventPeeper.h>
#include <WasabiEngine/EventEngine/EventFactory.h>
#include <WasabiEngine/EventEngine/EventPeeper.h>
#include <WasabiEngine/EventEngine/EventProperty.h>
#include <WasabiEngine/EventEngine/HandlerRegistration.h>
#include <WasabiEngine/EventEngine/KeyState.h>
#include <WasabiEngine/EventEngine/KeyType.h>
#include <WasabiEngine/EventEngine/KeyboardEventHandler.h>
#include <WasabiEngine/EventEngine/QuitEventHandler.h>
#include <WasabiEngine/EventEngine/SDL_PumpEventsWrapper.h>
#include <WasabiEngine/EventEngine/ContactEventHandler.h>

/* Graphic Engine */
#include <WasabiEngine/GraphicEngine/GraphicEngine.h>
#include <WasabiEngine/GraphicEngine/Mesh.h>
#include <WasabiEngine/GraphicEngine/GraphicObject.h>

/* Physic Engine */
#include <WasabiEngine/PhysicEngine/PhysicEngine.h>
#include <WasabiEngine/PhysicEngine/PhysicObject.h>

/* AI Engine */
#include <WasabiEngine/AIEngine/FuzzyModule/FuzzyModule.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FuzzyParser.h>
#include <WasabiEngine/AIEngine/FSM/State.h>
#include <WasabiEngine/AIEngine/FSM/StateMachine.h>
#include <WasabiEngine/AIEngine/Routing/RoutePlanner.h>
#include <WasabiEngine/AIEngine/Routing/RouteNode.h>
#include <WasabiEngine/AIEngine/Goals/Goal.h>
#include <WasabiEngine/AIEngine/Goals/GoalComposite.h>

/* Optimization Engine */
#include <WasabiEngine/OptimizationEngine/LPSolver.h>

/* Utils */
#include <WasabiEngine/Utils/ConfigurationFileParser.h>
#include <WasabiEngine/Utils/ResourceFactory.h>
#include <WasabiEngine/Utils/PropertyMap.h>
#include <WasabiEngine/Utils/WasabiTime.h>
#include <WasabiEngine/Utils/MathUtil.h>
#include <WasabiEngine/Utils/Vectors.h>
#include <WasabiEngine/Utils/SuperFastHash.h>

/* TinyXML */
#include <TinyXML/tinyxml.h>

#endif	/* WASABIENGINE_H */

