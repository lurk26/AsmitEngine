#include "monster_chase.hpp"

#include "Unit.hpp"
#include "controller\Controller.hpp"
#include "controller\random_move_ai.hpp"
#include "controller\player_controller.hpp"

#include <iostream>

MonsterChase::MonsterChase()
{
    //Begin Monster Chase
    std::cout << "Enter the number of monsters: ";
    std::cin >> m_num_monsters;
    initializeMonsters();

    m_player = new Unit(0.0f, 0.0f);
    m_player->setController(new PlayerController(m_player));
    std::cout << "Initializing player at (0,0)\n";

    beginChase();
}

void MonsterChase::initializeMonsters()
{
    std::cout << "Initializing" << m_num_monsters << "monsters at (1,1):\n";
    for (unsigned int i = 0; i < m_num_monsters; i++)
    {
        Unit* monster = new Unit(1, 1);
        Controller* randomController = new RandomMoveAI(monster);
        monster->setController(randomController);
        m_monsters.push_back(monster);
    }
}

void MonsterChase::showCurrentLocations()
{
    std::cout << "Monsters are at: \n";
    for (unsigned int i = 0; i < m_num_monsters; i++)
    {
        Vec3 pos = m_monsters[i]->getXYZ();
        std::cout<< i <<": (" <<pos.getX() << "," << pos.getY()<< ")\n";
    }

    std::cout << "Player at: (" << m_player->getXYZ().getX() << "," << m_player->getXYZ().getY() << ")\n";
}
void MonsterChase::beginChase()
{
    bool play = true;
    while (play)
    {
        showCurrentLocations();
        for (unsigned int i = 0; i < m_num_monsters; i++)
        {
            m_monsters[i]->update();
        }
        m_player->update();
    }

    
}
MonsterChase::~MonsterChase()
{
}
