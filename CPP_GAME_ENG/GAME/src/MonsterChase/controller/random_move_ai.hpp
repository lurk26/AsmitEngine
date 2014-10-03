
#ifndef HEADER_RANDOM_MOVE_AI_HPP
#define HEADER_RANDOM_MOVE_AI_HPP

#include "Controller.hpp"
class RandomMoveAI :
    public Controller
{
public:
    RandomMoveAI::RandomMoveAI(Unit* unit);
    ~RandomMoveAI();

    void    update();
};

#endif