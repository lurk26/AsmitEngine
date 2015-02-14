#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <assert.h>
#include <inttypes.h>

namespace Engine
{

    template<typename T>
    class SharedPtr
    {
    public:
        explicit SharedPtr(T * i_ptr);
        SharedPtr();

        SharedPtr(SharedPtr & i_other);
        SharedPtr & operator=(SharedPtr & i_other);

        ~SharedPtr();

        T* operator->();
        T& operator*();

        // release();
        // change( T * i_newptr );

    private:
        T * 	m_ptr;
        uint32_t* m_pRefCount;
    };


} // namespace Engine


#include "SharedPtr-inl.h"

#endif