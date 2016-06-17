#include "script.h"

#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Urho2D/Sprite2D.h>
#include <Urho3D/Urho2D/AnimationSet2D.h>
#include <Urho3D/Graphics/Model.h>
#include <Urho3D/Graphics/Material.h>
#include <Urho3D/Graphics/Animation.h>
#include <Urho3D/Audio/Sound.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_STRING(String, CString);
EMBINDCEFV8_DECLARE_CLASS(ResourceCache);

EMBINDCEFV8_BINDINGS(resource)
{
    embindcefv8::Class<ResourceCache>("ResourceCache")
        .method("getSprite2D", &ResourceCache::GetResource<Sprite2D>)
        .method("getAnimationSet2D", &ResourceCache::GetResource<AnimationSet2D>)
        .method("getModel", &ResourceCache::GetResource<Model>)
        .method("getMaterial", &ResourceCache::GetResource<Material>)
        .method("getAnimation", &ResourceCache::GetResource<Animation>)
        .method("getSound", &ResourceCache::GetResource<Sound>)
        ;
}
