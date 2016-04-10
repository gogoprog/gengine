#include "embindcefv8.h"

#include <Urho3D/Graphics/Camera.h>

using namespace Urho3D;

EMBINDCEFV8_BINDINGS(graphics)
{
    embindcefv8::Class<Camera>("Camera")
        .method("setOrthoSize", static_cast<void (Camera::*)(float)>(&Camera::SetOrthoSize))
        .method("setOrthographic", &Camera::SetOrthographic)
        .method("setEnabled", static_cast<void (Camera::*)(bool)>(&Camera::SetEnabled))
        ;
}
