#pragma once
#include "Controller.hpp"
class RandomMoveAI :
    public Controller
{
public:
    RandomMoveAI::RandomMoveAI(Unit* unit);
    ~RandomMoveAI();

    void    update();
};

