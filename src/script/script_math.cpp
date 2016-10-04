#include "script.h"

#include <Urho3D/Math/Vector3.h>
#include <Urho3D/Math/Vector2.h>
#include <Urho3D/Math/Rect.h>
#include <Urho3D/Math/Color.h>

using namespace Urho3D;

class Maths
{
public:
    template<typename V>
    static float getVectorLength(const V & v)
    {
        return v.Length();
    }

    template<typename V>
    static float getVectorLengthSquared(const V & v)
    {
        return v.LengthSquared();
    }

    template<typename V>
    static V getNormalizedVector(const V & v)
    {
        auto result = v;
        result.Normalize();
        return result;
    }

    template<typename V>
    static float getVectorAngle(const V & v1, const V & v2)
    {
        return v1.Angle(v2);
    }

    template<typename V>
    static float getVectorDistance(const V & v1, const V & v2)
    {
        return (v1 - v2).Length();
    }

    template<typename V>
    static float getVectorDistanceSquared(const V & v1, const V & v2)
    {
        return (v1 - v2).LengthSquared();
    }
};

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

    embindcefv8::Class<Maths>("Maths")
        .static_function("getVector2Length", &Maths::getVectorLength<Vector2>)
        .static_function("getVector3Length", &Maths::getVectorLength<Vector3>)
        .static_function("getVector2LengthSquared", &Maths::getVectorLengthSquared<Vector2>)
        .static_function("getVector3LengthSquared", &Maths::getVectorLengthSquared<Vector3>)
        .static_function("getNormalizedVector2", &Maths::getNormalizedVector<Vector2>)
        .static_function("getNormalizedVector3", &Maths::getNormalizedVector<Vector3>)
        .static_function("getVector2Angle", &Maths::getVectorAngle<Vector2>)
        .static_function("getVector3Angle", &Maths::getVectorAngle<Vector3>)
        .static_function("getVector2Distance", &Maths::getVectorDistance<Vector2>)
        .static_function("getVector3Distance", &Maths::getVectorDistance<Vector3>)
        .static_function("getVector2DistanceSquared", &Maths::getVectorDistanceSquared<Vector2>)
        .static_function("getVector3DistanceSquared", &Maths::getVectorDistanceSquared<Vector3>)
        ;
}
