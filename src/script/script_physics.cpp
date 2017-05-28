#include "script.h"

#include <Urho3D/Core/Context.h>
#include <Urho3D/Physics/PhysicsWorld.h>
#include <Urho3D/Physics/CollisionShape.h>
#include <Urho3D/Physics/RigidBody.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_CLASS(Context, void);
EMBINDCEFV8_DECLARE_CLASS(Component, void);
EMBINDCEFV8_DECLARE_STRING(String, CString);
EMBINDCEFV8_DECLARE_ENUM(CollisionEventMode);
EMBINDCEFV8_DECLARE_CLASS(RigidBody, Component);
EMBINDCEFV8_DECLARE_CLASS(CollisionShape, Component);
EMBINDCEFV8_DECLARE_CLASS(PhysicsWorld, Component);

EMBINDCEFV8_BINDINGS(physics)
{
    embindcefv8::Class<RigidBody>("RigidBody")
        .constructor<Context*>()
        .method("setMass", &RigidBody::SetMass)
        .method("setFriction", &RigidBody::SetFriction)
        .method("setCollisionEventMode", &RigidBody::SetCollisionEventMode)
        ;

    embindcefv8::Class<CollisionShape>("CollisionShape")
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

    embindcefv8::Class<PhysicsWorld>("PhysicsWorld")
        .constructor<Context*>()
        .method("setGravity", &PhysicsWorld::SetGravity)
        ;
}
