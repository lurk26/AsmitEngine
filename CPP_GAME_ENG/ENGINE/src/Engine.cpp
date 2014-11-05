#include "Engine.hpp"

#include "memory\BlockAllocators.hpp"

#include <iostream>


Engine::Engine()
{
    std::cout << "This is part of engine. Bye!\n\n";
    BlockAllocators::create();
}


Engine::~Engine()
{
    
}

void Engine::shutdown()
{
    BlockAllocators::destroy();
}