#pragma once

#include "CollisionFixture.h"
#include "objects\GameObject.hpp"
#include "physics\Shapes.h"
#include "utils\SharedPtr\SharedPtr.h"

namespace Engine
{
namespace Physics
{



class OBBFixture: public CollisionFixture
{

private:
    AABB    m_aabb;

    

public:
    OBBFixture();
    ~OBBFixture();


public:
    OBBCollisionObject(Engine::SharedPtr<GameObject> object_ptr, Vec3 center, Vec3 extents);
    ~OBBCollisionObject();

    Engine::SharedPtr<Engine::GameObject> getObject() { return m_object_ptr; }

    const Transform& getTrans() const { return m_object_ptr->getTrans(); }
};

}
}