#include "embindcefv8.h"

#include <Urho3D/Math/Vector3.h>

using namespace Urho3D;

EMBINDCEFV8_BINDINGS(math)
{
    embindcefv8::ValueObject<Vector3>("Vector3")
        .constructor<float, float, float>()
        .property("x", &Vector3::x_)
        .property("y", &Vector3::y_)
        .property("z", &Vector3::z_)
        ;
}
