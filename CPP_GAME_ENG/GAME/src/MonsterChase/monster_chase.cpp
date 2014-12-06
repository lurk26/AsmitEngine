#include "monster_chase.hpp"

#include "Unit.hpp"
#include "controller\Controller.hpp"
#include "controller\random_move_ai.hpp"
#include "controller\player_controller.hpp"

#include "utils\RingBuffer.hpp"

#include <algorithm>
#include <ctime>
#include <iostream>


MonsterChase::MonsterChase()
{
    srand((unsigned int)time(0));

    //Begin Monster Chase
    std::cout << "Enter the number of monsters: ";
    std::cin >> m_num_monsters;

    m_player = new Unit(0.0f, 0.0f);
    m_player->setController(new PlayerController(m_player, "Player"));
    std::cout << "Initializing player at (0,0)\n";

    initializeMonsters();
    showCurrentLocations();
}

void MonsterChase::initializeMonsters()
{
    std::cout << "Initializing" << m_num_monsters << "monsters at (1,1):\n";
    for (unsigned int i = 0; i < m_num_monsters; i++)
    {
        Unit* monster = new Unit(1.0f, 1.0f);
        Controller* randomController = new RandomMoveAI(monster, "Monster");
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

    RingBuffer<Vec3> past_states(8);

    while (play)
    {
        std::cout << "Enter Q to quit, i to add a monster, o to delete a random monster or any key to continue" << std::endl;
     
        std::cin >> monster_chase_input;

        switch (monster_chase_input)
        {
        case 'q': play = false; break;
        case 'i':
        {
            Unit* monster = new Unit(1, 1);
            Controller* randomController = new RandomMoveAI(monster, "Monster");
            monster->setController(randomController);
            m_monsters.push_back(monster);
            m_num_monsters++;
            showCurrentLocations();
            break;
        }
        case 'o':
        {
            int idx = rand() % m_monsters.size();
            std::swap(m_monsters[idx], m_monsters.back());
            delete m_monsters.back();
            m_monsters.pop_back();
            m_num_monsters--;
            showCurrentLocations();
            break;
        }
        default: break;
        }

        for (unsigned int i = 0; i < m_num_monsters; i++)
        {
            m_monsters[i]->update();
        }

        m_player->update();

        past_states.add(m_player->getXYZ());

        showCurrentLocations();

    }
        
    std::cout << "printing past 10 states: \n"
    int num_states = past_states.size();
    for (unsigned int i = 0; i < num_states; i++)
    {
        Vec3 v = past_states[i];
        std::cout << v.getX() << " " << v.getY() << " " << v.getZ() << "\n";
    }
    
}
MonsterChase::~MonsterChase()
{
    for (unsigned int i = 0; i < m_monsters.size(); i++)
        delete m_monsters[i];

    delete m_player;
}
