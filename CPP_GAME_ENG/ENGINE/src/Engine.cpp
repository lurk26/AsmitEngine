#include "Engine.hpp"

#include "memory\BlockAllocators.hpp"
#include "memory\HeapAllocator.hpp"

#include <iostream>


bool Engine::init()
{
    std::cout << "This is part of engine. Bye!\n\n";
    if (!HeapAllocator::create(1024 * 1024)) return false;
    if( !BlockAllocators::create() ) return false;

    return true;
}


bool Engine::shutdown()
{
    BlockAllocators::destroy();

    HeapAllocator::destroy();
    
    return true;
}