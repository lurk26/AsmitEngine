#pragma once

class Unit;

class Controller
{
protected:
    Unit *m_unit;

public:
    Controller(Unit* unit) : m_unit(unit) {};
    virtual ~Controller();

    virtual void  update() = 0;
};

