#pragma once
#include <vector>
#include "utils\SharedPtr\SharedPtr.h"
#include "OBBCollisionObject.h"
#include "RigidBody.h"

namespace Engine
{
namespace Physics
{

    struct CollisionInfo
    {
        Physics::OBBCollisionObject* boxA;
        Physics::OBBCollisionObject* boxB;
        Vec3 collision_normal;
    };

class PhysicsHandler
{
private:
    std::vector<Physics::RigidBody> m_bodies;

    static PhysicsHandler* m_physics_handler;
    PhysicsHandler();
    ~PhysicsHandler();
public:

    void static create() { m_physics_handler = new PhysicsHandler(); }
    void static destroy();

    static PhysicsHandler* get()   { return m_physics_handler;  }

    void    addRigidBody(Physics::RigidBody);
    void    checkAllCollisions();
};

}

}