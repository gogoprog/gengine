#include "script.h"

#include <Urho3D/Physics/PhysicsWorld.h>
#include <Urho3D/Physics/CollisionShape.h>
#include <Urho3D/Physics/RigidBody.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_CLASS(Context);
EMBINDCEFV8_DECLARE_CLASS(Component);
EMBINDCEFV8_DECLARE_STRING(String, CString);
EMBINDCEFV8_DECLARE_ENUM(CollisionEventMode);

EMBINDCEFV8_BINDINGS(physics)
{
    embindcefv8::Class<RigidBody, Component>("RigidBody")
        .constructor<Context*>()
        .method("setMass", &RigidBody::SetMass)
        .method("setFriction", &RigidBody::SetFriction)
        .method("setCollisionEventMode", &RigidBody::SetCollisionEventMode)
        ;

    embindcefv8::Class<CollisionShape, Component>("CollisionShape")
        .constructor<Context*>()
        .method("setBox", &CollisionShape::SetBox)
        .method("setSphere", &CollisionShape::SetSphere)
        .method("setStaticPlane", &CollisionShape::SetStaticPlane)
        .method("setCylinder", &CollisionShape::SetCylinder)
        .method("setCapsule", &CollisionShape::SetCapsule)
        .method("setCone", &CollisionShape::SetCone)
        .method("setTriangleMesh", &CollisionShape::SetTriangleMesh)
        .method("setConvexHull", &CollisionShape::SetConvexHull)
        .method("setTerrain", &CollisionShape::SetTerrain)
        ;

    embindcefv8::Class<PhysicsWorld, Component>("PhysicsWorld")
        .constructor<Context*>()
        .method("setGravity", &PhysicsWorld::SetGravity)
        ;
}
