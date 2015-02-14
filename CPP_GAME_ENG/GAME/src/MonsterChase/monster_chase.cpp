#include "monster_chase.hpp"

#include "Unit.hpp"
#include "controller\Controller.hpp"
#include "controller\random_move_ai.hpp"
#include "controller\player_controller.hpp"

#include "timing\Timing.h"
#include "utils\RingBuffer.hpp"
#include "render\BasicRenderer.h"

#include <algorithm>
#include <ctime>
#include <iostream>


MonsterChase::MonsterChase()
{
    srand((unsigned int)time(0));

    //Begin Monster Chase
    std::cout << "Enter the number of monsters: ";
   // std::cin >> m_num_monsters;
    m_num_monsters = 4;
    
    initializeMonsters();
    showCurrentLocations();
}

void MonsterChase::initializeMonsters()
{
    m_player = new Unit(0.0f, 0.0f);
    m_player->setController(new PlayerController(m_player, "Player"));
    m_player->setTexture("image\\game_guy.bmp");
    std::cout << "Initializing player at (0,0)\n";

    std::cout << "Initializing" << m_num_monsters << "monsters at (1,1):\n";
    for (unsigned int i = 0; i < m_num_monsters; i++)
    {
        Unit* monster = new Unit(1.0f, 1.0f);
        Controller* randomController = new RandomMoveAI(monster, "Monster");
        monster->setController(randomController);
        monster->setTexture("image\\game_enemy.bmp");
        m_monsters.push_back(monster);
    }

}


void MonsterChase::showCurrentLocations()
{
    //bool bQuit = false;

    //Cheesy::Service(bQuit);

    //struct Cheesy::Point2D SSTextUL(220, 40);
    //struct Cheesy::Point2D SSTextLR(420, 80);
    //struct Cheesy::ColorRGBA White(255, 255, 255, 255);

    //struct Cheesy::ColorRGBA ClearColor(50, 50, 255, 0);

    //if (bQuit == false)
    //{
    //    struct Cheesy::Point2D		center(0.0f, 0.0f);
    //    struct Cheesy::Point2D		size(50.0f, 50.0f);
    //    struct Cheesy::Point2D		offsetGG(50.0f, 100.0f);
    //    struct Cheesy::Point2D		offsetBG(0.0f, 0.0f);

    //    struct Cheesy::ColorRGBA	white(255, 255, 255, 255);
    //    Cheesy::UVSet				UVs = { Cheesy::UV(0.0f, 0.0f), Cheesy::UV(1.0f, 0.0f), Cheesy::UV(0.0f, 1.0f), Cheesy::UV(1.0f, 1.0f) };

    //    Cheesy::Texture * pSampleTexture = CreateTextureFromFile("image\\game_guy.bmp");
    //    assert(pSampleTexture);

    //    Cheesy::Sprite * pGoodGuy = Cheesy::Sprite::Create(center, 0.1f, size, white, *pSampleTexture, UVs);
    //    assert(pGoodGuy);

    //    pSampleTexture->Release();

    //    pSampleTexture = CreateTextureFromFile("image\\game_enemy.bmp");
    //    assert(pSampleTexture);
    //    std::vector<Cheesy::Sprite *> monsters(m_num_monsters);
    //    for (int i = 0; i < m_num_monsters; i++)
    //    {
    //        Cheesy::Sprite * pBadGuy = Cheesy::Sprite::Create(center, 0.1f, size, white, *pSampleTexture, UVs);
    //        assert(pBadGuy);
    //        monsters[i]=(pBadGuy);
    //    }

    //    pSampleTexture->Release();

    //    ClearColor.r = ClearColor.g = ClearColor.b = 80;

    //    float Rotation = 0.0f;
    //    
    //        // We must call Cheesy::Service() at the start of each frame
    //        //Cheesy::Service(bQuit);

    //        if (!bQuit)
    //        {
    //            // We must call Cheesy::BeginFrame() when we want to start making draw requests
    //            if (Cheesy::BeginFrame(ClearColor))
    //            {

    //                pGoodGuy->Draw(offsetGG, Rotation);
    //                for (int i = 0; i < m_num_monsters; i++)
    //                {
    //                    struct Cheesy::Point2D pos(m_monsters[i]->getXYZ().getX(), m_monsters[i]->getXYZ().getY());
    //                    monsters[i]->Draw( pos, 0.0f);
    //                }
    //                //pBadGuy->Draw(offsetBG, 0.0f);

    //                // We must call Cheesy::EndFrame() when we're doing making draw requests.
    //                Cheesy::EndFrame();
    //            }
    //        }
    //    

    //    delete pGoodGuy;
    //    for (int i = 0; i < m_num_monsters; i++)
    //    {
    //        delete monsters[i];
    //    }
    //    //delete pBadGuy;
    //}
    ///*std::cout << "Monsters are at: \n";
    //for (unsigned int i = 0; i < m_num_monsters; i++)
    //{
    //    Vec3 pos = m_monsters[i]->getXYZ();
    //    std::cout<< i <<": (" <<pos.getX() << "," << pos.getY()<< ")\n";
    //}

    //std::cout << "Player at: (" << m_player->getXYZ().getX() << "," << m_player->getXYZ().getY() << ")\n";*/
}

void MonsterChase::beginChase()
{
    Engine::Timing::Initialize();
    // Cold start, this dt value will be large, 
    // we will update it again in the loop.
    float dt = Engine::Timing::GetLastFrameTime_s();
    
    
    //RingBuffer<Vec3> past_states(8);


    while (1)
    {
        // get dt
        dt = Engine::Timing::GetLastFrameTime_s();

        std::cout << "Enter Q to quit, i to add a monster, o to delete a random monster or any key to continue" << std::endl;
     
     /*   switch (monster_chase_input)
        {
        case 'q': break;
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
        }*/

        for (unsigned int i = 0; i < m_num_monsters; i++)
        {
            m_monsters[i]->update(dt);
        }

        m_player->update(dt);

        //past_states.add(m_player->getXYZ());

        //showCurrentLocations();

        BasicRenderer::get()->update(dt);

    }

    
}
MonsterChase::~MonsterChase()
{
    for (unsigned int i = 0; i < m_monsters.size(); i++)
        delete m_monsters[i];

    delete m_player;
}
