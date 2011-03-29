/* 
 * File:   Goal.h
 * Author: Roberto
 *
 * Created on 23 de enero de 2011, 21:37
 */

#ifndef GOAL_H
#define	GOAL_H

namespace WasabiEngine
{

enum GoalStatus {
    ACTIVE_STATUS, INACTIVE_STATUS, COMPLETED_STATUS, FAILED_STATUS
};

/**
* The base class of a single goal.
*/
template <class Entity>
class Goal {
protected:
    Entity* owner;
    GoalStatus status;
public:
    Goal(Entity* entityOwner) : owner(entityOwner){ status = INACTIVE_STATUS;}
    virtual ~Goal(){};
    virtual void activate() = 0;
    virtual GoalStatus  process() = 0;
    virtual void terminate() = 0;
    bool isActive()const{return status == ACTIVE_STATUS;}
    bool isInactive()const{return status == INACTIVE_STATUS;}
    bool isComplete()const{return status == COMPLETED_STATUS;}
    bool hasFailed()const{return status == FAILED_STATUS;}
    virtual void addSubgoal(Goal<Entity>* goal){}
    void activateIfInactive();
    void reactivateIfFailed();
};

template <class Entity>
inline void Goal<Entity>::activateIfInactive()
{
    if(status == INACTIVE_STATUS)
        activate();
}

template <class Entity>
void Goal<Entity>::reactivateIfFailed()
{
    if(status == FAILED_STATUS)
        status == INACTIVE_STATUS;
}

}

#endif	/* GOAL_H */

