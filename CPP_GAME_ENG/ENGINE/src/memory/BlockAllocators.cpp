#include "BlockAllocators.hpp"

#include <cassert>

BlockAllocators * BlockAllocators::m_block_allocators = NULL;

BlockAllocators::BlockAllocators()
{
    SMBAllocator[8] = SmallBlockAllocator::create(8, 1000);
    SMBAllocator[16] = SmallBlockAllocator::create(16, 1000);
}


BlockAllocators::~BlockAllocators()
{
    delete SMBAllocator[8];
    delete SMBAllocator[16];
    SMBAllocator.clear();
}

void BlockAllocators::create()
{
    assert(m_block_allocators == NULL);

    m_block_allocators = new BlockAllocators();
}

void BlockAllocators::destroy()
{
    assert(m_block_allocators != NULL);
    delete m_block_allocators;
    m_block_allocators = NULL;
}

// standard new & delete
void * BlockAllocators::operator new(size_t i_size)
{
    return _aligned_malloc(i_size, 4);
}

void BlockAllocators::operator delete(void * i_ptr)
{
    // don't delete NULL pointers. i guess we could also assert
    if (i_ptr)
        _aligned_free(i_ptr);
}