#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#include "../../ENGINE/src/Engine.hpp"
#include "MonsterChase\monster_chase.hpp"

#include <iostream>



int main(int argv, char** argc)
{
    //_CrtSetBreakAlloc(153);
    Engine::Engine();
    MonsterChase * game = new MonsterChase();
    game->beginChase();
    delete game;
    Engine::shutdown();

#ifdef _DEBUG
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
#endif
    return 0;
}
