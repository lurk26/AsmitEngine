#include "Engine.hpp"

#include "memory\BlockAllocators.hpp"

#include <iostream>


Engine::Engine()
{
    std::cout << "This is part of engine. Bye!\n\n";
    
}


Engine::~Engine()
{
    
}

void Engine::shutdown()
{
    delete _8_Byte_Allocator;
    delete _16_Byte_Allocator;
}