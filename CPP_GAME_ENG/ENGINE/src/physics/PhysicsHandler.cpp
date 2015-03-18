#include "PhysicsHandler.h"
#include "utils\Console\ConsolePrint.h"

namespace Engine
{
namespace Physics
{

    PhysicsHandler* PhysicsHandler::m_physics_handler = nullptr;

PhysicsHandler::PhysicsHandler()
{
    m_colliders.clear();
}


PhysicsHandler::~PhysicsHandler()
{
    m_physics_handler = nullptr;
}

void PhysicsHandler::destroy()
{
    delete m_physics_handler;
}

void PhysicsHandler::addCollider(SharedPtr<Moveable> obj_ptr, Vec3 aabb_center, Vec3 aabb_extents)
{
    m_colliders.push_back( OBBCollisionObject(obj_ptr, aabb_center, aabb_extents));
}

void   PhysicsHandler::checkAllCollisions()
{
    for (int i = 0; i < (int)m_colliders.size() - 1 ; i++)
    {


        for (int j = i + 1; j < (int)m_colliders.size(); j++)
        {
            bool collision = OBBCollisionObject::checkOBBIntersection(
                                            m_colliders[i], Vec3(),
                                            m_colliders[j], Vec3());

            if (collision) DEBUG_PRINT("Collisoin detected!\n");
        }
    }
}

}
}