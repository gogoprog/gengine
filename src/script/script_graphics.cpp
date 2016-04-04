#include "embindcefv8.h"

#include <Urho3D/Graphics/Camera.h>

using namespace Urho3D;

EMBINDCEFV8_BINDINGS(graphics)
{
    embindcefv8::Class<Camera>("Camera")
        ;
}
