/* 
 * File:   GoalComposite.h
 * Author: Roberto
 *
 * Created on 23 de enero de 2011, 22:00
 */

#ifndef GOALCOMPOSITE_H
#define	GOALCOMPOSITE_H

#include <list>
#include <WasabiEngine/AIEngine/Goals/Goal.h>

namespace WasabiEngine
{

/**
* The base class of a composition goals.
*/
template <class Entity>
class GoalComposite : public Goal<Entity>{
protected:
    std::list<Goal<Entity>*> subgoals;
public:
    GoalComposite(Entity* entityOwner) : Goal<Entity>(entityOwner){}
    virtual ~GoalComposite(){ clearSubgoals();}
    void addSubgoal(Goal<Entity>* goal);
    GoalStatus processSubgoals();
    void clearSubgoals();
};

template <class Entity>
inline void GoalComposite<Entity>::addSubgoal(Goal<Entity>* goal)
{
    subgoals.push_back(goal);
}

template <class Entity>
inline GoalStatus GoalComposite<Entity>::processSubgoals()
{
    //remove all completed and failed goals from the front of the subgoal list
    while (!subgoals.empty() &&
        (subgoals.front()->isComplete() || subgoals.front()->hasFailed()))
    {
        subgoals.front()->terminate();
        delete subgoals.front();
        subgoals.pop_front();
    }
    if (!subgoals.empty())
    {
        GoalStatus subgoalStatus = subgoals.front()->process();
        if (subgoalStatus == COMPLETED_STATUS && subgoals.size() > 1)
            return ACTIVE_STATUS;
        return subgoalStatus;
    }
    else
        return COMPLETED_STATUS;
}

template <class Entity>
inline void GoalComposite<Entity>::clearSubgoals()
{
    typename std::list<Goal<Entity>*>::iterator it;
    for(it = subgoals.begin(); it != subgoals.end(); it++)
    {
        (*it)->terminate();
        delete (*it);
    }
    subgoals.clear();
}

}

#endif	/* GOALCOMPOSITE_H */

