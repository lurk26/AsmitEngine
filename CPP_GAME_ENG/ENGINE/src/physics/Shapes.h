#pragma once
#include "utils/Vec3.hpp"

namespace Engine
{
namespace Physics
{

    struct AABB
    {
        Vec3 center;
        Vec3 extents;
        AABB(Vec3 c, Vec3 e) : center(c), extents(e){};
    };

}
}