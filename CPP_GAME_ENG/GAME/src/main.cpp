#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#include "../../ENGINE/src/Engine.hpp"

#include "../../ENGINE/src/utils\FloatHelpers.h"

#include "MonsterChase\monster_chase.hpp"

#include <iostream>



int main(int argv, char** argc)
{
    //_CrtSetBreakAlloc(224);
    Engine::Engine();
   /* MonsterChase * game = new MonsterChase();
    game->beginChase();
    delete game;
   */ Engine::shutdown();

    // float comparisons unit test
    float a = 0.0000000000000000001f;
    float b = 10000000000000000000000.0f;
    float div = b / a;
    std::cout << " Is 10000000000000000000000 / 0.0000000000000000001f  infinity: " << isInfinity(div)<< std::endl;

    float c = -1.0f;
    std::cout << "Is sqrt(-1) NaN? : " << isNan(sqrt(c)) << std::endl;

    float d = 1.0f; 
    d = d * 5;
    float e = 2.2f + 2.8f;

    std::cout << "Is 1.0f*5 equal to 2.2 + 2.8 ? :" << isEqual(d, e) << std::endl;



#ifdef _DEBUG
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
#endif
    return 0;
}
