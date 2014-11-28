#include "SmallBlockAllocator.hpp"
#include <map>

#pragma once
class BlockAllocators
{
private:
    static BlockAllocators * m_block_allocators;

    std::map<size_t, SmallBlockAllocator*> SMBAllocator;
    
    BlockAllocators();
public:
    static BlockAllocators* get()       { return m_block_allocators; }
    SmallBlockAllocator*    getSMBAllocator(size_t size) 
    {
        if (SMBAllocator.find(size) != SMBAllocator.end())
            return SMBAllocator[size];
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


