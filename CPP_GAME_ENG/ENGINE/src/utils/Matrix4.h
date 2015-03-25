#ifndef __MATRIX_4_H__
#define __MATRIX_4_H__

#include "Vec3.hpp"
#include <cstring>
#include "FloatHelpers.h"

#include <iostream>

namespace Engine
{

class Matrix4
{
private:
    float M[16];

public:

    Matrix4() {};
    Matrix4(const Matrix4& other);
    float&          operator()(const int row, const int col) 
                                            { return M[row * 4 + col]; }
    const float&    operator()(const int row, const int col) const 
                                            { return M[row * 4 + col]; }
    
    float&    operator[](const int index) { return M[index]; }
    const float&    operator[](const int index) const { return M[index]; }

    inline Matrix4& operator=(const Matrix4& other);
    inline Matrix4  operator=(const float& scalar);

    inline bool     operator==(const Matrix4& other) const;
    static inline bool isEqual(const Matrix4& a, const Matrix4& b);
    inline bool     operator!=(const Matrix4& other) const;

    inline Matrix4  operator+(const Matrix4& other) const;
    inline Matrix4& operator+=(const Matrix4& other);

    inline Matrix4  operator-(const Matrix4& other) const;
    inline Matrix4  operator-=(const Matrix4& other) const;

    inline Matrix4  operator*(const Matrix4& other) const;
    inline Matrix4& operator*=(const Matrix4& other);
    inline Matrix4  operator*(const float scalar) const;
    inline Matrix4& operator*=(const float scalar);

    inline void     makeIdentity();
    inline bool     isIdentity() const {};
    
    inline void     setFromArray(float *d);

    inline Matrix4& setTranslation(const Vec3& translation);

    inline Vec3      getTranslation() const;

    // Make rotation matrix from euler angles
    inline Matrix4&  setRotationDegrees(const Vec3& rotation);
    inline Matrix4&  setRotationRadians(const Vec3& rotation);
    inline Vec3      getRotationDegrees() const;

    inline Matrix4& setRotationAxisRadians(const float& angle, const Vec3& axis);

    inline bool     getInverse(Matrix4& out) const;
    inline void     getTransposed(Matrix4& dest) const;

    // Rotate a vector by the rotation part of this matrix.
    inline void     rotateVect(Vec3& vect) const;

    // An alternate transform vector method, writing into a second vector
    inline void     rotateVect(Vec3& out, const Vec3& in) const;

    // Transforms the vector by this matrix
    inline void     transformVect(Vec3& vect) const;

