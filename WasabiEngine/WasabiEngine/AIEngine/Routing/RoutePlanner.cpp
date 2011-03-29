/* 
 * File:   RoutePlanner.cpp
 * Author: Fran_2
 * 
 * Created on 10 de enero de 2011, 12:42
 */

#include "RoutePlanner.h"

using namespace WasabiEngine;

const int RoutePlanner::DEFAULT_NUMBER_OF_NODES = 16;

RoutePlanner::RoutePlanner() : factory(DEFAULT_NUMBER_OF_NODES) {
}

RoutePlanner::RoutePlanner(const RoutePlanner& orig) {
    //Copy not allowed
}

RoutePlanner::~RoutePlanner() {
}

RouteNode* RoutePlanner::getNode(const int& nodeId){
    RouteNode** node = map.get(nodeId);
    if(node != NULL)
        return *node;
    return NULL;
}

RouteNode* RoutePlanner::createNode(const int& nodeId, const WasVec2d& position){
    RouteNode* node = factory.createResource();
    node->prepare(nodeId,position);
    map.set(nodeId, node);
    return node;
}

void RoutePlanner::destroyNode(RouteNode* node){
    map.remove(node->getNodeId());
    factory.returnResource(node);
}

RouteNode* RoutePlanner::closestNode(const WasVec2d& position)
{
    RouteNode* node = NULL;

    std::list<RouteNode*> nodeList = map.getItems();
    std::list<RouteNode*>::iterator it;
    float minDistance, distance;
    
    for(it = nodeList.begin(); it != nodeList.end(); it++)
    {
        if(node == NULL)
        {
            minDistance = (*it)->getPosition().distance(position);
            node = (*it);
        }
        else
        {
            distance = (*it)->getPosition().distance(position);
            if(distance < minDistance)
            {
                minDistance = distance;
                node = (*it);
            }
        }
    }

    return node;
}
