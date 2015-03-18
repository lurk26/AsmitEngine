#include "Moveable.hpp"

namespace Engine{

Moveable::Moveable()
{
    m_trans.makeIdentity();
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