/* 
 * File:   ResourceFactory.h
 * Author: Roberto
 *
 * Created on 5 de noviembre de 2010, 13:25
 */

#ifndef RESOURCEFACTORY_H
#define	RESOURCEFACTORY_H

#include <set>
#include <string>
#include <sstream>

namespace WasabiEngine {

    /**
     * Template class to handle resources in a efficient way.
     * It store chunks of data to avoid frecuently calls to new/delete operators.
     * Every class that uses that factory must have a clear() method, that will be called
     * after returnResource().
     */
    template<class Resource>
    class ResourceFactory {
    private:

        typedef struct _MemoryChunk {
            Resource* resourcePool;
            _MemoryChunk* nextChunk;

            _MemoryChunk() {
                resourcePool = NULL;
                nextChunk = NULL;
            }
        } MemoryChunk;

        int chunkSize;
        int creationCount;
        MemoryChunk* pool;
        std::set<Resource*> usedResources;
        std::set<Resource*> freeResources;

        ResourceFactory(const ResourceFactory& orig);
        void addMemoryChunk();
    public:
        static const int DEFAULT_CHUNK_SIZE = 256;
        ResourceFactory();
        ResourceFactory(const int& poolSize);
        ~ResourceFactory();
        Resource* createResource();
        bool returnResource(Resource* resource);
        std::set<Resource*>& getResources();
        int getCreationCount(); //FIXME: Podria ser util reconvertirlo a un contador de instancias activas
    };

    template <class Resource>
    ResourceFactory<Resource>::ResourceFactory() {
        pool = NULL;
        creationCount = 0;
        chunkSize = ResourceFactory::DEFAULT_CHUNK_SIZE;
        addMemoryChunk();
    }

    template <class Resource>
    ResourceFactory<Resource>::ResourceFactory(const int& poolSize) {
        pool = NULL;
        creationCount = 0;
        chunkSize = poolSize;
        addMemoryChunk();
    }

    template <class Resource>
    ResourceFactory<Resource>::ResourceFactory(const ResourceFactory& orig) {
        //Not allowed
    }

    template <class Resource>
    ResourceFactory<Resource>::~ResourceFactory() {
        typename std::set<Resource*>::iterator currentResource = usedResources.begin();
        typename std::set<Resource*>::iterator nextResource = usedResources.begin();
        while(currentResource != usedResources.end()) {
            nextResource++;
            returnResource(*currentResource);
            currentResource = nextResource;
        }
        MemoryChunk* currentChunk = pool;
        MemoryChunk* nextChunk = NULL;
        while (currentChunk != NULL) {
            nextChunk = currentChunk->nextChunk;
            delete [] currentChunk->resourcePool;
            delete currentChunk;
            currentChunk = nextChunk;
        }
    }

    template <class Resource>
    void ResourceFactory<Resource>::addMemoryChunk() {
        MemoryChunk* newChunk = new MemoryChunk();
        newChunk->resourcePool = new Resource[chunkSize];
        if (pool == NULL) {
            pool = newChunk;
        } else {
            MemoryChunk* currentChunk = pool;
            while (currentChunk->nextChunk != NULL)
                currentChunk = currentChunk->nextChunk;
            currentChunk->nextChunk = newChunk;
        }
        for (int i = 0; i < chunkSize; i++)
            freeResources.insert(&newChunk->resourcePool[i]);
    }

    template <class Resource>
    Resource* ResourceFactory<Resource>::createResource() {
        Resource* resource;
        if (freeResources.size() == 0)
            addMemoryChunk();
        resource = (*freeResources.begin());
        freeResources.erase(resource);
        usedResources.insert(resource);
        creationCount++;

        return resource;
    }

    template <class Resource>
    bool ResourceFactory<Resource>::returnResource(Resource* resource) {
        usedResources.erase(resource);
        freeResources.insert(resource);
        resource->clear();
        return true;
    }

    template <class Resource>
    std::set<Resource*>& ResourceFactory<Resource>::getResources() {
        return usedResources;
    }

    template <class Resource>
    int ResourceFactory<Resource>::getCreationCount() {
        return creationCount;
    }
}

#endif	/* RESOURCEFACTORY_H */
