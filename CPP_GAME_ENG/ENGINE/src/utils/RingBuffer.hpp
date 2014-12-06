#ifndef  HEADER_RINGBUFFER_H
#define  HEADER_RINGBUFFER_H

#include <vector>

template<typename T>
class RingBuffer
{
private:
    std::vector<T> m_items;
    size_t m_size;
    size_t m_current;
    
public:
    RingBuffer(size_t i_size)
    {
        m_size = i_size;
        m_current = -1;
        m_items.resize(i_size);
    }

    void add(const T & i_item)
    {
        m_current = (m_current + 1) % m_size;
        m_items[m_current] = i_item;
    }

    const T & operator[] (size_t i_index)
    {
        int temp_index = m_current - i_index;

        while (temp_index < 0) temp_index += m_size;

        return m_items[temp_index];
    }

    size_t size()
    {
        return m_size;
    }

};


#endif 