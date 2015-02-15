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
        BasicRenderer::init();

		// Unit test for NamedBitSet --------------
		// This incorporates a test or HashedString too
		Engine::NamedBitSet<uint32_t> test_bitset;
		test_bitset.GetBitIndex("Hello");
		uint32_t hello_index;
		if (test_bitset.FindBitIndex("Hello", hello_index) && hello_index == test_bitset.GetBitIndex("Hello"))
			std::cout << "Success";
		else
			assert(NULL); //blow up
		// ----------------------------------------

		// Unit test for StringPool ---------------
		Engine::StringPool * pTestPool = Engine::StringPool::Create(1024);
		assert(pTestPool);

		const char * pP1 = pTestPool->find("This");
		const char * pP2 = pTestPool->find("is");
		const char * pP3 = pTestPool->find("a");
		const char * pP4 = pTestPool->find("test");
		const char * pP5 = pTestPool->find("a");

		// pP3 and pP5 should now be the same sharing one string in the string pool
		assert(pP5 == pP3);

		delete pTestPool;
		// -------------------------------------------


        int * myptr = new int[10];
        // using auto pointer. this should prevent memory leak on myptr;
        Engine::AutoPtr <int> test_autoptr(myptr);


		MonsterChase * game = new MonsterChase();
		game->beginChase();
		delete game;


        BasicRenderer::shutdown();
        Cheesy::Shutdown();
        Engine::shutdown();
    }
    



#ifdef _DEBUG
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
#endif
    return 0;
}
