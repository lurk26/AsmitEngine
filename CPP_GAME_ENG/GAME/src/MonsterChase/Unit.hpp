#pragma once
#ifndef HEADER_UNIT_HPP
#define HEADER_UNIT_HPP

#include "objects/Moveable.hpp"

#include "utils/SharedPtr/SharedPtr.h"

#include <string>

class Controller;

class Unit
{

private:
    Engine::SharedPtr<Engine::Moveable> m_body;
    Controller* m_controller;
public:
	Unit();
	virtual ~Unit();

    Unit(float x, float y);
    Unit(Vec3 pos);
    
    const Vec3      getXYZ()                        { return m_body->getPosition(); }
    const Vec3      getVelocity()                   { return m_body->getVelocity(); }

    void            setXYZ(const Vec3& v)           { m_body->setPosition(v); }
    void            setVelocity(const Vec3& v)      { m_body->setVelocity(v); }

    void            setController(Controller* c)    { m_controller = c; }

    void            setTexture(std::string s);

    void            update( float dt );
    
};

#endif