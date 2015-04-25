#include "RigidBody.h"
#include "objects\GameObject.hpp"

using namespace Engine::Physics;

RigidBody::RigidBody(float mass)
{
    m_mass = mass;
}


RigidBody::~RigidBody()
{
    delete m_collider;
}

void RigidBody::addCollider(Engine::SharedPtr<GameObject> obj_ptr, Vec3 aabb_center, Vec3 aabb_extents)
{
    m_collider = new OBBCollisionObject(obj_ptr, aabb_center, aabb_extents);
}