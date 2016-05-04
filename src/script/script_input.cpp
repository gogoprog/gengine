#include "embindcefv8.h"

#include <Urho3D/Input/Input.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_CLASS(Input)

EMBINDCEFV8_BINDINGS(input)
{
    embindcefv8::Class<Input>("Input")
        .method("getKeyPress", &Input::GetKeyPress)
        .method("getKeyDown", &Input::GetKeyDown)
        .method("getScancodePress", &Input::GetScancodePress)
        .method("getScancodeDown", &Input::GetScancodeDown)
        .method("getMouseButtonPress", &Input::GetMouseButtonPress)
        .method("getMouseButtonDown", &Input::GetMouseButtonDown)
        .method("getMousePosition", &Input::GetMousePosition)
        .method("getMouseMove", &Input::GetMouseMove)
        .method("getMouseMoveWheel", &Input::GetMouseMoveWheel)
        ;
}
