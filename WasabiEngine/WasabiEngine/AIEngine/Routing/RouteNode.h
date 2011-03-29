/* 
 * File:   RouteNode.h
 * Author: Fran_2
 *
 * Created on 10 de enero de 2011, 12:50
 */

#ifndef ROUTENODE_H
#define	ROUTENODE_H

#include <map>
#include <WasabiEngine/Utils/Vectors.h>
#include <WasabiEngine/GameEngine/Sensor.h>
#include <WasabiEngine/GameEngine/SensorFactory.h>

namespace WasabiEngine {

    /**
    * A RoutePlanner node.
    */
    class RouteNode {
    private:
        static const float SENSOR_RADIUS;

        int nodeId;
        WasVec2d position;
        Sensor* sensor;
        std::map<int, int> routeMap;

        RouteNode();
        RouteNode(const RouteNode& orig);
        void prepare(const int& nodeId, const WasVec2d& position);
        void clear();
    public:
        virtual ~RouteNode();
        int getNodeId();
        WasVec2d& getPosition();
        void addRoute(const int& destinationNode, const int& nextNode);
        int getNextNode(const int& destinationNode);
        void addHandler(int monitoredObjectId, SensorHandler* handler);
        void removeHandler(int monitoredObjectId);

        friend class RoutePlanner;
        friend class ResourceFactory<RouteNode>;
    };

    inline int RouteNode::getNodeId(){
        return nodeId;
    }

    inline WasVec2d& RouteNode::getPosition(){
        return position;
    }
}

#endif	/* ROUTENODE_H */

