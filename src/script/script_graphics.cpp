#include "script.h"

#include <Urho3D/Core/Context.h>
#include <Urho3D/Resource/Image.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Viewport.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Graphics/Light.h>
#include <Urho3D/Graphics/AnimatedModel.h>
#include <Urho3D/Graphics/Animation.h>
#include <Urho3D/Graphics/AnimationState.h>
#include <Urho3D/Graphics/Zone.h>
#include <Urho3D/Graphics/Terrain.h>
#include <Urho3D/Graphics/Skybox.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_CLASS(Component, void);
EMBINDCEFV8_DECLARE_CLASS(Context, void);
EMBINDCEFV8_DECLARE_CLASS(Renderer, void);
EMBINDCEFV8_DECLARE_CLASS(Scene, void);
EMBINDCEFV8_DECLARE_CLASS(Image, void);

EMBINDCEFV8_BINDINGS(graphics)
{
    embindcefv8::Class<Material>("Material")
        ;

    embindcefv8::Class<Model>("Model")
        ;

    embindcefv8::Class<Animation>("Animation")
        ;

    embindcefv8::Class<AnimationState>("AnimationState")
        .method("setWeight", &AnimationState::SetWeight)
        .method("setLooped", &AnimationState::SetLooped)
        .method("setTime", &AnimationState::SetTime)
        .method("addTime", &AnimationState::AddTime)
        ;

    embindcefv8::Class<Viewport>("Viewport")
        .constructor<Context*>()
        .method("setScene", &Viewport::SetScene)
        .method("setCamera", &Viewport::SetCamera)
        ;

    embindcefv8::Class<Zone>("Zone")
        .method("setAmbientColor", &Zone::SetAmbientColor)
        .method("setFogColor", &Zone::SetFogColor)
        ;

    embindcefv8::Class<Renderer>("Renderer")
        .method("getDefaultZone", &Renderer::GetDefaultZone)
        .method("setViewport", &Renderer::SetViewport)
        ;

    embindcefv8::Class<BiasParameters>("BiasParameters")
        .constructor<float, float, float>()
        .property("constantBias", &BiasParameters::constantBias_)
        .property("slopeScaledBias", &BiasParameters::slopeScaledBias_)
        .property("normalOffset", &BiasParameters::normalOffset_)
        ;

    embindcefv8::Class<CascadeParameters>("CascadeParameters")
        .constructor<float, float, float, float, float, float>()
        ;
}
