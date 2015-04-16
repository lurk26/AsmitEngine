#pragma once
#include "physics\OBBCollisionObject.h"

namespace Engine
{
namespace Physics
{
    typedef Matrix4 Transform;

    class RigidBody
    {
    private:
        
        OBBCollisionObject * m_collider;

    public:
        RigidBody();
        ~RigidBody();
    };

}
}