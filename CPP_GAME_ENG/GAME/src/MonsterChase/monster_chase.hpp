#ifndef HEADER_MONSTER_CHASE_HPP
#define HEADER_MONSTER_CHASE_HPP

#include <vector>

#include "Unit.hpp"

class Unit;

class MonsterChase
{
private:
    unsigned int        m_num_monsters;
    std::vector<Unit*>   m_monsters;
    Unit*                m_player;

    void    initializeMonsters();
    void    showCurrentLocations();
    
public:
	MonsterChase();
	~MonsterChase();
    void    beginChase();

    
};

#endif