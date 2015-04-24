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
        float                m_mass;
    public:
        RigidBody(float mass);


        void    addCollider(SharedPtr<Moveable> obj_ptr, Vec3 aabb_center, Vec3 aabb_extents);
        const Physics::OBBCollisionObject*  getCollider() { return m_collider; }

        ~RigidBody();
    };

}
}