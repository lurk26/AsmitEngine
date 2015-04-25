#include "Unit.hpp"

#include "objects\GameObject.hpp"
#include "render\BasicRenderer.h"
#include "physics\OBBCollisionObject.h"
#include "physics\PhysicsHandler.h"
#include "utils\Matrix4.h"

#include "controller\controller.hpp"

#include <cstdlib>


Unit::Unit()
{
    using namespace Engine;
    m_body = Engine::SharedPtr<GameObject>(new GameObject());
    m_body->setPosition(Vec3(0, 0, 0));
    m_body->setVelocity(Vec3(0, 0, 0));
    m_body->setActive(true);
}

Unit::Unit(float x, float y)
{
    using namespace Engine;
    m_body = Engine::SharedPtr<GameObject>(new GameObject());
    m_body->setPosition(Vec3(x, y, 0.0f));
    m_body->setVelocity(Vec3(0.0f, 0.0f, 0.0f));
    m_body->setActive(true);
}

Unit::Unit(Vec3 pos)
{
    using namespace Engine;
    m_body = Engine::SharedPtr<GameObject>(new GameObject());
    m_body->setPosition(pos);
    m_body->setVelocity(Vec3(0.0f, 0.0f, 0.0f));
    m_body->setActive(true);
}

Unit::~Unit()
{
    m_body->setActive(false);
    delete m_controller;
}



void Unit::update(float dt)
{
    m_controller->update(dt);
    m_body->update(dt);
}

void Unit::applyRotationZ(float rad)
{
    Vec3 current_rot = m_body->getRotation();
    Vec3 new_rot = current_rot + Vec3(0, 0, rad);
    m_body->setRotation( new_rot );

//    Engine::Matrix4 rot;
//    rot.setRotationRadians(Vec3(0, 0, rad));

//    Engine::Matrix4 trans = m_body->getTrans();
//    m_body->setTrans(trans*rot);
}

void Unit::setTexture(std::string s)
{
    using namespace Engine;
    BasicRenderer::get()->addRenderable(m_body, s);
}


void Unit::addRigidBody()
{
    Engine::Physics::PhysicsHandler::get()->addRigidBody()
}

void Unit::setCollider(Vec3 center, Vec3 extents)
{
    Engine::Physics::PhysicsHandler::get()->addCollider(m_body, center, extents);
}