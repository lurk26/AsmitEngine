#include <cmath>
#include <assert.h>

#ifndef HEADER_VEC3_HPP
#define HEADER_VEC3_HPP

class Vec3
{
private:
    float m_floats[3];
    
public:
    
    ~Vec3();

    inline Vec3(float x, float y, float z) 
    { 
        m_floats[0] = x; 
        m_floats[1] = y;
        m_floats[2] = z;
    }

    inline Vec3() : Vec3(0.0f, 0.0f, 0.0f){}

    inline Vec3(float x) : Vec3(x, x, x) {}

    inline       float&    operator[](int n)        { return m_floats[n]; }
    inline const float&    operator[](int n) const  { return m_floats[n]; }

    inline const float&    getX() const             { return m_floats[0]; }
    inline const float&    getY() const             { return m_floats[1]; }
    inline const float&    getZ() const             { return m_floats[2]; }

    inline void            setX(float x)            { m_floats[0] = x; }
    inline void            setY(float y)            { m_floats[1] = y; }
    inline void            setZ(float z)            { m_floats[2] = z; }

    inline const float&    X() const                { return m_floats[0]; }
    inline const float&    Y() const                { return m_floats[1]; }
    inline const float&    Z() const                { return m_floats[2]; }

    inline Vec3&           operator*=(const float& s)
    {
        m_floats[0] *= s; m_floats[1] *= s; m_floats[2] *= s;
        return *this;
    }

    inline Vec3&           operator/=(const float& s)
    {
        assert(s != float(0.0));
        return *this *= float(1.0) / s;
    }

    inline float           length2() const          { return dot(*this); }
    inline float           length()  const          { return sqrt(length2()); }
    inline Vec3&           normalize()              { return *this/=length();}

    inline float           dot(const Vec3& v) const
    {
        return m_floats[0] * v.X() + m_floats[1] * v.Y() + m_floats[2] * v.Z();
    }

};

inline Vec3 operator*(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1.X() * v2.X(), v1.Y() * v2.Y(), v1.Z() * v2.Z());
}

inline Vec3 operator*(const float& s, const Vec3& v)
{
    return Vec3(s * v.X(), s * v.Y(), s * v.Z());
}

inline Vec3 operator*(const Vec3& v, const float& s)
{
    return Vec3(s * v.X(), s * v.Y(), s * v.Z());
}

inline Vec3 operator/(const Vec3& v, const float& s)
{
    assert(s != float(0.0));
    return v * (float(1.0) / s);
}

inline Vec3 operator+(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1.X() + v2.X(), v1.Y() + v2.Y(), v1.Z() + v2.Z());
}

inline Vec3 operator-(const Vec3& v1, const Vec3& v2)
{
    return Vec3(v1.X() - v2.X(), v1.Y() - v2.Y(), v1.Z() - v2.Z());
}


#endif