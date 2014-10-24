#ifndef HEADER_SMALL_BLOCK_ALLOCATOR_HPP
#define HEADER_SMALL_BLOCK_ALLOCATOR_HPP

#include <cstdlib>

class BitField;

class SmallBlockAllocator
{

private:

    void *      m_p_memory;
    BitField *  m_bitfield;
    size_t      m_block_size;
    size_t      m_block_count;

    SmallBlockAllocator(size_t block_size, size_t block_count, void * p_memory, BitField * bitfield);
public:

    static SmallBlockAllocator * create(size_t block_size, size_t block_count);
    ~SmallBlockAllocator();
    
    void * _alloc();
    void   _free(void * pmem);


};

SmallBlockAllocator::SmallBlockAllocator(size_t block_size, size_t block_count, void * p_memory, BitField * bitfield)
{
    m_block_size = block_size;
    m_block_count = block_count;
    m_p_memory = p_memory;
    m_bitfield = bitfield;
}

SmallBlockAllocator::~SmallBlockAllocator()
{

    //TODO: Check bitfield to make sure no blocks are given out
    _aligned_free(m_p_memory);

    delete m_bitfield;
}

#endif HEADER_SMALL_BLOCK_ALLOCATOR_HPP