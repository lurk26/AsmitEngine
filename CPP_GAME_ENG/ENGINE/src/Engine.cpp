#include "Engine.hpp"

#include "memory\BlockAllocators.hpp"
#include "memory\HeapAllocator.hpp"

#include <iostream>


Engine::Engine()
{
    std::cout << "This is part of engine. Bye!\n\n";
    HeapAllocator::create(1024 * 1024);
    BlockAllocators::create();
}


Engine::~Engine()
{
    
}

void Engine::shutdown()
{
    BlockAllocators::destroy();

    HeapAllocator::destroy();
}