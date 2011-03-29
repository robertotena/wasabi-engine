/* 
 * File:   StateMachine.h
 * Author: Fran_2
 *
 * Created on 14 de diciembre de 2010, 18:31
 */

#ifndef STATEMACHINE_H
#define	STATEMACHINE_H

#include <WasabiEngine/AIEngine/FSM/State.h>

namespace WasabiEngine {

    /**
    * Represents a Finite States Machine.
    */
    template <class Type>
    class StateMachine {
    private:
        /* DEPRECATED
        typedef std::map<EventPort, State<Type>* > EdgeMap;
        typedef std::map<State<Type>*, EdgeMap> TransitionMap;
        HandlerRegistration* registration;
        TransitionMap transitionMap;
        State<Type>* getTarget(const Event* event);
        */
        
        Type* entity;
        State<Type>* previousState;
        State<Type>* currentState;
        State<Type>* globalState;
    public:
        StateMachine(Type* entity);
        StateMachine(const StateMachine& orig);
        virtual ~StateMachine();
        void setEntity(Type* entity);
        void update();
        State<Type>* getCurrentState();
        void setState(State<Type>* state);
        void setGlobalState(State<Type>* state);
        bool isInState(State<Type>* state);
        void backToPreviousState();
        /* DEPRECATED
        void handle(const Event* event);
        void addTransition(State<Type>* fromState, State<Type>* toState, EventFactoryBase* transition);
        void removeTransition(State<Type>* fromState, State<Type>* toState, EventFactoryBase* transition);
         */
    };

    template <class Type>
    StateMachine<Type>::StateMachine(Type* entity) {
        this->entity = entity;
        previousState = NULL;
        currentState = NULL;
        globalState = NULL;
        //registration = NULL;
    }

    template <class Type>
    StateMachine<Type>::StateMachine(const StateMachine& orig) {
        //FIXME
    }

    template <class Type>
    StateMachine<Type>::~StateMachine() {
        /* DEPRECATED
        if(registration)
            registration->removeHandler();
        */
    }

    template <class Type>
    void StateMachine<Type>::setEntity(Type* entity) {
        this->entity = entity;
    }

    template <class Type>
    void StateMachine<Type>::update() {
        if (globalState != NULL)
            globalState->update(entity);
        if (currentState != NULL)
            currentState->update(entity);
    }

    template <class Type>
    void StateMachine<Type>::setState(State<Type>* state) {
        if(currentState != NULL)
            currentState->onExit(entity);
        State<Type>* tmp = state;
        previousState = currentState;
        currentState = tmp;
        currentState->onEntry(entity);
    }

    template <class Type>
    inline void StateMachine<Type>::setGlobalState(State<Type>* state) {
        globalState = state;
    }

    template <class Type>
    bool StateMachine<Type>::isInState(State<Type>* state) {
        if (currentState == state)
            return true;
        return false;
    }

    template <class Type>
    inline void StateMachine<Type>::backToPreviousState() {
        if (previousState != NULL)
            setState(previousState);
    }

    /* DEPRECATED
     *

    template<class Type>
    void StateMachine<Type>::handle(const Event* event) {
        State<Type>* stateTarget = getTarget(event);
        if (stateTarget != NULL)
            setState(stateTarget);
    }

    template <class Type>
    inline void StateMachine<Type>::addTransition(State<Type>* fromState, State<Type>* toState, EventFactoryBase* transition) {
        registration = EventEngine::getInstance()->addHandler(this, transition);
        transitionMap[fromState][transition->getPort()] = toState;
    }

    template <class Type>
    inline void StateMachine<Type>::removeTransition(State<Type>* fromState, State<Type>* toState, EventFactoryBase* transition) {
        transitionMap[fromState][transition->getPort()] = NULL;
    }

    template <class Type>
    inline State<Type>* StateMachine<Type>::getTarget(const Event* event) {
        EdgeMap& edges = transitionMap[currentState];
        return edges[*event->getPort()];
    }
    */
}

#endif	/* STATEMACHINE_H */

