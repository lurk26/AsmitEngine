#include "Moveable.hpp"


Moveable::Moveable()
{
}


Moveable::~Moveable()
{
}

void Moveable::update(float dt)
{
    m_position = m_position + 0.5f*(m_velocity + m_old_velocity)*dt;
}