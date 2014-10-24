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


#endif HEADER_BIT_FIELD_HPP