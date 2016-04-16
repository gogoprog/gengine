#include "embindcefv8.h"

#include <Urho3D/Scene/Component.h>
#include <Urho3D/Urho2D/StaticSprite2D.h>
#include <Urho3D/Urho2D/AnimatedSprite2D.h>
#include <Urho3D/Urho2D/Sprite2D.h>
#include <Urho3D/Urho2D/AnimationSet2D.h>
#include <Urho3D/Core/Context.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_STRING(String, CString);
EMBINDCEFV8_DECLARE_CLASS(Context);
EMBINDCEFV8_DECLARE_CLASS(Component);
EMBINDCEFV8_DECLARE_ENUM(LoopMode2D);

#ifdef EMSCRIPTEN
    extern template struct emscripten::internal::TypeID<Context>;
#endif

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
        ;

    embindcefv8::Class<AnimatedSprite2D, Component>("AnimatedSprite2D")
        .constructor<Context*>()
        .method("setAnimation", &AnimatedSprite2D::SetAnimation)
        .method("setAnimationSet", &AnimatedSprite2D::SetAnimationSet)
        ;
}
