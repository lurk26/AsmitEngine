#include "Engine.hpp"
#include <iostream>

#include "memory\SmallBlockAllocator.hpp"

Engine::Engine()
{
    std::cout << "This is part of engine. Bye!\n\n";

    SmallBlockAllocator* pNewSBA = SmallBlockAllocator::create(8, 32);

    delete pNewSBA;
}


Engine::~Engine()
{
}
