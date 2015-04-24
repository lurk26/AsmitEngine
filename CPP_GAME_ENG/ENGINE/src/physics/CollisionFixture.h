#pragma once

/* Interface class for Fixtures */

namespace Engine
{
namespace Physics
{

class CollisionFixture
{
public:
 
    enum FixtureType
    {
        OBBFixture,
        SphericalFixture,
        CylinderFixture
    };
    
    CollisionFixture();
    virtual ~CollisionFixture();

    FixtureType getType() { return m_type; }

protected:
    FixtureType m_type;

};

}
}