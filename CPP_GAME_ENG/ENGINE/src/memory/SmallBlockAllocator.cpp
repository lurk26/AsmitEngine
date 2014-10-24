#include "SmallBlockAllocator.hpp"

#include "BitField.hpp"

SmallBlockAllocator* SmallBlockAllocator::create(size_t block_size, size_t block_count)
{
    void * p_memory = _aligned_malloc(block_size * block_count, 64);

    if (p_memory == NULL)
        return NULL;

    BitField * bitfield = BitField::create(block_count);

    if (bitfield == NULL)
    {
        free(p_memory);
        return NULL;
    }

    return new SmallBlockAllocator(block_size, block_count, p_memory, bitfield);
}


SmallBlockAllocator::SmallBlockAllocator(size_t block_size, size_t block_count, void * p_memory, BitField* bitfield)
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
