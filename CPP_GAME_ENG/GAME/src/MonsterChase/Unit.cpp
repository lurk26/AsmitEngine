#include "Unit.hpp"

#include "objects\Moveable.hpp"
#include "render\BasicRenderer.h"

#include "controller\controller.hpp"

#include <cstdlib>


Unit::Unit()
{
    m_body = Engine::SharedPtr<Moveable>(new Moveable());
    m_body->setPosition(Vec3(0, 0, 0));
    m_body->setVelocity(Vec3(0, 0, 0));
    m_body->setActive(true);
}

Unit::Unit(float x, float y)
{
    m_body = Engine::SharedPtr<Moveable>(new Moveable());
    m_body->setPosition(Vec3(x, y, 0.0f));
    m_body->setVelocity(Vec3(0.0f, 0.0f, 0.0f));
    m_body->setActive(true);
}

Unit::Unit(Vec3 pos)
{
    m_body = Engine::SharedPtr<Moveable>(new Moveable());
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

void Unit::setTexture(std::string s)
{
    BasicRenderer::get()->addRenderable(m_body, s);
}