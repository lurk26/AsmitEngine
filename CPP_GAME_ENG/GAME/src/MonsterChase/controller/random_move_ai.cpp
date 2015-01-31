#include "random_move_ai.hpp"

#include "..\Unit.hpp"

#include <cstdlib>

RandomMoveAI::RandomMoveAI(Unit* unit, const char* name) :Controller(unit,name)
{
}


RandomMoveAI::~RandomMoveAI()
{
}

void RandomMoveAI::update( float dt )
{
    m_unit->setVelocity(20.0f*Vec3((float)(rand() % 3 - 1), (float)(rand() % 3 - 1), 0.0f));
}