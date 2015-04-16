#include "Controller.hpp"

#include <cstdlib>

Controller::~Controller()
{
    free((void*)m_name);
}
