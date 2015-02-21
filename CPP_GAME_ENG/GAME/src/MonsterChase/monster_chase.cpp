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

MonsterChase* MonsterChase::m_monster_chase = NULL;

MonsterChase::MonsterChase()
{
    srand((unsigned int)time(0));

    //Begin Monster Chase
    std::cout << "Enter the number of monsters: ";
   // std::cin >> m_num_monsters;
    m_num_monsters = 4;
    m_monster_chase = this;
    initializeMonsters();
    showCurrentLocations();
}

void MonsterChase::initializeMonsters()
{
    
    parseLuaLoadActors("Actors.lua");
}

bool GetAsVector3(LuaPlus::LuaObject & i_Object, Vec3 & o_Out)
{
    if (!i_Object.IsTable() || (i_Object.GetCount() < 3))
        return false;

    LuaPlus::LuaObject X = i_Object[1];
    LuaPlus::LuaObject Y = i_Object[2];
    LuaPlus::LuaObject Z = i_Object[3];

    if (!X.IsNumber() || !Y.IsNumber() || !Z.IsNumber())
        return false;

    o_Out.setX(X.GetFloat());
    o_Out.setY(Y.GetFloat());
    o_Out.setZ(Z.GetFloat());

    return true;
}

Unit* MonsterChase::makeUnit(LuaPlus::LuaObject lua_actor)
{
    assert(lua_actor.IsTable());
   
    LuaPlus::LuaObject ControllerName = lua_actor["controller"];
    assert(ControllerName.IsString());

    Vec3 pos(0, 0, 0);
    LuaPlus::LuaObject InitialPosition = lua_actor["position"];
    if (!InitialPosition.IsNil())
    {
        GetAsVector3(InitialPosition, pos);
    }

    LuaPlus::LuaObject SpriteTexture = lua_actor["texture"];
    assert(SpriteTexture.IsString());

    Unit* unit = new Unit(pos);
    Controller* controller;
    if (strcmp(ControllerName.GetString(), "RandomMoveAI") == 0)
    {
        controller = new RandomMoveAI(unit, "Monster");
    }
    else if (strcmp(ControllerName.GetString(), "PlayerController") == 0)
    {
       controller = new PlayerController(unit, "Player");
    }
    else
    {
        controller = new RandomMoveAI(unit, "Monster");
    }
    unit->setController(controller);
    unit->setTexture(SpriteTexture.GetString());

    return unit;
}

void MonsterChase::parseLuaLoadActors(std::string s)
{
    using namespace LuaPlus;
    LuaState * pState = LuaState::Create();
    if (pState)
    {
        if (pState->DoFile(s.c_str()) == 0)
        {
            // Read the Actors
            LuaObject Actors = pState->GetGlobal("Actors");
            for (LuaPlus::LuaTableIterator it(Actors); it; it.Next())
            {
                LuaObject ThisActor = it.GetValue();
                assert(ThisActor.IsTable());
                m_monsters.push_back(makeUnit(ThisActor));
            }

            m_num_monsters = m_monsters.size();
        }
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

        if (m_player)
            m_player->update(dt);

        //past_states.add(m_player->getXYZ());

        //showCurrentLocations();

        BasicRenderer::get()->update(dt);

    }

    
}


Unit* MonsterChase::getClosestUnitFrom(Vec3 point, Unit* ignore)
{
    float min_dist = 999999.999f;
    Unit* closest_unit = nullptr;
    for (unsigned int i = 0; i < m_monsters.size(); i++)
    {
        if (ignore && ignore == m_monsters[i]) continue;
        float dist = (point - m_monsters[i]->getXYZ()).length2();
        if (dist < min_dist)
        {
            min_dist = dist;
            closest_unit = m_monsters[i];
        }

    }
    return closest_unit;
}

MonsterChase::~MonsterChase()
{
    for (unsigned int i = 0; i < m_monsters.size(); i++)
        delete m_monsters[i];

    if(m_player) delete m_player;

    m_monster_chase = NULL;
}



