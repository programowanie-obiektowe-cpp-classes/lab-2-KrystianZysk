#pragma once

#include "Resource.hpp"
#include <iostream>
#include <memory>

class ResourceManager {
private:
    std::unique_ptr<Resource> resource;

public:
    ResourceManager() : resource(std::make_unique<Resource>()) {
        std::cout << "ResourceManager created\n";
    }

    ~ResourceManager() {
        std::cout << "ResourceManager destroyed\n";
    }

    ResourceManager(const ResourceManager& other) : resource(std::make_unique<Resource>(*other.resource)) {
        std::cout << "ResourceManager copied\n";
    }

    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            resource = std::make_unique<Resource>(*other.resource);
        }
        std::cout << "ResourceManager copy-assigned\n";
        return *this;
    }
    double get() const {
        return resource->get();
    }
};