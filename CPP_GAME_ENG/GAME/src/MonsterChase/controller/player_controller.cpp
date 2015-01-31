#include "player_controller.hpp"

#include "../Unit.hpp"

#include <iostream>

PlayerController::PlayerController(Unit* unit, const char* name) : Controller(unit,name)
{
}


PlayerController::~PlayerController()
{
}

void PlayerController::update( float dt )
{
    std::cout << "Enter W-A-S-D for up-left-down-right : ";
    char input;
    std::cin >> input;

    Vec3 player_pos = m_unit->getXYZ();
    switch (input)
    {
    case 'W': player_pos.setY(player_pos.getY() + 1);
        break;
    case 'S': player_pos.setY(player_pos.getY() - 1);
        break;

    case 'A': player_pos.setX(player_pos.getX() - 1);
        break;

    case 'D': player_pos.setX(player_pos.getX() + 1);;
        break;
   
    }
    m_unit->setXYZ(player_pos);
}