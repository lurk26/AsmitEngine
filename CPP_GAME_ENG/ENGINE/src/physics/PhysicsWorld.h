#pragma once
#include <vector>
#include "utils\SharedPtr\SharedPtr.h"
#include "CollisionFixture.h"
#include "PhysicsBody.h"

namespace Engine
{
namespace Physics
{

    struct CollisionInfo
    {
        Physics::CollisionFixture* collision_objA;
        Physics::CollisionFixture* collision_objB;
        Vec3 collision_normal;
    };

class PhysicsWorld
{
private:
    std::vector<PhysicsBody> m_bodies;
    std::vector<CollisionFixture> m_colliders;

    static PhysicsWorld* m_physics_handler;
    PhysicsWorld();
    ~PhysicsWorld();
public:

    void static create() { m_physics_handler = new PhysicsWorld(); }
    void static destroy();

    static PhysicsWorld* get()   { return m_physics_handler;  }

    void    addPhysicsBody(PhysicsBody& body);
    void    checkAllCollisions();
};

}

}