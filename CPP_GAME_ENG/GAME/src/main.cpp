#include <crtdbg.h>

#include "../../ENGINE/src/Engine.hpp"
#include "MonsterChase\monster_chase.hpp"

#include <iostream>


static char input;

int main(int argv, char** argc)
{
    Engine::Engine();
    MonsterChase * game = new MonsterChase();
    game->beginChase();
    delete game;
    
#ifdef _DEBUG
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
#endif
    return 0;
}
