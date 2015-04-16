#ifndef __AUTO_PTR_H
#define __AUTO_PTR_H

#include <assert.h>

namespace Engine
{

template<typename T>
class AutoPtr
{
public:
	explicit AutoPtr( T * i_ptr );
	
	AutoPtr( AutoPtr & i_other );
	AutoPtr & operator=( AutoPtr & i_other );
	
	~AutoPtr();	

	T* operator->();
	T& operator*();
	
	// release();
	// change( T * i_newptr );

private:
	T * 	m_ptr;
};

   
} // namespace Engine

#include "AutoPtr-inl.h"

#endif // __AUTO_PTR_H	