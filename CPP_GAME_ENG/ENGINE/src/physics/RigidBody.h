#pragma once
#include "physics\CollisionObject.h"

namespace Engine
{
namespace Physics
{
    typedef Matrix4 Transform;

    class RigidBody
    {
    private:
        
        CollisionObject * m_collider;

    public:
        RigidBody();
        ~RigidBody();
    };

}
}