#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Windows.h"

#include "../../ENGINE/src/Engine.hpp"

#include "MonsterChase\monster_chase.hpp"

#include <Cheesy.h>

#include <iostream>





int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    //_CrtSetBreakAlloc(224);
    if (Engine::init())
    {
        Cheesy::Create("Cheesy Test App", 640, 480, false, false);

        MonsterChase * game = new MonsterChase();
        game->beginChase();
        delete game;

        Cheesy::Shutdown();
        Engine::shutdown();
    }
    



#ifdef _DEBUG
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
#endif
    return 0;
}
