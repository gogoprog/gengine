#include "bindings.h"

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
#include <Urho3D/Urho2D/TmxFile2D.h>
#include <Urho3D/Urho2D/TileMap2D.h>
#include <Urho3D/Math/Color.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/Core/Context.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_STRING(String, CString);
EMBINDCEFV8_DECLARE_CLASS(Context, void);
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

    embindcefv8::Class<PhysicsRaycastResult2D>("PhysicsRaycastResult2D")
        .constructor<>()
        .property("position", &PhysicsRaycastResult2D::position_)
        .property("normal", &PhysicsRaycastResult2D::normal_)
        .property("distance", &PhysicsRaycastResult2D::distance_)
        // .property("body", &PhysicsRaycastResult2D::body_) // :todo: support for emscripten
        ;

    embindcefv8::Class<ParticleEffect2D>("ParticleEffect2D")
        ;

    embindcefv8::Class<TmxFile2D>("TmxFile2D")
        ;
}
