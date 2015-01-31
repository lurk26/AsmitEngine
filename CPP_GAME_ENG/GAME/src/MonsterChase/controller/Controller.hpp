#ifndef HEADER_CONTROLLER_HPP
#define HEADER_CONTROLLER_HPP

#include <cstring>

class Unit;

class Controller
{
protected:
    Unit *m_unit;
    const char* m_name;
public:
    Controller(Unit* unit, const char* name) : m_unit(unit), m_name(_strdup(name)) {};
    virtual ~Controller();

    virtual void  update(float dt) = 0;
};

#endif