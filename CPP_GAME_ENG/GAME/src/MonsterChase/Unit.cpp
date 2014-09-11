#include "Unit.hpp"

#include <cstdlib>

Unit::Unit()
{
}


Unit::~Unit()
{
}

Unit::Unit(int x, int y)
{
    m_x = x;
    m_y = y;
}

void Unit::moveUnitRandomly()
{
    // move +1 or -1 or 0 randomly
    m_x += rand() % 3 - 1;
    m_y += rand() % 3 - 1;
}