#include "SmallBlockAllocator.hpp"


#pragma once
class BlockAllocators
{
private:
    static BlockAllocators * m_block_allocators;
    SmallBlockAllocator* _8_Byte_Allocator;
    static SmallBlockAllocator* _16_Byte_Allocator;

    BlockAllocators();
public:
    BlockAllocators*    get()       { return m_block_allocators; }
    void                create();
    ~BlockAllocators();
};



static SmallBlockAllocator* _8_Byte_Allocator = SmallBlockAllocator::create(8, 1000);
static SmallBlockAllocator* _16_Byte_Allocator = SmallBlockAllocator::create(16, 1000);
