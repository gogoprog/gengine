#include "embindcefv8.h"

#include <Urho3D/Urho2D/StaticSprite2D.h>
#include <Urho3D/Urho2D/Sprite2D.h>

using namespace Urho3D;

EMBINDCEFV8_BINDINGS(urho2d)
{
    embindcefv8::Class<Sprite2D>("Sprite2D")
        ;

    embindcefv8::Class<StaticSprite2D>("StaticSprite2D")
        .method("setSprite", &StaticSprite2D::SetSprite)
        ;
}
