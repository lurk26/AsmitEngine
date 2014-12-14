#ifndef HEADER_FLOAT_HELPERS_H
#define HEADER_FLOAT_HELPERS_H

#include "float.h"
#include "math.h"

bool isNan(float i_f)
{
    volatile float temp = i_f;
    return (temp != temp);
}

bool isEqual(float i_f1, float i_f2)
{
    return fabs(i_f1 - i_f2) < FLT_EPSILON;
}

bool isInfinity(float i_f)
{
    if (!isNan(i_f))
    {
        return (i_f * 0) != 0;
    }
    else return false;
}

#endif