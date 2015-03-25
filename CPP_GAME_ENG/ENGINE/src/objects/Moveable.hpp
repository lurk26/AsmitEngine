#ifndef HEADER_MOVEABLE_HPP
#define HEADER_MOVEABLE_HPP

#include "utils/vec3.hpp"
#include "utils\Matrix4.h"


typedef Engine::Matrix4 Transform;
namespace Engine
{
    class Moveable
    {
    private:
        Transform   m_trans;
        Vec3        m_rpy;
        Vec3        m_velocity;
        Vec3        m_position;
        Vec3        m_old_velocity;
        bool        m_is_active;
    public:
        Moveable();
        ~Moveable();


        const Vec3        getVelocity() const             { return m_velocity; }
        const Vec3        getPosition() const             { return m_trans.getTranslation(); }
        const Vec3        getRotation() const              { return m_rpy; }
        const Transform&   getTrans() const                { return m_trans; }
        const bool         isActive()    const             { return m_is_active; }

        void        setRotation(Vec3 euler_angles)  { m_rpy = euler_angles; m_trans.setRotationRadians(m_rpy); }
        void        setPosition(const Vec3& pos)    { m_trans.setTranslation(pos); }
        void        setTrans(const Transform& trans){ m_trans = trans; }
        void        setVelocity(const Vec3& vel)    { m_old_velocity = m_velocity; m_velocity = vel; }
        void        setActive(const bool state)     { m_is_active = state; }

        void        update(float dt);
    };
}
#endif