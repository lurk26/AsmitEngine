#ifndef HEADER_MONSTER_CHASE_HPP
#define HEADER_MONSTER_CHASE_HPP

#include <vector>

#include "Unit.hpp"

#pragma warning( disable : 4996 )
#include "LuaPlus.h"

class Unit;

class MonsterChase
{
private:

    static MonsterChase* m_monster_chase;

    unsigned int        m_num_monsters;
    std::vector<Unit*>   m_monsters;
    Unit*                m_player;

    void    initializeMonsters();
    void    showCurrentLocations();

    void    parseLuaLoadActors(std::string s);
    Unit*   makeUnit(LuaPlus::LuaObject lua_actor);
    
public:
	MonsterChase();
	~MonsterChase();
    void    beginChase();
    static MonsterChase*   get()   { return m_monster_chase; }

    Unit*  getClosestUnitFrom(Vec3 point, Unit* ignore = nullptr);
        
};

#endif