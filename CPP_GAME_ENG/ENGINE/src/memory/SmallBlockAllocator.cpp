#include "SmallBlockAllocator.hpp"

#include "BitField.hpp"

#include <cassert>

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

    return new SmallBlockAllocator(block_size, block_count, reinterpret_cast<uint8_t*>(p_memory), bitfield);
}


SmallBlockAllocator::SmallBlockAllocator(size_t block_size, size_t block_count, uint8_t * p_memory, BitField* bitfield)
{
    m_block_size = block_size;
    m_block_count = block_count;
    m_p_memory = p_memory;
    m_bitfield = bitfield;
    m_blocks_allocated = 0;
}

SmallBlockAllocator::~SmallBlockAllocator()
{

    //TODO: Check bitfield to make sure no blocks are given out
    assert(m_bitfield->isEmpty());
    _aligned_free(m_p_memory);

    delete m_bitfield;
}

void * SmallBlockAllocator::_alloc()
{
    size_t index;
    if (!m_bitfield->getNextFreeElement(index))
        return NULL;

    m_bitfield->setElement(index);
    m_blocks_allocated++;
    return m_p_memory + (index*m_block_size);
}

void SmallBlockAllocator::_free(void * pmem)
{
    uintptr_t check_ptr = reinterpret_cast<uintptr_t>(pmem);
    uintptr_t memory_base = reinterpret_cast<uintptr_t>(m_p_memory);
    size_t index = (check_ptr - memory_base)/m_block_size;
    assert((*m_bitfield)[index] == true);
    m_bitfield->releaseElement(index);
    m_blocks_allocated--;
}

bool  SmallBlockAllocator::contains(void * ptr)
{
    uintptr_t check_ptr = reinterpret_cast<uintptr_t>(ptr);
    uintptr_t memory_base = reinterpret_cast<uintptr_t>(m_p_memory);

    if (check_ptr < memory_base) return false;
    if (check_ptr >= memory_base + m_block_count*m_block_size) return false;
    if (check_ptr % m_block_size != 0) return false;
    if ((*m_bitfield)[(check_ptr - memory_base)/m_block_size]) return true;
    else return false;

}

// standard new & delete
void * SmallBlockAllocator::operator new(size_t i_size)
{
    return _aligned_malloc(i_size, 4);
}

void SmallBlockAllocator::operator delete(void * i_ptr)
{
    // don't delete NULL pointers. i guess we could also assert
    if (i_ptr)
        _aligned_free(i_ptr);
}