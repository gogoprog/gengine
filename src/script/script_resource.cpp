#include "embindcefv8.h"

#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Urho2D/Sprite2D.h>

using namespace Urho3D;

DECLARE_STRING(String, CString)

EMBINDCEFV8_BINDINGS(resource)
{
    embindcefv8::Class<ResourceCache>("ResourceCache")
        .method("getSprite2D", &ResourceCache::GetResource<Sprite2D>)
        ;
}
