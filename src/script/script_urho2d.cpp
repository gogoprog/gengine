#include "script.h"

#include <Urho3D/Scene/Component.h>
#include <Urho3D/Urho2D/StaticSprite2D.h>
#include <Urho3D/Urho2D/AnimatedSprite2D.h>
#include <Urho3D/Urho2D/Sprite2D.h>
#include <Urho3D/Urho2D/AnimationSet2D.h>
#include <Urho3D/Urho2D/Drawable2D.h>
#include <Urho3D/Urho2D/PhysicsWorld2D.h>
#include <Urho3D/Urho2D/RigidBody2D.h>
#include <Urho3D/Urho2D/CollisionBox2D.h>
#include <Urho3D/Urho2D/CollisionCircle2D.h>
#include <Urho3D/Urho2D/ParticleEffect2D.h>
#include <Urho3D/Urho2D/ParticleEmitter2D.h>
#include <Urho3D/Math/Color.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/Core/Context.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_STRING(String, CString);
EMBINDCEFV8_DECLARE_CLASS(Context);
EMBINDCEFV8_DECLARE_CLASS(Component);
EMBINDCEFV8_DECLARE_CLASS(RigidBody2D);
EMBINDCEFV8_DECLARE_ENUM(LoopMode2D);
EMBINDCEFV8_DECLARE_ENUM(BlendMode);
EMBINDCEFV8_DECLARE_ENUM(BodyType2D);
EMBINDCEFV8_DECLARE_ENUM(TextureAddressMode);
EMBINDCEFV8_DECLARE_ENUM(TextureCoordinate);

