#ifndef HEADER_BIT_FIELD_HPP
#define HEADER_BIT_FIELD_HPP

#include <cstdlib>

class BitField
{
private:
    unsigned int * m_memory;
    size_t         m_num_blocks;
    BitField(size_t memory_block_count, void * memory);
public:
    
    static BitField*       create(size_t memory_block_count);
    ~BitField();
};

BitField::BitField(size_t memory_block_count, void * memory)
{
    m_memory = reinterpret_cast<unsigned int*>(memory);
    m_num_blocks = memory_block_count;
}

BitField::~BitField()
{
    free(m_memory);
}

BitField* BitField::create(size_t memory_block_count)
{
    size_t quotient = memory_block_count / sizeof(unsigned int) * 8;
    size_t remainder = memory_block_count%sizeof(unsigned int) * 8;

    int num_ints;
    if (remainder != 0)
        num_ints = quotient + 1;
    else num_ints - quotient;

    void * memory = _aligned_malloc(num_ints*sizeof(unsigned int),64);
    if (memory == NULL)
        return NULL;

    return new BitField(memory_block_count, memory);

}

#endif HEADER_BIT_FIELD_HPP