    // Transforms input vector by this matrix and stores result in output vector
    inline void     transformVect(Vec3& out, const Vec3& in) const;
};

inline Matrix4::Matrix4(const Matrix4& other)
{ 
    std::cout << "Consturctor called\n";
    *this = other;
}
inline Matrix4& Matrix4::operator=(const Matrix4& other)
{
    
    if (this == &other)
        return *this;
    memcpy(M, other.M, 16 * sizeof(float));
    return *this;
}

inline Matrix4  Matrix4::operator=(const float& scalar)
{
    for (int i = 0; i < 16; ++i)
        M[i] = scalar;
    return *this;
}

inline bool Matrix4::operator==(const Matrix4& other) const
{
    for (int i = 0; i < 16; ++i)
        if (M[i] != other.M[i])
            return false;

    return true;
}

inline bool Matrix4::isEqual(const Matrix4& a, const Matrix4& b)
{
    for (int i = 0; i < 16; ++i)
        if (!Engine::isEqual(a.M[i], b.M[i]))
            return false;

    return true;
}

inline Matrix4 Matrix4::operator*(const Matrix4& m1) const
{
    Matrix4 m3;
    const float *m2 = M;
    
    m3[0] = m1[0] * m2[0] + m1[4] * m2[1] + m1[8] * m2[2] + m1[12] * m2[3];
    m3[1] = m1[1] * m2[0] + m1[5] * m2[1] + m1[9] * m2[2] + m1[13] * m2[3];
    m3[2] = m1[2] * m2[0] + m1[6] * m2[1] + m1[10] * m2[2] + m1[14] * m2[3];
    m3[3] = m1[3] * m2[0] + m1[7] * m2[1] + m1[11] * m2[2] + m1[15] * m2[3];

    m3[4] = m1[0] * m2[4] + m1[4] * m2[5] + m1[8] * m2[6] + m1[12] * m2[7];
    m3[5] = m1[1] * m2[4] + m1[5] * m2[5] + m1[9] * m2[6] + m1[13] * m2[7];
    m3[6] = m1[2] * m2[4] + m1[6] * m2[5] + m1[10] * m2[6] + m1[14] * m2[7];
    m3[7] = m1[3] * m2[4] + m1[7] * m2[5] + m1[11] * m2[6] + m1[15] * m2[7];

    m3[8] = m1[0] * m2[8] + m1[4] * m2[9] + m1[8] * m2[10] + m1[12] * m2[11];
    m3[9] = m1[1] * m2[8] + m1[5] * m2[9] + m1[9] * m2[10] + m1[13] * m2[11];
    m3[10] = m1[2] * m2[8] + m1[6] * m2[9] + m1[10] * m2[10] + m1[14] * m2[11];
    m3[11] = m1[3] * m2[8] + m1[7] * m2[9] + m1[11] * m2[10] + m1[15] * m2[11];

    m3[12] = m1[0] * m2[12] + m1[4] * m2[13] + m1[8] * m2[14] + m1[12] * m2[15];
    m3[13] = m1[1] * m2[12] + m1[5] * m2[13] + m1[9] * m2[14] + m1[13] * m2[15];
    m3[14] = m1[2] * m2[12] + m1[6] * m2[13] + m1[10] * m2[14] + m1[14] * m2[15];
    m3[15] = m1[3] * m2[12] + m1[7] * m2[13] + m1[11] * m2[14] + m1[15] * m2[15];
    return m3;
}

inline void Matrix4::makeIdentity()
{
    memset(M, 0, 16 * sizeof(float));
    M[0] = M[5] = M[10] = M[15] = (float)1;
}

inline void Matrix4::setFromArray(float *d)
{
    for (int i = 0; i < 16; ++i)
        M[i] = *(d + i);
}

inline Matrix4& Matrix4::setTranslation(const Vec3& translation)
{
    M[12] = translation.X();
    M[13] = translation.Y();
    M[14] = translation.Z();
    return *this;
}

inline Vec3 Matrix4::getTranslation() const
{
    return Vec3(M[12], M[13], M[14]);
}

// Make a rotation matrix from Euler angles.
inline Matrix4&  Matrix4::setRotationRadians(const Vec3& rotation)
{
    const float cr = cos(rotation.X());
    const float sr = sin(rotation.X());
    const float cp = cos(rotation.Y());
    const float sp = sin(rotation.Y());
    const float cy = cos(rotation.Z());
    const float sy = sin(rotation.Z());

    M[0] = (float)(cp*cy);
    M[1] = (float)(cp*sy);
    M[2] = (float)(-sp);

    const float srsp = sr*sp;
    const float crsp = cr*sp;

    M[4] = (float)(srsp*cy - cr*sy);
    M[5] = (float)(srsp*sy + cr*cy);
    M[6] = (float)(sr*cp);

    M[8] = (float)(crsp*cy + sr*sy);
    M[9] = (float)(crsp*sy - sr*cy);
    M[10] = (float)(cr*cp);

    return *this;
}


inline Matrix4&  Matrix4::setRotationAxisRadians(const float& angle, const Vec3& axis)
{
    const float c = cos(angle);
    const float s = sin(angle);
    const float t = 1.0f - c;

    const float tx = t * axis.X();
    const float ty = t * axis.Y();
    const float tz = t * axis.Z();

    const float sx = s * axis.X();
    const float sy = s * axis.Y();
    const float sz = s * axis.Z();

    M[0] = (float)(tx * axis.X() + c);
    M[1] = (float)(tx * axis.Y() + sz);
    M[2] = (float)(tx * axis.Z() - sy);

    M[4] = (float)(ty * axis.X() - sz);
    M[5] = (float)(ty * axis.Y() + c);
    M[6] = (float)(ty * axis.Z() + sx);

    M[8] = (float)(tz * axis.X() + sy);
    M[9] = (float)(tz * axis.Y() - sx);
    M[10] = (float)(tz * axis.Z() + c);

    return *this;
}

inline bool Matrix4::getInverse(Matrix4& out) const
{
    const Matrix4 &m = *this;

    float d = (m(0, 0) * m(1, 1) - m(0, 1) * m(1, 0)) * (m(2, 2) * m(3, 3) - m(2, 3) * m(3, 2)) -
        (m(0, 0) * m(1, 2) - m(0, 2) * m(1, 0)) * (m(2, 1) * m(3, 3) - m(2, 3) * m(3, 1)) +
        (m(0, 0) * m(1, 3) - m(0, 3) * m(1, 0)) * (m(2, 1) * m(3, 2) - m(2, 2) * m(3, 1)) +
        (m(0, 1) * m(1, 2) - m(0, 2) * m(1, 1)) * (m(2, 0) * m(3, 3) - m(2, 3) * m(3, 0)) -
        (m(0, 1) * m(1, 3) - m(0, 3) * m(1, 1)) * (m(2, 0) * m(3, 2) - m(2, 2) * m(3, 0)) +
        (m(0, 2) * m(1, 3) - m(0, 3) * m(1, 2)) * (m(2, 0) * m(3, 1) - m(2, 1) * m(3, 0));

    if (Engine::isEqual(d, 0.0f))
        return false;

    d = 1.f/(d);

    out(0, 0) = d * (m(1, 1) * (m(2, 2) * m(3, 3) - m(2, 3) * m(3, 2)) +
        m(1, 2) * (m(2, 3) * m(3, 1) - m(2, 1) * m(3, 3)) +
        m(1, 3) * (m(2, 1) * m(3, 2) - m(2, 2) * m(3, 1)));
    out(0, 1) = d * (m(2, 1) * (m(0, 2) * m(3, 3) - m(0, 3) * m(3, 2)) +
        m(2, 2) * (m(0, 3) * m(3, 1) - m(0, 1) * m(3, 3)) +
        m(2, 3) * (m(0, 1) * m(3, 2) - m(0, 2) * m(3, 1)));
    out(0, 2) = d * (m(3, 1) * (m(0, 2) * m(1, 3) - m(0, 3) * m(1, 2)) +
        m(3, 2) * (m(0, 3) * m(1, 1) - m(0, 1) * m(1, 3)) +
        m(3, 3) * (m(0, 1) * m(1, 2) - m(0, 2) * m(1, 1)));
    out(0, 3) = d * (m(0, 1) * (m(1, 3) * m(2, 2) - m(1, 2) * m(2, 3)) +
        m(0, 2) * (m(1, 1) * m(2, 3) - m(1, 3) * m(2, 1)) +
        m(0, 3) * (m(1, 2) * m(2, 1) - m(1, 1) * m(2, 2)));
    out(1, 0) = d * (m(1, 2) * (m(2, 0) * m(3, 3) - m(2, 3) * m(3, 0)) +
        m(1, 3) * (m(2, 2) * m(3, 0) - m(2, 0) * m(3, 2)) +
        m(1, 0) * (m(2, 3) * m(3, 2) - m(2, 2) * m(3, 3)));
    out(1, 1) = d * (m(2, 2) * (m(0, 0) * m(3, 3) - m(0, 3) * m(3, 0)) +
        m(2, 3) * (m(0, 2) * m(3, 0) - m(0, 0) * m(3, 2)) +
        m(2, 0) * (m(0, 3) * m(3, 2) - m(0, 2) * m(3, 3)));
    out(1, 2) = d * (m(3, 2) * (m(0, 0) * m(1, 3) - m(0, 3) * m(1, 0)) +
        m(3, 3) * (m(0, 2) * m(1, 0) - m(0, 0) * m(1, 2)) +
        m(3, 0) * (m(0, 3) * m(1, 2) - m(0, 2) * m(1, 3)));
    out(1, 3) = d * (m(0, 2) * (m(1, 3) * m(2, 0) - m(1, 0) * m(2, 3)) +
        m(0, 3) * (m(1, 0) * m(2, 2) - m(1, 2) * m(2, 0)) +
        m(0, 0) * (m(1, 2) * m(2, 3) - m(1, 3) * m(2, 2)));
    out(2, 0) = d * (m(1, 3) * (m(2, 0) * m(3, 1) - m(2, 1) * m(3, 0)) +
        m(1, 0) * (m(2, 1) * m(3, 3) - m(2, 3) * m(3, 1)) +
        m(1, 1) * (m(2, 3) * m(3, 0) - m(2, 0) * m(3, 3)));
    out(2, 1) = d * (m(2, 3) * (m(0, 0) * m(3, 1) - m(0, 1) * m(3, 0)) +
        m(2, 0) * (m(0, 1) * m(3, 3) - m(0, 3) * m(3, 1)) +
        m(2, 1) * (m(0, 3) * m(3, 0) - m(0, 0) * m(3, 3)));
    out(2, 2) = d * (m(3, 3) * (m(0, 0) * m(1, 1) - m(0, 1) * m(1, 0)) +
        m(3, 0) * (m(0, 1) * m(1, 3) - m(0, 3) * m(1, 1)) +
        m(3, 1) * (m(0, 3) * m(1, 0) - m(0, 0) * m(1, 3)));
    out(2, 3) = d * (m(0, 3) * (m(1, 1) * m(2, 0) - m(1, 0) * m(2, 1)) +
        m(0, 0) * (m(1, 3) * m(2, 1) - m(1, 1) * m(2, 3)) +
        m(0, 1) * (m(1, 0) * m(2, 3) - m(1, 3) * m(2, 0)));
    out(3, 0) = d * (m(1, 0) * (m(2, 2) * m(3, 1) - m(2, 1) * m(3, 2)) +
        m(1, 1) * (m(2, 0) * m(3, 2) - m(2, 2) * m(3, 0)) +
        m(1, 2) * (m(2, 1) * m(3, 0) - m(2, 0) * m(3, 1)));
    out(3, 1) = d * (m(2, 0) * (m(0, 2) * m(3, 1) - m(0, 1) * m(3, 2)) +
        m(2, 1) * (m(0, 0) * m(3, 2) - m(0, 2) * m(3, 0)) +
        m(2, 2) * (m(0, 1) * m(3, 0) - m(0, 0) * m(3, 1)));
    out(3, 2) = d * (m(3, 0) * (m(0, 2) * m(1, 1) - m(0, 1) * m(1, 2)) +
        m(3, 1) * (m(0, 0) * m(1, 2) - m(0, 2) * m(1, 0)) +
        m(3, 2) * (m(0, 1) * m(1, 0) - m(0, 0) * m(1, 1)));
    out(3, 3) = d * (m(0, 0) * (m(1, 1) * m(2, 2) - m(1, 2) * m(2, 1)) +
        m(0, 1) * (m(1, 2) * m(2, 0) - m(1, 0) * m(2, 2)) +
        m(0, 2) * (m(1, 0) * m(2, 1) - m(1, 1) * m(2, 0)));
    
    return true;
}


inline void Matrix4::getTransposed(Matrix4& dest) const
{
    dest[0] = M[0];
    dest[1] = M[4];
    dest[2] = M[8];
    dest[3] = M[12];

    dest[4] = M[1];
    dest[5] = M[5];
    dest[6] = M[9];
    dest[7] = M[13];

    dest[8] = M[2];
    dest[9] = M[6];
    dest[10] = M[10];
    dest[11] = M[14];

    dest[12] = M[3];
    dest[13] = M[7];
    dest[14] = M[11];
    dest[15] = M[15];
}

inline void Matrix4::rotateVect(Vec3& vect) const
{
    Vec3 tmp = vect;
    vect[0] = tmp.X()*M[0] + tmp.Y()*M[4] + tmp.Z()*M[8];
    vect[1] = tmp.X()*M[1] + tmp.Y()*M[5] + tmp.Z()*M[9];
    vect[2] = tmp.X()*M[2] + tmp.Y()*M[6] + tmp.Z()*M[10];
}

inline void Matrix4::rotateVect(Vec3& out, const Vec3& in) const
{
    out[0] = in.X()*M[0] + in.Y()*M[4] + in.Z()*M[8];
    out[1] = in.X()*M[1] + in.Y()*M[5] + in.Z()*M[9];
    out[2] = in.X()*M[2] + in.Y()*M[6] + in.Z()*M[10];
}

inline void Matrix4::transformVect(Vec3& vect) const
{
    float vector[3];

    vector[0] = vect.X()*M[0] + vect.Y()*M[4] + vect.Z()*M[8] + M[12];
    vector[1] = vect.X()*M[1] + vect.Y()*M[5] + vect.Z()*M[9] + M[13];
    vector[2] = vect.X()*M[2] + vect.Y()*M[6] + vect.Z()*M[10] + M[14];

    vect[0] = vector[0];
    vect[1] = vector[1];
    vect[2] = vector[2];
}

inline void Matrix4::transformVect(Vec3& out, const Vec3& in) const
{
    out[0] = in.X()*M[0] + in.Y()*M[4] + in.Z()*M[8] + M[12];
    out[1] = in.X()*M[1] + in.Y()*M[5] + in.Z()*M[9] + M[13];
    out[2] = in.X()*M[2] + in.Y()*M[6] + in.Z()*M[10] + M[14];
}

}

#endif __MATRIX_4_H__