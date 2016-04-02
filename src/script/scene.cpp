#include "embindcefv8.h"

#include <Urho3D/Scene/Node.h>

using namespace Urho3D;

EMBINDCEFV8_BINDINGS(scene)
{
    embindcefv8::Class<Node>("Node");
}
