#include <malloc.h>		// for _aligned_malloc
#include <stdio.h>		// for printf

#include "Allocators.h"
#include "BlockAllocators.hpp"

// standard new & delete
void * operator new(size_t i_size)
{
	printf("Calling new( size_t ) with size %d.\n\n", i_size);

    if (i_size <= 8)
    {
        return BlockAllocators::get()->getSMBAllocator(8)->_alloc();
    }
    if (i_size > 8 && i_size <= 16)
    {
        return BlockAllocators::get()->getSMBAllocator(16)->_alloc();
    }
	return _aligned_malloc(i_size, 4);
}

void operator delete(void * i_ptr)
{
	printf("Calling delete( void * ) on %p.\n\n", i_ptr);
    if (BlockAllocators::get()->getSMBAllocator(8)->contains(i_ptr))
    {
        BlockAllocators::get()->getSMBAllocator(8)->_free(i_ptr);
    }
    else if (BlockAllocators::get()->getSMBAllocator(8)->contains(i_ptr))
    {
        BlockAllocators::get()->getSMBAllocator(8)->_free(i_ptr);
    }
    else if (i_ptr) // don't delete NULL pointers. i guess we could also assert
		_aligned_free(i_ptr);
}

// array new[] and delete[]
void * operator new[](size_t i_size)
{
	printf("Calling new[]( size_t ) with size %d.\n\n", i_size);

	void * pmem = _aligned_malloc(i_size, 4);
	printf("new[]( size_t ) returned %p.\n\n", pmem);
	return pmem;
}

void operator delete[](void * i_ptr)
{
	printf("Calling delete[]( void * ) on %p.\n\n", i_ptr);

	// don't delete NULL pointers. i guess we could also assert
	if (i_ptr)
		_aligned_free(i_ptr);
}

void * operator new(size_t i_size, NewAlignment i_align)
{
	printf("Calling new( size_t, NewAlignment ) with ( %d, %d ).\n\n", i_size, i_align);

	switch (i_align)
	{
	case NEW_ALIGN_16:
	case NEW_ALIGN_32:
		return _aligned_malloc(i_size, i_align);
	default:
		return _aligned_malloc(i_size, 4);
	}
}

// needed to keep compiler happy if above operator throws which
// is important if exception handling is enabled
void operator delete(void * i_ptr, NewAlignment i_align)
{
	printf("Calling delete( void *, NewAlignment ) with ( %08X, %d ).\n\n", i_ptr, i_align);
	printf("BTW... this should never happen.\n\n");

	// don't attempt to delete NULL pointers. i guess we could also assert
	if (i_ptr != 0)
		_aligned_free(i_ptr);
}


// tracking allocators
void * operator new(size_t i_size, const char * i_pFile, unsigned int i_Line)
{
	printf("Calling new( size_t ) with size %d from %s:%d.\n\n", i_size, i_pFile, i_Line);

	void * pMem = _aligned_malloc(i_size, 4);

	// StoreTrackingInfo( pMem, i_pFile, i_Line);

	return pMem;
}

void operator delete(void * i_ptr, const char * i_pFile, unsigned int i_Line)
{
	printf("Calling delete( void *, unsigned int, const char * ) with ( %p, %s, %d ).\n\n", i_ptr, i_pFile, i_Line);
	printf("BTW... this should never happen.\n\n");

	// don't attempt to delete NULL pointers. i guess we could also assert
	if (i_ptr != 0)
		_aligned_free(i_ptr);

}