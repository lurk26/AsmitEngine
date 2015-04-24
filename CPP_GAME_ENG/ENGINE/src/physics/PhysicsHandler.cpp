#include "PhysicsHandler.h"
#include "utils\Console\ConsolePrint.h"
#include "render\BasicRenderer.h"

namespace Engine
{
namespace Physics
{

    PhysicsHandler* PhysicsHandler::m_physics_handler = nullptr;

PhysicsHandler::PhysicsHandler()
{
    m_bodies.clear();
}


PhysicsHandler::~PhysicsHandler()
{
    m_physics_handler = nullptr;
}

void PhysicsHandler::destroy()
{
    delete m_physics_handler;
}

void PhysicsHandler::addRigidBody(Physics::RigidBody body)
{

    m_bodies.push_back(body);
}

void   PhysicsHandler::checkAllCollisions()
{
    for (int i = 0; i < (int)m_bodies.size() - 1 ; i++)
    {
        
        for (int j = i + 1; j < (int)m_bodies.size(); j++)
        {
            bool collision = OBBCollisionObject::checkOBBIntersection(
                                            *(m_bodies[i].getCollider()), Vec3(),
                                            *(m_bodies[j].getCollider()), Vec3());

            if (collision) 
                BasicRenderer::get()->setClearColor(Cheesy::ColorRGBA(200,50,90,0));
            else
                BasicRenderer::get()->setClearColor(Cheesy::ColorRGBA(100, 200, 50, 0));
        }
    }
}

}
}