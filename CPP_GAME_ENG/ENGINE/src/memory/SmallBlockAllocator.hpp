#ifndef HEADER_SMALL_BLOCK_ALLOCATOR_HPP
#define HEADER_SMALL_BLOCK_ALLOCATOR_HPP

#include "BitField.hpp"
#include <cstdlib>

//class Bitfield;

class SmallBlockAllocator
{

private:

    void *      m_p_memory;
    BitField*   m_bitfield;
    size_t      m_block_size;
    size_t      m_block_count;

    SmallBlockAllocator(size_t block_size, size_t block_count, void * p_memory, BitField * bitfield);
public:

    static SmallBlockAllocator * create(size_t block_size, size_t block_count);
    ~SmallBlockAllocator();
    
    void * _alloc();
    void   _free(void * pmem);


};

#endif HEADER_SMALL_BLOCK_ALLOCATOR_HPP