#include "player_controller.hpp"

#include "../Unit.hpp"

#include <iostream>

char PlayerController::m_input = 0;

PlayerController::PlayerController(Unit* unit, const char* name) : Controller(unit,name)
{
}


PlayerController::~PlayerController()
{
}

void PlayerController::update( float dt )
{
    std::cout << "Enter W-A-S-D for up-left-down-right : ";
 
    Vec3 player_pos = m_unit->getXYZ();

    // only process input once per 0.2seconds
    static float time_since_last;
    
    time_since_last += dt;
    if (time_since_last > 0.05f)
    {
        switch (m_input)
        {
        case 'W': player_pos.setY(player_pos.getY() + 3);
            break;
        case 'S': player_pos.setY(player_pos.getY() - 3);
            break;

        case 'A': player_pos.setX(player_pos.getX() - 3);
            break;

        case 'D': player_pos.setX(player_pos.getX() + 3);
            break;

        }
        m_unit->setXYZ(player_pos);
        time_since_last = 0.0f;
    }
}