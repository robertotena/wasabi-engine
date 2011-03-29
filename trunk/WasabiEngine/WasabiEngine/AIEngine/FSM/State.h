/* 
 * File:   State.h
 * Author: Fran_2
 *
 * Created on 14 de diciembre de 2010, 18:39
 */

#ifndef STATE_H
#define	STATE_H

namespace WasabiEngine {

    /**
    * A FSM's state
    *
    */
    template <class Type>
    class State {
    public:
        virtual ~State();
        virtual void onEntry(Type* entity);
        virtual void update(Type* entity) = 0;
        virtual void onExit(Type* entity);
    };

    template <class Type>
    State<Type>::~State(){
    }
    
    template <class Type>
    void State<Type>::onEntry(Type* entity) {
    }

    template <class Type>
    void State<Type>::onExit(Type* entity) {
    }
}

#endif	/* STATE_H */

