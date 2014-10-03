#include "Unit.hpp"

#include "objects\Moveable.hpp"

#include "controller\controller.hpp"

#include <cstdlib>


Unit::Unit()
{
    m_body = new Moveable();
    m_body->setPosition(Vec3(0, 0, 0));
    m_body->setVelocity(Vec3(0, 0, 0));
}

Unit::Unit(float x, float y)
{
    m_body = new Moveable();
    m_body->setPosition(Vec3(x, y, 0.0f));
    m_body->setVelocity(Vec3(0.0f, 0.0f, 0.0f));
}


Unit::~Unit()
{
}



void Unit::update()
{
    m_controller->update();
    m_body->update();
}