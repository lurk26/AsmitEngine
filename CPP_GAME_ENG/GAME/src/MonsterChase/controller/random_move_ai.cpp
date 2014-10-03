#include "random_move_ai.hpp"

#include "..\Unit.hpp"

#include <cstdlib>

RandomMoveAI::RandomMoveAI(Unit* unit) :Controller(unit)
{
}


RandomMoveAI::~RandomMoveAI()
{
}

void RandomMoveAI::update()
{
    m_unit->setVelocity(Vec3((float)(rand() % 3 - 1), (float)(rand() % 3 - 1), 0.0f));
}