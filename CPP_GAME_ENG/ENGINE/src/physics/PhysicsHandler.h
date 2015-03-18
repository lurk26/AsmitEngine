#pragma once
#include <vector>
#include "utils\SharedPtr\SharedPtr.h"
#include "OBBCollisionObject.h"

namespace Engine
{
namespace Physics
{

class PhysicsHandler
{
private:
    std::vector<Physics::OBBCollisionObject> m_colliders;

    static PhysicsHandler* m_physics_handler;
    PhysicsHandler();
    ~PhysicsHandler();
public:

    void static create() { m_physics_handler = new PhysicsHandler(); }
    void static destroy();

    static PhysicsHandler* get()   { return m_physics_handler;  }

    void    addCollider(SharedPtr<Moveable> obj_ptr, Vec3 aabb_center, Vec3 aabb_extents);
    void    checkAllCollisions();
};

}

}