#include "bindings.h"

#include <Urho3D/Core/Context.h>
#include <Urho3D/Physics/PhysicsWorld.h>

using namespace Urho3D;

EMBINDCEFV8_BINDINGS(physics)
{
    embindcefv8::Class<PhysicsRaycastResult>("PhysicsRaycastResult")
        .constructor<>()
        .property("position", &PhysicsRaycastResult::position_)
        .property("normal", &PhysicsRaycastResult::normal_)
        .property("distance", &PhysicsRaycastResult::distance_)
        .property("hitFraction", &PhysicsRaycastResult::hitFraction_)
        // .property("body", &PhysicsRaycastResult::body_) // :todo: support for emscripten
        ;
}