EMBINDCEFV8_BINDINGS(urho2d)
{
    embindcefv8::Class<Texture2D>("Texture2D")
        .method("setAddressMode", static_cast<void (Texture2D::*)(TextureCoordinate, TextureAddressMode)>(&Texture2D::SetAddressMode))
        ;

    embindcefv8::Class<Sprite2D>("Sprite2D")
        .method("getTexture", &Sprite2D::GetTexture)
        ;

    embindcefv8::Class<AnimationSet2D>("AnimationSet2D")
        ;

    embindcefv8::Class<StaticSprite2D, Component>("StaticSprite2D")
        .constructor<Context*>()
        .method("setSprite", &StaticSprite2D::SetSprite)
        .method("setEnabled", static_cast<void (StaticSprite2D::*)(bool)>(&StaticSprite2D::SetEnabled))
        .method("setDrawRect", &StaticSprite2D::SetDrawRect)
        .method("setTextureRect", &StaticSprite2D::SetTextureRect)
        .method("setColor", &StaticSprite2D::SetColor)
        .method("setAlpha", &StaticSprite2D::SetAlpha)
        .method("setHotSpot", &StaticSprite2D::SetHotSpot)
        .method("setUseHotSpot", &StaticSprite2D::SetUseHotSpot)
        .method("setBlendMode", &StaticSprite2D::SetBlendMode)
        .method("remove", static_cast<void (StaticSprite2D::*)()>(&StaticSprite2D::Remove))
        .method("setLayer", static_cast<void (StaticSprite2D::*)(int)>(&StaticSprite2D::SetLayer))
        .method("setOrderInLayer", static_cast<void (StaticSprite2D::*)(int)>(&StaticSprite2D::SetOrderInLayer))
        .method("getLayer", static_cast<int (StaticSprite2D::*)() const>(&StaticSprite2D::GetLayer))
        .method("getOrderInLayer", static_cast<int (StaticSprite2D::*)() const>(&StaticSprite2D::GetOrderInLayer))
        ;

    embindcefv8::Class<AnimatedSprite2D, Component>("AnimatedSprite2D")
        .constructor<Context*>()
        .method("setAnimation", &AnimatedSprite2D::SetAnimation)
        .method("setAnimationSet", &AnimatedSprite2D::SetAnimationSet)
        .method("remove", static_cast<void (AnimatedSprite2D::*)()>(&AnimatedSprite2D::Remove))
        .method("setLayer", static_cast<void (AnimatedSprite2D::*)(int)>(&AnimatedSprite2D::SetLayer))
        .method("setOrderInLayer", static_cast<void (AnimatedSprite2D::*)(int)>(&AnimatedSprite2D::SetOrderInLayer))
        .method("getLayer", static_cast<int (AnimatedSprite2D::*)() const>(&AnimatedSprite2D::GetLayer))
        .method("getOrderInLayer", static_cast<int (AnimatedSprite2D::*)() const>(&AnimatedSprite2D::GetOrderInLayer))
        .method("setEntity", &AnimatedSprite2D::SetEntity)
        .method("setLoopMode", &AnimatedSprite2D::SetLoopMode)
        .method("setSpeed", &AnimatedSprite2D::SetSpeed)
        .method("getBonePosition", &AnimatedSprite2D::GetBonePosition)
        .method("setColor", static_cast<void (AnimatedSprite2D::*)(const Color &)>(&AnimatedSprite2D::SetColor))
        .method("setAlpha", static_cast<void (AnimatedSprite2D::*)(float)>(&AnimatedSprite2D::SetAlpha))
        ;

    embindcefv8::Class<RigidBody2D, Component>("RigidBody2D")
        .constructor<Context*>()
        .method("setBodyType", &RigidBody2D::SetBodyType)
        .method("setMass", &RigidBody2D::SetMass)
        .method("setInertia", &RigidBody2D::SetInertia)
        .method("setMassCenter", &RigidBody2D::SetMassCenter)
        .method("setLinearDamping", &RigidBody2D::SetLinearDamping)
        .method("setAngularDamping", &RigidBody2D::SetAngularDamping)
        .method("setFixedRotation", &RigidBody2D::SetFixedRotation)
        .method("setBullet", &RigidBody2D::SetBullet)
        .method("setGravityScale", &RigidBody2D::SetGravityScale)
        .method("setAwake", &RigidBody2D::SetAwake)
        .method("setLinearVelocity", &RigidBody2D::SetLinearVelocity)
        .method("setAngularVelocity", &RigidBody2D::SetAngularVelocity)
        .method("applyForce", &RigidBody2D::ApplyForce)
        .method("applyForceToCenter", &RigidBody2D::ApplyForceToCenter)
        .method("applyTorque", &RigidBody2D::ApplyTorque)
        .method("applyLinearImpulse", &RigidBody2D::ApplyLinearImpulse)
        .method("applyAngularImpulse", &RigidBody2D::ApplyAngularImpulse)
        .method("getID", static_cast<unsigned (RigidBody2D::*)() const>(&RigidBody2D::GetID))
        ;

    embindcefv8::Class<PhysicsRaycastResult2D>("PhysicsRaycastResult2D")
        .constructor<>()
        .property("position", &PhysicsRaycastResult2D::position_)
        .property("normal", &PhysicsRaycastResult2D::normal_)
        .property("distance", &PhysicsRaycastResult2D::distance_)
        // .property("body", &PhysicsRaycastResult2D::body_) // :todo: support for emscripten
        ;

    embindcefv8::Class<PhysicsWorld2D, Component>("PhysicsWorld2D")
        .constructor<Context*>()
        .method("setGravity", &PhysicsWorld2D::SetGravity)
        .method("setContinuousPhysics", &PhysicsWorld2D::SetContinuousPhysics)
        .method("setSubStepping", &PhysicsWorld2D::SetSubStepping)
        .method("drawDebugGeometry", &PhysicsWorld2D::DrawDebugGeometry)
        .method("raycastSingle", &PhysicsWorld2D::RaycastSingle)
        .method("getRigidBody", static_cast<RigidBody2D* (PhysicsWorld2D::*)(const Vector2&, unsigned)>(&PhysicsWorld2D::GetRigidBody))
        ;

    embindcefv8::Class<CollisionBox2D, Component>("CollisionBox2D")
        .constructor<Context*>()
        .method("setSize", static_cast<void (CollisionBox2D::*)(const Vector2&)>(&CollisionBox2D::SetSize))
        .method("setCenter", static_cast<void (CollisionBox2D::*)(const Vector2&)>(&CollisionBox2D::SetCenter))
        .method("setAngle", static_cast<void (CollisionBox2D::*)(float)>(&CollisionBox2D::SetAngle))
        .method("setDensity", static_cast<void (CollisionBox2D::*)(float)>(&CollisionBox2D::SetDensity))
        .method("setFriction", static_cast<void (CollisionBox2D::*)(float)>(&CollisionBox2D::SetFriction))
        .method("setRestitution", static_cast<void (CollisionBox2D::*)(float)>(&CollisionBox2D::SetRestitution))
        ;

    embindcefv8::Class<CollisionCircle2D, Component>("CollisionCircle2D")
        .constructor<Context*>()
        .method("setRadius", &CollisionCircle2D::SetRadius)
        .method("setCenter", static_cast<void (CollisionCircle2D::*)(const Vector2&)>(&CollisionCircle2D::SetCenter))
        .method("setDensity", static_cast<void (CollisionCircle2D::*)(float)>(&CollisionCircle2D::SetDensity))
        .method("setFriction", static_cast<void (CollisionCircle2D::*)(float)>(&CollisionCircle2D::SetFriction))
        .method("setRestitution", static_cast<void (CollisionCircle2D::*)(float)>(&CollisionCircle2D::SetRestitution))
        ;

    embindcefv8::Class<ParticleEffect2D>("ParticleEffect2D")
        ;

    embindcefv8::Class<ParticleEmitter2D, Component>("ParticleEmitter2D")
        .constructor<Context*>()
        .method("setEffect", &ParticleEmitter2D::SetEffect)
        .method("setSprite", &ParticleEmitter2D::SetSprite)
        .method("setBlendMode", &ParticleEmitter2D::SetBlendMode)
        .method("setMaxParticles", &ParticleEmitter2D::SetMaxParticles)
        .method("setLayer", static_cast<void (ParticleEmitter2D::*)(int)>(&ParticleEmitter2D::SetLayer))
        .method("setOrderInLayer", static_cast<void (ParticleEmitter2D::*)(int)>(&ParticleEmitter2D::SetOrderInLayer))
        .method("getLayer", static_cast<int (ParticleEmitter2D::*)() const>(&ParticleEmitter2D::GetLayer))
        .method("getOrderInLayer", static_cast<int (ParticleEmitter2D::*)() const>(&ParticleEmitter2D::GetOrderInLayer))
        ;
}
