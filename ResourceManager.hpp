#pragma once

#include "Resource.hpp"
#include <iostream>
#include <memory>

class ResourceManager {
private:
    std::unique_ptr<Resource> resource;

public:
    ResourceManager() : resource(std::make_unique<Resource>()) {}

    ~ResourceManager() {}

    ResourceManager(const ResourceManager& other) : resource(std::make_unique<Resource>(*other.resource)) {}

    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            resource = std::make_unique<Resource>(*other.resource);
        }
        return *this;
    }
    double get() const {
        return resource->get();
    }
};