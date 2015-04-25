#include "GameObject.hpp"

namespace Engine{

GameObject::GameObject()
{
    m_trans.makeIdentity();
    m_rpy = Vec3(0,0,0);
    m_velocity = Vec3(0, 0, 0);
    m_position = Vec3(0, 0, 0);
    m_old_velocity = Vec3(0, 0, 0);
    m_is_active = 0;
}


GameObject::~GameObject()
{
}

void GameObject::update(float dt)
{
    Vec3 new_position = getPosition() + 0.5f*(m_velocity + m_old_velocity)*dt;
    setPosition(new_position);
}

}