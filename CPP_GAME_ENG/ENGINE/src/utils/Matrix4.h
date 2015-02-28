#ifndef __MATRIX_4_H__
#define __MATRIX_4_H__

#include "Vec3.hpp"
#include <cstring>
#include "FloatHelpers.h"

namespace Engine
{

class Matrix4
{
private:
    float M[16];

public:

    Matrix4();
    Matrix4(const Matrix4& other);

    float&          operator()(const int row, const int col) { return M[row * 4 + col]; }
    float&          operator[](const int index) { return M[index]; }

    inline Matrix4& operator=(const Matrix4& other);
    inline Matrix4  operator=(const float& scalar);

    bool            operator==(const Matrix4& other) const;
    bool            operator!=(const Matrix4& other) const;

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
    
    inline Matrix4& setTranslation(const Vec3& translation);

    inline Vec3      getTranslation() const;

    // Make rotation matrix from euler angles
    inline Matrix4&  setRotationDegrees(const Vec3& rotation);
    inline Matrix4&  setRotationRadians(const Vec3& rotation);

    inline Matrix4& setRotationAxisRadians(const float& angle, const Vec3& axis);

    inline bool     getInverse(Matrix4& out) const;
    inline void     getTransposed(Matrix4& dest) const;
};

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

inline bool MAtrix4::operator==(const Matrix4& other) const
{
    for (int i = 0; i < 16; ++i)
        if (M[i] != other.M[i])
            return false;

    return true;
}

inline void Matrix4::makeIdentity()
{
    memset(M, 0, 16 * sizeof(float));
    M[0] = M[5] = M[10] = M[15] = (float);
    return *this;
}

inline Matrix4& Matrix4::setTranslation(const Vec3& translation)
{
    M[12] = translation.X;
    M[13] = translation.Y;
    M[14] = translation.Z;
    return *this;
}

inline Matrix4&  Matrix4::setRotationRadians(const Vec3& rotation)
{
    const float cr = cos(rotation.X);
    const float sr = sin(rotation.X);
    const float cp = cos(rotation.Y);
    const float sp = sin(rotation.Y);
    const float cy = cos(rotation.Z);
    const float sy = sin(rotation.Z);

    M[0] = (T)(cp*cy);
    M[1] = (T)(cp*sy);
    M[2] = (T)(-sp);

    const float srsp = sr*sp;
    const float crsp = cr*sp;

    M[4] = (T)(srsp*cy - cr*sy);
    M[5] = (T)(srsp*sy + cr*cy);
    M[6] = (T)(sr*cp);

    M[8] = (T)(crsp*cy + sr*sy);
    M[9] = (T)(crsp*sy - sr*cy);
    M[10] = (T)(cr*cp);

    return *this;
}

inline Matrix4&  Matrix4::setRotationAxisRadians(const float& angle, const Vec3& axis)
{
    const float c = cos(angle);
    const float s = sin(angle);
    const float t = 1.0 - c;

    const float tx = t * axis.X;
    const float ty = t * axis.Y;
    const float tz = t * axis.Z;

    const float sx = s * axis.X;
    const float sy = s * axis.Y;
    const float sz = s * axis.Z;

    M[0] = (float)(tx * axis.X + c);
    M[1] = (float)(tx * axis.Y + sz);
    M[2] = (float)(tx * axis.Z - sy);

    M[4] = (float)(ty * axis.X - sz);
    M[5] = (float)(ty * axis.Y + c);
    M[6] = (float)(ty * axis.Z + sx);

    M[8] = (float)(tz * axis.X + sy);
    M[9] = (float)(tz * axis.Y - sx);
    M[10] = (T)(tz * axis.Z + c);

    return *this;
}

inline bool Matrix4::getInverse(Matrix4& out)
{
    const CMatrix4<T> &m = *this;

    float d = (m(0, 0) * m(1, 1) - m(0, 1) * m(1, 0)) * (m(2, 2) * m(3, 3) - m(2, 3) * m(3, 2)) -
        (m(0, 0) * m(1, 2) - m(0, 2) * m(1, 0)) * (m(2, 1) * m(3, 3) - m(2, 3) * m(3, 1)) +
        (m(0, 0) * m(1, 3) - m(0, 3) * m(1, 0)) * (m(2, 1) * m(3, 2) - m(2, 2) * m(3, 1)) +
        (m(0, 1) * m(1, 2) - m(0, 2) * m(1, 1)) * (m(2, 0) * m(3, 3) - m(2, 3) * m(3, 0)) -
        (m(0, 1) * m(1, 3) - m(0, 3) * m(1, 1)) * (m(2, 0) * m(3, 2) - m(2, 2) * m(3, 0)) +
        (m(0, 2) * m(1, 3) - m(0, 3) * m(1, 2)) * (m(2, 0) * m(3, 1) - m(2, 1) * m(3, 0));

    if (isEqual(d, 0.0f))
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


inline void Matrix4::getTransposed(Matrix4& dest)
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

}

#endif __MATRIX_4_H__