namespace Engine
{
    template<typename T>
    inline AutoPtr<T>::AutoPtr(T * i_ptr) :
        m_ptr(i_ptr)
    {
    }

    template<typename T>
    inline AutoPtr<T>::AutoPtr(AutoPtr & i_other) :
        m_ptr(i_other.m_ptr)
    {
        // create new AutoPtr by taking ownership of existing AutoPtr
        // remember: There can be only one!
        if (i_other.m_ptr)
        {
            delete i_other.m_ptr;
            i_other.m_ptr = NULL;
        }

    }

    template<typename T>
    inline AutoPtr<T> & AutoPtr<T>::operator=(AutoPtr & i_other)
    {
        if (this != &i_other)
        {
            // replace our existing ptr by taking ownership of another AutoPtr
            if (m_ptr)
                delete(m_ptr);

            m_ptr = i_other.m_ptr;

            i_other.m_ptr = NULL;

            return *this;
        }
    }

    template<typename T>
    inline AutoPtr<T>::~AutoPtr()
    {
        if (m_ptr)
            delete m_ptr;
    }

    template<typename T>
    inline T * AutoPtr<T>::operator->()
    {
        return m_ptr;
    }

    template<typename T>
    inline T & AutoPtr<T>::operator*()
    {
        assert(m_ptr);

        return *m_ptr;
    }

} // namespace Engine
