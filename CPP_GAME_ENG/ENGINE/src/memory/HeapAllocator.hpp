#pragma once
class HeapAllocator
{
private:
    static HeapAllocator * m_heap_allocator;

    void *                 m_managed_mem_start;
    size_t                 m_managed_mem_size;

    struct BlockDescriptor
    {
        size_t size;
        BlockDescriptor* next;
        BlockDescriptor* prev;
    };

    BlockDescriptor * m_free_list;
    BlockDescriptor * m_free_list_end;

    HeapAllocator(void * pMem, size_t memSize);
    ~HeapAllocator();

public:
    static HeapAllocator*   get()           { return m_heap_allocator; }
    static bool             create(size_t sizeMem);
    static void             destroy();
    
    void *                  _alloc(size_t bytes);
    void                    _free(void* pMem);


    // standard new & delete
    void * operator new(size_t i_size);

    void operator delete(void * i_ptr);
};

