#include "MonsterChase.hpp"

#include "Unit.hpp"

#include <iostream>

MonsterChase::MonsterChase()
{
    //Begin Monster Chase
    std::cout << "Enter the number of monsters: ";
    std::cin >> m_num_monsters;
    initializeMonsters();

    m_player = Unit(0, 0);
    std::cout << "Initializing player at (0,0)\n";

    beginChase();
}

void MonsterChase::initializeMonsters()
{
    std::cout << "Initializing" << m_num_monsters << "monsters at (1,1):\n";
    for (unsigned int i = 0; i < m_num_monsters; i++)
    {
        Unit monster(1, 1);
        m_monsters.push_back(monster);
    }
}

void MonsterChase::showCurrentLocations()
{
    std::cout << "Monsters are at: \n";
    for (unsigned int i = 0; i < m_num_monsters; i++)
    {
        Vec3 pos = m_monsters[i].getXYZ();
        std::cout<< i <<": (" <<pos.getX() << "," << pos.getY()<< ")\n";
    }
    std::cout << "Player at: (" << m_player.getXYZ().getX() << "," << m_player.getXYZ().getY() << ")\n";
}
void MonsterChase::beginChase()
{
    bool play = true;
    while (play)
    {
        showCurrentLocations();
        for (unsigned int i = 0; i < m_num_monsters; i++)
        {
            m_monsters[i].moveUnitRandomly();
        }
        std::cout << "Enter W-A-S-D for up-left-down-right or Q to quit: ";
        char input;
        std::cin >> input;

        Vec3 player_pos = m_player.getXYZ();
        switch (input)
        {
        case 'W': player_pos.setY(player_pos.getY()+1);
            break;
        case 'S': player_pos.setY(player_pos.getY() -1);
            break;

        case 'A': player_pos.setX(player_pos.getX() + 1);
            break;

        case 'D': player_pos.setX(player_pos.getY() - 1);;
            break;
        case 'Q': play = false;
            break;
        }
        m_player.setXYZ(player_pos);
    }

    
}
MonsterChase::~MonsterChase()
{
}
