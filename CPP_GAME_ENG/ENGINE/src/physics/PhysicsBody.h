#pragma once

#include "CollisionFixture.h"
#include "objects\GameObject.hpp"
#include "physics\Shapes.h"
#include "utils\SharedPtr\SharedPtr.h"

namespace Engine
{
namespace Physics
{
     
class PhysicsBody
{
private:
    Engine::SharedPtr<Engine::GameObject>   m_object_ptr;
    CollisionFixture*                       m_fixture;
    float                                   m_density;
    Vec3                                    m_force;
    Vec3                                    m_gravity;

public:
    PhysicsBody(SharedPtr<GameObject>, float density = 0);
    ~PhysicsBody();

    SharedPtr<GameObject> getGameObject() { return m_object_ptr; }
    const Transform&      getTrans() const { return m_object_ptr->getTrans(); }
    const CollisionFixture* getFixture() { return m_fixture; }

    void                  addBoxFixture(const AABB& box);
};

}
}