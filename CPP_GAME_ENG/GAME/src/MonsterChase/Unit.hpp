#pragma once
#ifndef HEADER_UNIT_HPP
#define HEADER_UNIT_HPP

#include "utils/Vec3.hpp"

class Unit
{

private:
    Vec3 m_position;
public:
	Unit();
	~Unit();

    Unit(float x, float y) : m_position(x, y, 0.0f) {}
    
    const Vec3& getXYZ()    { return m_position; }
    void        setXYZ(const Vec3& v) { m_position = v; }
    void    moveUnitRandomly();
    
};

#endif