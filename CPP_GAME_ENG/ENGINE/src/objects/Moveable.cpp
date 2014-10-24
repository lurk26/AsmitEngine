#include "Moveable.hpp"


Moveable::Moveable()
{
}


Moveable::~Moveable()
{
}

void Moveable::update()
{
    m_position = m_position + m_velocity;
}