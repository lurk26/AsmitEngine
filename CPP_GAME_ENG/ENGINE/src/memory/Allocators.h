#ifndef __ALLOCATORS_H
#define __ALLOCATORS_H

void * operator new(size_t i_size);
void operator delete(void * i_ptr);

void * operator new[](size_t i_size);
void operator delete[](void * i_ptr);

void * operator new( size_t i_size, void * i_pmem );
void operator delete( void * i_ptr, void * i_pmem );

void * operator new[]( size_t i_size, void * i_pmem );
void operator delete[]( void * i_ptr, void * i_pmem );

// custom alignment allocators
enum NewAlignment
{
	NEW_ALIGN_DEFAULT,
	NEW_ALIGN_16 = 16,
	NEW_ALIGN_32 = 32
};

void * operator new(size_t i_size, NewAlignment i_align);
void operator delete(void * i_ptr, NewAlignment i_align);

// tracking allocators
void * operator new(size_t i_size, const char * i_pFile, unsigned int i_Line);
void operator delete(void * i_ptr, const char * i_pFile, unsigned int i_Line);

#ifdef _DEBUG
#define TRACK_NEW (__FILE__,__LINE__)
#else
#define TRACK_NEW
#endif

#endif // __ALLOCATORS_H