#include "BitField.hpp"

#include <cstring>

BitField::BitField(size_t memory_block_count, void * memory)
{
    m_memory = reinterpret_cast<unsigned int*>(memory);
    m_num_elements = memory_block_count;
}

BitField::~BitField()
{
    _aligned_free(m_memory);
}

BitField* BitField::create(size_t memory_block_count)
{
    size_t quotient = memory_block_count / sizeof(unsigned int) * 8;
    size_t remainder = memory_block_count%sizeof(unsigned int) * 8;

    int num_ints;
    if (remainder != 0)
        num_ints = quotient + 1;
    else
        num_ints = quotient;

    void * memory = _aligned_malloc(num_ints*sizeof(unsigned int), 64);
    if (memory == NULL)
        return NULL;
    memset(memory, 0, num_ints*sizeof(unsigned int));
    return new BitField(memory_block_count, memory);

}

// standard new & delete
void * BitField::operator new(size_t i_size)
{
    return _aligned_malloc(i_size, 4);
}

void BitField::operator delete(void * i_ptr)
{
    // don't delete NULL pointers. i guess we could also assert
    if (i_ptr)
        _aligned_free(i_ptr);
}
