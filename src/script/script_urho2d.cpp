#include "embindcefv8.h"

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
#include <Urho3D/Core/Context.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_STRING(String, CString);
EMBINDCEFV8_DECLARE_CLASS(Context);
EMBINDCEFV8_DECLARE_CLASS(Component);
EMBINDCEFV8_DECLARE_ENUM(LoopMode2D);
EMBINDCEFV8_DECLARE_ENUM(BlendMode);
EMBINDCEFV8_DECLARE_ENUM(BodyType2D);

EMBINDCEFV8_BINDINGS(urho2d)
{
    embindcefv8::Class<Sprite2D>("Sprite2D")
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
        ;

    embindcefv8::Class<PhysicsWorld2D, Component>("PhysicsWorld2D")
        .constructor<Context*>()
        .method("setGravity", &PhysicsWorld2D::SetGravity)
        ;

    embindcefv8::Class<RigidBody2D, Component>("RigidBody2D")
        .constructor<Context*>()
        .method("setBodyType", &RigidBody2D::SetBodyType)
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
}
