#include "Moveable.hpp"

namespace Engine{

Moveable::Moveable()
{
    m_trans.makeIdentity();
    m_rpy = Vec3(0,0,0);
    m_velocity = Vec3(0, 0, 0);
    m_position = Vec3(0, 0, 0);
    m_old_velocity = Vec3(0, 0, 0);
    m_is_active = 0;
}


Moveable::~Moveable()
{
}

void Moveable::update(float dt)
{
    Vec3 new_position = getPosition() + 0.5f*(m_velocity + m_old_velocity)*dt;
    setPosition(new_position);
}

}