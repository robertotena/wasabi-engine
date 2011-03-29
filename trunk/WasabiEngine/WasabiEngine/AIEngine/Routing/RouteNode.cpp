/* 
 * File:   RouteNode.cpp
 * Author: Fran_2
 * 
 * Created on 10 de enero de 2011, 12:50
 */

#include "RouteNode.h"

using namespace WasabiEngine;

const float RouteNode::SENSOR_RADIUS = 3.0f;

RouteNode::RouteNode() {
}

RouteNode::RouteNode(const RouteNode& orig) {
}

RouteNode::~RouteNode() {
    clear();
}

void RouteNode::prepare(const int& nodeId, const WasVec2d& position){
    this->nodeId = nodeId;
    this->position = position;
    sensor = SensorFactory::getInstance()->create(position, SENSOR_RADIUS);
}

void RouteNode::clear(){
    if(sensor != NULL)
        SensorFactory::getInstance()->destroy(sensor);
    sensor = NULL;
    routeMap.clear();
}

void RouteNode::addRoute(const int& destinationNode, const int& nextNode){
    routeMap[destinationNode] = nextNode;
}

int RouteNode::getNextNode(const int& destinationNode){
    //Ojo, si no existe devuelve un valor indeterminado
    return routeMap[destinationNode];
}

void RouteNode::addHandler(int monitoredObjectId, SensorHandler* handler){
    sensor->addHandler(monitoredObjectId, handler);
}

void RouteNode::removeHandler(int monitoredObjectId){
    sensor->removeHandler(monitoredObjectId);
}
