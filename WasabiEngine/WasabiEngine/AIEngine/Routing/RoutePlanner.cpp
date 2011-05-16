/* 
 * File:   RoutePlanner.cpp
 * Author: Fran_2
 * 
 * Created on 10 de enero de 2011, 12:42
 */

#include "RoutePlanner.h"
#include "WasabiEngine/GraphicEngine/GraphicEngine.h"

using namespace WasabiEngine;

const int RoutePlanner::DEFAULT_NUMBER_OF_NODES = 16;

RoutePlanner::RoutePlanner() : factory(DEFAULT_NUMBER_OF_NODES) {
    debugDraw = false;
    debugGraphicObject = NULL;
}

RoutePlanner::RoutePlanner(const RoutePlanner& orig) {
    //Copy not allowed
}

RoutePlanner::~RoutePlanner() {
}

RouteNode* RoutePlanner::getNode(const int& nodeId) {
    RouteNode** node = map.get(nodeId);
    if (node != NULL)
        return *node;
    return NULL;
}

RouteNode* RoutePlanner::createNode(const int& nodeId, const WasVec2d& position) {
    RouteNode* node = factory.createResource();
    node->prepare(nodeId, position);
    map.set(nodeId, node);
    return node;
}

void RoutePlanner::destroyNode(RouteNode* node) {
    map.remove(node->getNodeId());
    factory.returnResource(node);
}

RouteNode* RoutePlanner::closestNode(const WasVec2d& position) {
    RouteNode* node = NULL;

    std::list<RouteNode*> nodeList = map.getItems();
    std::list<RouteNode*>::iterator it;
    float minDistance, distance;

    for (it = nodeList.begin(); it != nodeList.end(); it++) {
        if (node == NULL) {
            minDistance = (*it)->getPosition().distance(position);
            node = (*it);
        } else {
            distance = (*it)->getPosition().distance(position);
            if (distance < minDistance) {
                minDistance = distance;
                node = (*it);
            }
        }
    }

    return node;
}

void RoutePlanner::activateDebugDraw(bool activate) {
    if (activate) {
        debugGraphicObject = GraphicEngine::getInstance()->createObject(getId());
        std::list<RouteNode*> nodes = map.getItems();
        for (std::list<RouteNode*>::iterator i = nodes.begin(); i != nodes.end(); i++) {
            //Draw node
            RouteNode* node = *i;
            GraphicObject* object = debugGraphicObject->createChild(WasVec3d(node->position.x, 0, node->position.y));
            object->scale(WasVec3d(0.5, 0.5, 0.5));
            Entity* entity = object->createEntity(PT_CUBE);
            entity->setColor(ColourValue::BLUE);
            //Draw paths
            Vertex v1 = {node->position.x, 0, -node->position.y};
            for (std::map<int, int>::iterator j = node->routeMap.begin(); j != node->routeMap.end(); j++) {
                if (j->first == j->second) {
                    MeshPrototype prototype(WASABI_LINES);
                    Face face;
                    Vertex v2 = {getNode(j->first)->position.x, 0, - getNode(j->first)->position.y};
                    face.addVertex(v1);
                    face.addVertex(v2);
                    prototype.addFace(face);
                    Entity* entity = debugGraphicObject->createEntity(prototype);
                    entity->setColor(ColourValue::BLUE);
                }
            }
        }
    } else if (debugGraphicObject != NULL) {
        GraphicEngine::getInstance()->destroyObject(debugGraphicObject);
    }
    debugDraw = activate;
}
