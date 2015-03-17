#include "random_move_ai.hpp"
#include "../monster_chase.hpp"

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
    Unit* target = MonsterChase::get()->getClosestUnitFrom(m_unit->getXYZ(), m_unit);
    m_unit->setVelocity(4.0f*(target->getXYZ() - m_unit->getXYZ()));
}