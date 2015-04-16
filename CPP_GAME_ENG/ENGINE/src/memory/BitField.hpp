#ifndef HEADER_BIT_FIELD_HPP
#define HEADER_BIT_FIELD_HPP

#include <stdint.h>
#include <cstdlib>

class BitField
{
private:
    size_t         m_num_elements;
    uint32_t *     m_memory;
    BitField(size_t memory_block_count, void * memory);
public:
    
    static BitField*       create(size_t memory_block_count);
    ~BitField();

    bool                   operator[](size_t index);
    bool                   getNextFreeElement(size_t & o_index);
    bool                   setElement(size_t index);
    bool                   releaseElement(size_t index);
    bool                   isEmpty();

    // standard new & delete
    void * operator new(size_t i_size);

    void operator delete(void * i_ptr);

};

inline bool BitField::operator[](size_t index)
{
    size_t element = index / (sizeof(m_memory[0])*8);
    uint32_t value = m_memory[element];

    unsigned int offset = index - (element*sizeof(m_memory[0])*8);

    return value & (1 << offset);
}

inline bool BitField::getNextFreeElement(size_t & o_index)
{
    size_t element = 0;

    while (m_memory[element] == UINT32_MAX)
        element++;
    if (element >= m_num_elements) return false;

    unsigned int offset = 0;
    while (m_memory[element] & (1 << offset))
        offset++;
    o_index = element*sizeof(m_memory[0])*8 + offset;
    return true;
}

inline bool BitField::setElement(size_t index)
{
    size_t element = index / (sizeof(m_memory[0])*8);
    if (element >= m_num_elements) return false;

    unsigned int offset = index - (element*sizeof(m_memory[0])*8);
    m_memory[element] = m_memory[element] | (1 << offset);
    return true;
}

inline bool BitField::releaseElement(size_t index)
{
    size_t element = index / (sizeof(m_memory[0])*8);
    if (element >= m_num_elements) return false;

    unsigned int offset = index - (element*sizeof(m_memory[0])*8);
    m_memory[element] = m_memory[element] & ~(1 << offset);
    return true;
}

inline bool BitField::isEmpty()
{
    size_t element = 0;
    while (element < m_num_elements)
    {
        if (m_memory[element] != 0) return false;
        element++;
    }

    return true;

}
#endif HEADER_BIT_FIELD_HPP