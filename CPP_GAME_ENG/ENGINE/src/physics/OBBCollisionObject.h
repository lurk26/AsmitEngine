#pragma once
#include "utils\Vec3.hpp"
#include "utils\Matrix4.h"
#include "utils\SharedPtr\SharedPtr.h"

#include "objects\Moveable.hpp"

/* The Collision Object class represents a bounding volume that is checked for collision.
 * This can be a sphere, an AABB, an ellipsoid etc. For now we just have an AABB.
 */

namespace Engine
{
namespace Physics
{
    class OBBCollisionObject
    {
    private:
        // The AABB should ideally be moved to its own class
        struct AABB
        {
            Vec3 center;
            Vec3 extents;
            AABB(Vec3 c, Vec3 e) : center(c), extents(e){};
        };
        AABB    m_aabb;
        
        Engine::SharedPtr<Engine::Moveable> m_object_ptr;

    public:
        OBBCollisionObject(Engine::SharedPtr<Moveable> object_ptr, Vec3 center, Vec3 extents);
        ~OBBCollisionObject();

        const Transform& getTrans() const { return m_object_ptr->getTrans(); }

        static bool checkOBBIntersection(const OBBCollisionObject& box_A, const Vec3& vel_A, const OBBCollisionObject& box_B, const Vec3& vel_B);
    };

}
}