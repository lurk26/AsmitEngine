#pragma once

#include <vector>

#include "Unit.hpp"

class Unit;

class MonsterChase
{
private:
    int                 m_num_monsters;
    std::vector<Unit>   m_monsters;
    Unit                m_player;

    void    initializeMonsters();
    void    showCurrentLocations();
    void    beginChase();

public:
	MonsterChase();
	~MonsterChase();

    
};

