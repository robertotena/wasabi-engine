/* 
 * File:   RoutePlanner.h
 * Author: Fran_2
 *
 * Created on 10 de enero de 2011, 12:42
 */

#ifndef ROUTEPLANNER_H
#define	ROUTEPLANNER_H

#include <WasabiEngine/Utils/ResourceFactory.h>
#include <WasabiEngine/Utils/PropertyMap.h>
#include <WasabiEngine/AIEngine/Routing/RouteNode.h>
#include <WasabiEngine/GameEngine/GameObject.h>
#include <WasabiEngine/GraphicEngine/GraphicEngine.h>

namespace WasabiEngine {

    /**
    * A Route planner.
    *
    */
    class RoutePlanner : public GameObject {
    private:
        static const int DEFAULT_NUMBER_OF_NODES;
        
        GraphicObject* debugGraphicObject;
        bool debugDraw;
        ResourceFactory<RouteNode> factory;
        PropertyMap<RouteNode*> map;
        RoutePlanner(const RoutePlanner& orig);
    public:
        RoutePlanner();
        virtual ~RoutePlanner();
        RouteNode* getNode(const int& nodeId);
        RouteNode* createNode(const int& nodeId, const WasVec2d& position);
        void destroyNode(RouteNode* node);
        void destroyAllNodes();
        RouteNode* closestNode(const WasVec2d& position);
        void activateDebugDraw(bool activate);
    };
}

#endif	/* ROUTEPLANNER_H */

