#include "HeapAllocator.hpp"

#include <cstdlib>
#include <cassert>

HeapAllocator * HeapAllocator::m_heap_allocator = NULL;

HeapAllocator::HeapAllocator(void * pMem, size_t memSize)
{
    m_managed_mem_start = pMem;
    m_managed_mem_size = memSize;

    m_free_list = reinterpret_cast<BlockDescriptor*>(m_managed_mem_start);
    m_free_list->size = memSize - sizeof(size_t);
    m_free_list->next = NULL;
    m_free_list->prev = NULL;
    m_free_list_end = m_free_list;
}


HeapAllocator::~HeapAllocator()
{
    _aligned_free(m_managed_mem_start);
}


void HeapAllocator::create(size_t memSize)
{
    assert(m_heap_allocator == NULL);

    void * pMem = _aligned_malloc(memSize, 4);
    assert(pMem);

    m_heap_allocator = new HeapAllocator(pMem, memSize);

}

void HeapAllocator::destroy()
{
    delete m_heap_allocator;
}

void * HeapAllocator::_alloc(size_t bytes)
{
    /* Holds where we are looking in memory */

    BlockDescriptor *current_free_block = m_free_list;

    while (current_free_block != NULL)
    {
        if (bytes <= (current_free_block)->size)
        {
            void * return_mem_address = current_free_block + sizeof(size_t);
            
            if ((current_free_block->size - bytes) >= sizeof(BlockDescriptor)) // can we fit another BlockDescriptor?
            {
                BlockDescriptor * new_block = reinterpret_cast<BlockDescriptor*>((char*)return_mem_address + bytes);
                new_block->size = current_free_block->size - bytes - sizeof(size_t);
                new_block->next = current_free_block->next;
                new_block->prev = current_free_block->prev;

                if (new_block->prev == NULL)
                    m_free_list = new_block;
                else
                    new_block->prev->next = new_block;
    
                if (new_block->next == NULL)
                    m_free_list_end = new_block;
                else
                    new_block->next->prev = new_block;
                
                current_free_block->size = bytes;
            }
            
            return return_mem_address;
        }
        current_free_block = current_free_block->next;
    }

    return 0;
}

void HeapAllocator::_free(void * pMem)
{
    BlockDescriptor* current_block = reinterpret_cast<BlockDescriptor*>((char*)pMem - sizeof(size_t));

    current_block->prev = NULL;
    current_block->next = m_free_list->next;
    m_free_list = current_block;
}


// standard new & delete
void * HeapAllocator::operator new(size_t i_size)
{
    return _aligned_malloc(i_size, 4);
}

void HeapAllocator::operator delete(void * i_ptr)
{
    // don't delete NULL pointers. i guess we could also assert
    if (i_ptr)
        _aligned_free(i_ptr);
}