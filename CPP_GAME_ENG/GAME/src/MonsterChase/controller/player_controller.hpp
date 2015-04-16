#ifndef HEADER_PLAYER_CONTROLLER_HPP
#define HEADER_PLAYER_CONTROLLER_HPP

#include "Controller.hpp"

class Unit;
class PlayerController :
    public Controller
{
private:
    static char m_input;
public:
    PlayerController(Unit* unit, const char* name);
    ~PlayerController();

    static void setInput(unsigned int keyID) { m_input = keyID; }
    static void releaseInput(unsigned int keyID) { m_input = 0; }
    void        update(float dt);
};

#endif