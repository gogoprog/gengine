#pragma once

#include "embindcefv8.h"

namespace Urho3D
{
    struct Vector2;
    struct Vector3;
    struct IntVector2;
    struct Rect;
    struct Color;
}

EMBINDCEFV8_DECLARE_VALUE_OBJECT(Urho3D::Vector2);
EMBINDCEFV8_DECLARE_VALUE_OBJECT(Urho3D::Vector3);
EMBINDCEFV8_DECLARE_VALUE_OBJECT(Urho3D::IntVector2);
EMBINDCEFV8_DECLARE_VALUE_OBJECT(Urho3D::Rect);
EMBINDCEFV8_DECLARE_VALUE_OBJECT(Urho3D::Color);
