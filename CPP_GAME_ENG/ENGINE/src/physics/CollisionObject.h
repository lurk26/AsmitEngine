#pragma once
#include "utils\Vec3.hpp"
#include "utils\Matrix4.h"

/* The Collision Object class represents a bounding volume that is checked for collision.
 * This can be a sphere, an AABB, an ellipsoid etc. For now we just have an AABB.
 */

namespace Engine
{
namespace Physics
{
    class CollisionObject
    {
    private:
        // The AABB should ideally be moved to its own class
        struct AABB
        {
            Vec3 min;
            Vec3 max;
        };

        AABB    m_aabb;


    public:
        CollisionObject();
        ~CollisionObject();
    };

}
}