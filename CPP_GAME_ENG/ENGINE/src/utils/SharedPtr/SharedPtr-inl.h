namespace Engine
{
    template<typename T>
    inline SharedPtr<T>::SharedPtr() :
        m_ptr(nullptr),
        m_pRefCount(new uint32_t(1))
    {
    }

    template<typename T>
    inline SharedPtr<T>::SharedPtr(T * i_ptr) :
        m_ptr(i_ptr),
        m_pRefCount( new uint32_t(1) )
    {
    }

    template<typename T>
    inline SharedPtr<T>::SharedPtr(SharedPtr & i_other) :
        m_ptr(i_other.m_ptr),
        m_pRefCount( i_other.m_pRefCount )
    {
        assert(m_pRefCount != nullptr);
        // create new SharedPtr by incrementing ref count
        (*m_pRefCount)++;
    }

    template<typename T>
    inline SharedPtr<T> & SharedPtr<T>::operator=(SharedPtr & i_other)
    {
        if (this != &i_other)
        {
            // release our reference to existing object
            assert(m_pRefCount != nullptr);

            if (--(*m_pRefCount) == 0)
            {
                if (m_ptr)
                    delete m_ptr;

                delete m_pRefCount;
            }

            // add ownership of i_other to object
            m_ptr = i_other.m_ptr;
            m_pRefCount = i_other.m_pRefCount;

            (*m_pRefCount)++;

            return *this;
        }
    }

    template<typename T>
    inline SharedPtr<T>::~SharedPtr()
    {
        assert(m_pRefCount != nullptr);

        if (--(*m_pRefCount) == 0)
        {
            if (m_ptr)
                delete m_ptr;
            delete m_pRefCount;
        }
    }

    template<typename T>
    inline T * SharedPtr<T>::operator->()
    {
        return m_ptr;
    }

    template<typename T>
    inline T & SharedPtr<T>::operator*()
    {
        assert(m_ptr);

        return *m_ptr;
    }

} // namespace Engine
