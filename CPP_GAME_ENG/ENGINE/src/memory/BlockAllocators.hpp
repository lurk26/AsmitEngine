#include "SmallBlockAllocator.hpp"
#include <map>

#pragma once
class BlockAllocators
{
private:
    static BlockAllocators * m_block_allocators;

    SmallBlockAllocator* SMBAllocator[10];
    
    BlockAllocators();
public:
    static BlockAllocators* get()       { return m_block_allocators; }
    SmallBlockAllocator*    getSMBAllocator(size_t size) 
    {
        if (SMBAllocator[static_cast<int>(log2(size))])
            return SMBAllocator[static_cast<int>(log2(size))];
        else
            return NULL;
    }
    static void             create();
    static void             destroy();
    ~BlockAllocators();

    // standard new & delete
    void * operator new(size_t i_size);

    void operator delete(void * i_ptr);
};


