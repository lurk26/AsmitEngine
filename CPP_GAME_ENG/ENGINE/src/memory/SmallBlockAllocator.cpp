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

