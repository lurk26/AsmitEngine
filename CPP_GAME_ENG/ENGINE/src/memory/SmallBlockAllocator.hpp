#ifndef HEADER_SMALL_BLOCK_ALLOCATOR_HPP
#define HEADER_SMALL_BLOCK_ALLOCATOR_HPP

#include <cstdlib>
#include <stdint.h>

class BitField;

class SmallBlockAllocator
{

private:

    uint8_t *   m_p_memory;
    BitField*   m_bitfield;
    size_t      m_block_size;
    size_t      m_block_count;
    size_t      m_blocks_allocated;

    SmallBlockAllocator(size_t block_size, size_t block_count, uint8_t * p_memory, BitField * bitfield);
public:

    static SmallBlockAllocator * create(size_t block_size, size_t block_count);
    ~SmallBlockAllocator();
    
    void *      _alloc();
    void        _free(void * pmem);
    bool        contains(void * ptr);
    size_t      numBlocksFree() { return m_block_count - m_blocks_allocated; }

};

#endif HEADER_SMALL_BLOCK_ALLOCATOR_HPP