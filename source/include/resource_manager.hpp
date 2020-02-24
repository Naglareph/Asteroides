#pragma once

#include <unordered_map>
#include <fstream>
#include <string>
#include <iostream>

template <typename Derived, class T> 
class ResourceManager
{
public:
    ResourceManager(const std::string& fileName)
    {
        PopulateStorage(fileName);
    }

    ~ResourceManager()
    {
        KillResources();    //de-allocate the resources from the heap.
    }

    T* GetResource(const std::string& resourceName)
    {
        auto res = this->Find(resourceName); //use auto since we don't know what data-type the Find() method will return!
     
        if (res)
            return res->first;
        else
            return NULL;
    }

    bool AddResource(const std::string& resourceName)
    {
        auto res = this->Find(resourceName); //see if resource is already allocated
        if (res) //if resourceName already allocated
        {
            ++res->second;  //increments counter in map
            return true;
        }

        auto filePath = this->fileMap.find(resourceName);
        if (filePath == this->fileMap.end())  //if we don't find resource in our container
            return false;

        T* resource = this->Load(filePath->second);
        if (!resource)      //if resource doesn't load
            return false;

        //if pass all tests we place resource on our container keeping track of our memory allocation.
        this->resourceMap.emplace(resourceName, std::make_pair(resource, 1));
        return true;
    }

    bool ReleaseResource(const std::string& resourceName)
    {
        auto res = this->Find(resourceName);
        if (!res)
            return false;
        --res->second;  //decrement use counter if resource if found
        if (!res->second)   
            Unload(resourceName);   //de-allocate memory
        return true;
    }

    void KillResources()
    {
        while (this->resourceMap.begin() != this->resourceMap.end())
        {
            delete this->resourceMap.begin()->second.first;
            this->resourceMap.erase(this->resourceMap.begin());
        }
    }

    T* Load(const std::string& path)
    {
        return static_cast<Derived*>(this)->Load(path);
    }

private:


    void Unload(const std::string& resourceName)
    {
        auto itr = this->resourceMap.find(resourceName);

        if (itr == this->resourceMap.end())
        {
            std::cerr << "Fail" << std::endl;
            return;
        }
        delete itr->second.first;
        this->resourceMap.erase(itr);
    }
    
    std::pair<T*,  int>* Find(const std::string& resourceName)
    {
        auto itr = this->resourceMap.find(resourceName);

        if (itr != this->resourceMap.end())
            return &itr->second;
        else
            return NULL;
    }

    void PopulateStorage(const std::string& fileName)
    {
        std::ifstream paths(fileName);

        if (paths.is_open())
        {
            std::string pathName;
            std::string path;

            while (!paths.eof())
            {                 
                paths >> pathName >> path;
                fileMap.emplace(pathName, path);
            }
            paths.close();
            return;
        }
        std::cerr << "Fail" << std::endl;
    }

    std::unordered_map< std::string, std::pair<T*, int> > resourceMap; //Keeps track of what resources are currently allocated
    std::unordered_map<std::string, std::string> fileMap; //Stores fileName and filePath variables
};
