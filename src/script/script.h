#pragma once

#include "embindcefv8.h"

namespace Urho3D
{
    class Vector2;
    class Vector3;
    class IntVector2;
    class Rect;
    class Color;
}

EMBINDCEFV8_DECLARE_VALUE_OBJECT(Urho3D::Vector2);
EMBINDCEFV8_DECLARE_VALUE_OBJECT(Urho3D::Vector3);
EMBINDCEFV8_DECLARE_VALUE_OBJECT(Urho3D::IntVector2);
EMBINDCEFV8_DECLARE_VALUE_OBJECT(Urho3D::Rect);
EMBINDCEFV8_DECLARE_VALUE_OBJECT(Urho3D::Color);
