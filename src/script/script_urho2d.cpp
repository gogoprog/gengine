#include "embindcefv8.h"

#include <Urho3D/Urho2D/StaticSprite2D.h>
#include <Urho3D/Urho2D/Sprite2D.h>
#include <Urho3D/Core/Context.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_CLASS(Context);
extern template struct emscripten::internal::TypeID<Context>;

EMBINDCEFV8_BINDINGS(urho2d)
{
    embindcefv8::Class<Sprite2D>("Sprite2D")
        ;

    embindcefv8::Class<StaticSprite2D>("StaticSprite2D")
        .constructor<Context*>()
        .method("setSprite", &StaticSprite2D::SetSprite)
        .method("setEnabled", static_cast<void (StaticSprite2D::*)(bool)>(&StaticSprite2D::SetEnabled))
        .method("setDrawRect", &StaticSprite2D::SetDrawRect)
        .method("setTextureRect", &StaticSprite2D::SetTextureRect)
        .method("setColor", &StaticSprite2D::SetColor)
        ;
}
