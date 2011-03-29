/* 
 * File:   PropertyMap.h
 * Author: Roberto
 *
 * Created on 3 de enero de 2011, 17:48
 */

#ifndef PROPERTYMAP_H
#define	PROPERTYMAP_H

#include <tr1/unordered_map>
#include <list>

namespace WasabiEngine {

    /**
     * HashMap of properties.
     */
    template <class Type, typename KeyType = unsigned int> class PropertyMap {
    private:
        std::tr1::unordered_map<KeyType, Type> properties;
    public:

        Type* get(const KeyType& id) {
            Type* object = NULL;
            if (properties.find(id) != properties.end())
                object = &properties[id];
            return object;
        }

        void set(const KeyType& id, const Type& property) {
            properties[id] = property;
        }

        void remove(const KeyType& id) {
            if (properties.find(id) != properties.end())
                properties.erase(id);
        }

        void clear() {
            properties.clear();
        }

        int size() const {
            return properties.size();
        }

        std::list<Type> getItems() const {
            std::list<Type> items;
            for (typename std::tr1::unordered_map<KeyType, Type>::const_iterator i = properties.begin(); i != properties.end(); i++) {
                items.push_back(i->second);
            }
            return items;
        }
    };

}

#endif	/* PROPERTYMAP_H */

