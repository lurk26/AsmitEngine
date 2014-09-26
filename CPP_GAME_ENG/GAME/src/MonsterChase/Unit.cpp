#include "Unit.hpp"

#include <cstdlib>

Unit::Unit()
{
}


Unit::~Unit()
{
}



void Unit::moveUnitRandomly()
{
    // move +1 or -1 or 0 randomly
    m_position = m_position + Vec3((float)(rand() % 3 - 1), (float)(rand() % 3 - 1), 0.0f);
}