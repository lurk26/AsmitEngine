#include "OBBCollisionObject.h"
namespace Engine
{
namespace Physics
{

    OBBCollisionObject::OBBCollisionObject(Engine::SharedPtr<Moveable> object_ptr, 
        Vec3 center, Vec3 extents) :
        m_object_ptr(object_ptr),
        m_aabb(center,extents)
    {
        
    }


    OBBCollisionObject::~OBBCollisionObject()
    {
    }

    bool OBBCollisionObject::checkOBBIntersection(const OBBCollisionObject& box_A, const Vec3& vel_A, const OBBCollisionObject& box_B, const Vec3& vel_B)
    {
        const Transform A_trans = box_A.getTrans();
        const Transform B_trans = box_B.getTrans();

        Matrix4 A_inverseTrans;
        A_trans.getInverse(A_inverseTrans);
        Matrix4 BtoA = B_trans*A_inverseTrans;
        
        Vec3 B_center, A_center;
        B_trans.transformVect(B_center, box_B.m_aabb.center);
        A_trans.transformVect(A_center, box_A.m_aabb.center);
        Vec3 D = B_center - A_center;

        A_inverseTrans.rotateVect(D);

        Vec3 Bcenter_inA;
        BtoA.transformVect(Bcenter_inA, box_B.m_aabb.center);

        // Make extent vectors of B and rotate into A's space
        Vec3 B_ex(box_B.m_aabb.extents.X(), 0, 0);
        Vec3 B_ey(0, box_B.m_aabb.extents.Y(), 0);
        Vec3 B_ez(0, 0, box_B.m_aabb.extents.Z());

        BtoA.rotateVect(B_ex);
        BtoA.rotateVect(B_ey);
        BtoA.rotateVect(B_ez);

        float s;

        // A's x axis
        s = fabsf(D.X()) - (box_A.m_aabb.extents.X() + fabsf(B_ex.X()) + fabsf(B_ey.X()) + fabsf(B_ez.X()));
        if (s > 0.0f) return false;
        
        // A's y axis
        s = fabsf(D.Y()) - (box_A.m_aabb.extents.Y() + fabsf(B_ex.Y()) + fabsf(B_ey.Y()) + fabsf(B_ez.Y()));
        if (s > 0.0f) return false;

        // A's z axis
        s = fabsf(D.Z()) - (box_A.m_aabb.extents.Z() + fabsf(B_ex.Z()) + fabsf(B_ey.Z()) + fabsf(B_ez.Z()));
        if (s > 0.0f) return false;


        Matrix4 B_inverseTrans;
        B_trans.getInverse(B_inverseTrans);
        Matrix4 AtoB = A_trans*B_inverseTrans;
        
        AtoB.rotateVect(D);

        // Make extent vectors of A and rotate into B's space
        Vec3 A_ex(box_A.m_aabb.extents.X(), 0, 0);
        Vec3 A_ey(0, box_A.m_aabb.extents.Y(), 0);
        Vec3 A_ez(0, 0, box_A.m_aabb.extents.Z());

        AtoB.rotateVect(A_ex);
        AtoB.rotateVect(A_ey);
        AtoB.rotateVect(A_ez);

        // B's x axis
        s = fabsf(D.X()) - (box_B.m_aabb.extents.X() + fabsf(A_ex.X()) + fabsf(A_ey.X()) + fabsf(A_ez.X()));
        if (s > 0.0f) return false;

        // B's y axis
        s = fabsf(D.Y()) - (box_B.m_aabb.extents.Y() + fabsf(A_ex.Y()) + fabsf(A_ey.Y()) + fabsf(A_ez.Y()));
        if (s > 0.0f) return false;

        // B's z axis
        s = fabsf(D.Z()) - (box_B.m_aabb.extents.Z() + fabsf(A_ex.Z()) + fabsf(A_ey.Z()) + fabsf(A_ez.Z()));
        if (s > 0.0f) return false;

        return true;
    }
}
}