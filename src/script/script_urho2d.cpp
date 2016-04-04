#include "embindcefv8.h"

#include <Urho3D/Urho2D/StaticSprite2D.h>

using namespace Urho3D;

EMBINDCEFV8_BINDINGS(urho2d)
{
    embindcefv8::Class<StaticSprite2D>("StaticSprite2D")
        ;
}
