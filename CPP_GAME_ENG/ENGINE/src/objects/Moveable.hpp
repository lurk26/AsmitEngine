

#include "utils/vec3.hpp"

#pragma once
class Moveable
{
private:
    Vec3        m_velocity;
    Vec3        m_position;

public:
    Moveable();
    ~Moveable();

    
    const Vec3&        getVelocity() const             { return m_velocity; }
    const Vec3&        getPosition() const             { return m_position; }

    void        setPosition(const Vec3& pos)    { m_position = pos; }
    void        setVelocity(const Vec3& vel)    { m_position = vel; }

    void        update();
};

