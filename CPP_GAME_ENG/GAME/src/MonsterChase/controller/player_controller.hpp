#ifndef HEADER_PLAYER_CONTROLLER_HPP
#define HEADER_PLAYER_CONTROLLER_HPP

#include "Controller.hpp"

class Unit;
class PlayerController :
    public Controller
{
public:
    PlayerController(Unit* unit, const char* name);
    ~PlayerController();

    void        update(float dt);
};

#endif