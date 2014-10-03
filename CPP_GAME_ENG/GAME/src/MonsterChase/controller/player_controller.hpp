#pragma once
#include "Controller.hpp"

class Unit;
class PlayerController :
    public Controller
{
public:
    PlayerController(Unit* unit);
    ~PlayerController();

    void        update();
};

