#include "script.h"

#include <Urho3D/Math/Vector3.h>
#include <Urho3D/Math/Vector2.h>
#include <Urho3D/Math/Rect.h>
#include <Urho3D/Math/Color.h>

using namespace Urho3D;

EMBINDCEFV8_BINDINGS(math)
{
    embindcefv8::ValueObject<Vector3>("Vector3")
        .constructor<float, float, float>()
        .property("x", &Vector3::x_)
        .property("y", &Vector3::y_)
        .property("z", &Vector3::z_)
        ;

    embindcefv8::ValueObject<IntVector2>("IntVector2")
        .constructor<int, int>()
        .property("x", &IntVector2::x_)
        .property("y", &IntVector2::y_)
        ;

    embindcefv8::ValueObject<Vector2>("Vector2")
        .constructor<float, float>()
        .property("x", &Vector2::x_)
        .property("y", &Vector2::y_)
        ;

    embindcefv8::ValueObject<Rect>("Rect")
        .constructor<Vector2, Vector2>()
        .property("min", &Rect::min_)
        .property("max", &Rect::max_)
        ;

    embindcefv8::ValueObject<Color>("Color")
        .constructor<float, float, float, float>()
        .property("r", &Color::r_)
        .property("g", &Color::g_)
        .property("b", &Color::b_)
        .property("a", &Color::a_)
        ;
}
