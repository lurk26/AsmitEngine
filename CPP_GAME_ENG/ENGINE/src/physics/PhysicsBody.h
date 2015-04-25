#pragma once

#include "CollisionFixture.h"
#include "objects\GameObject.hpp"
#include "physics\Shapes.h"
#include "utils\SharedPtr\SharedPtr.h"

namespace Engine
{
namespace Physics
{

 
class PhysicsBody
{
private:
    Engine::SharedPtr<Engine::GameObject> m_object_ptr;
public:
    PhysicsBody();
    ~PhysicsBody();
};

}
}