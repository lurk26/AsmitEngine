#pragma once

#include "CollisionFixture.h"
#include "objects\GameObject.hpp"
#include "physics\Shapes.h"
#include "PhysicsBody.h"
#include "utils\SharedPtr\SharedPtr.h"

namespace Engine
{
namespace Physics
{

class OBBFixture: public CollisionFixture
{

private:
    AABB         m_aabb;
    PhysicsBody* m_parent;
    

public:
    OBBFixture(Vec3 center, Vec3 extents);
    ~OBBFixture();

    const Transform& getTrans() const { return m_object_ptr->getTrans(); }
};

}
}