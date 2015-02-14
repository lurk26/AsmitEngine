#ifndef HEADER_MOVEABLE_HPP
#define HEADER_MOVEABLE_HPP

#include "utils/vec3.hpp"

#pragma once
class Moveable
{
private:
    Vec3        m_velocity;
    Vec3        m_position;
    Vec3        m_old_velocity;
    bool        m_is_active;
public:
    Moveable();
    ~Moveable();

    
    const Vec3&        getVelocity() const             { return m_velocity; }
    const Vec3&        getPosition() const             { return m_position; }
    const bool         isActive()    const             { return m_is_active; }

    void        setPosition(const Vec3& pos)    { m_position = pos; }
    void        setVelocity(const Vec3& vel)    { m_old_velocity = m_velocity; m_velocity = vel; }
    void        setActive(const bool state)     { m_is_active = state; }

    void        update(float dt);
};

#endif