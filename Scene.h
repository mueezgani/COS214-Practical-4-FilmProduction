#ifndef SCENE_H
#define SCENE_H

#include "WorkGroup.h"

class Scene : public WorkGroup
{
public:
    Scene(const std::string& name);
    ~Scene();
};

#endif