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
EMBINDCEFV8_DECLARE_CLASS(Camera, Component);
EMBINDCEFV8_DECLARE_CLASS(Light, Component);
EMBINDCEFV8_DECLARE_CLASS(Terrain, Component);
EMBINDCEFV8_DECLARE_CLASS(Skybox, Component);
EMBINDCEFV8_DECLARE_CLASS(Drawable, void);
EMBINDCEFV8_DECLARE_ENUM(LightType);

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

    embindcefv8::Class<Camera>("Camera")
        .constructor<Context*>()
        .method("setOrthoSize", static_cast<void (Camera::*)(const Vector2 &)>(&Camera::SetOrthoSize))
        .method("setOrthographic", &Camera::SetOrthographic)
        .method("setEnabled", static_cast<void (Camera::*)(bool)>(&Camera::SetEnabled))
        .method("setNearClip", &Camera::SetNearClip)
        .method("setFarClip", &Camera::SetFarClip)
        .method("setFov", &Camera::SetFov)
        .method("setAspectRatio", &Camera::SetAspectRatio)
        .method("setAutoAspectRatio", &Camera::SetAutoAspectRatio)
        .method("worldToScreenPoint", &Camera::WorldToScreenPoint)
        .method("screenToWorldPoint", &Camera::ScreenToWorldPoint)
        .method("setZoom", &Camera::SetZoom)
        .method("getZoom", &Camera::GetZoom)
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

    embindcefv8::Class<Light>("Light")
        .constructor<Context*>()
        .method("setLightType", &Light::SetLightType)
        .method("setColor", &Light::SetColor)
        .method("setCastShadows", static_cast<void (Light::*)(bool)>(&Light::SetCastShadows))
        .method("setShadowBias", &Light::SetShadowBias)
        .method("setShadowCascade", &Light::SetShadowCascade)
        .method("setSpecularIntensity", &Light::SetSpecularIntensity)
        ;

    embindcefv8::Class<Terrain>("Terrain")
        .constructor<Context*>()
        .method("setPatchSize", &Terrain::SetPatchSize)
        .method("setSpacing", &Terrain::SetSpacing)
        .method("setSmoothing", &Terrain::SetSmoothing)
        .method("setHeightMap", &Terrain::SetHeightMap)
        .method("setMaterial", &Terrain::SetMaterial)
        .method("setOccluder", &Terrain::SetOccluder)
        .method("setCastShadows", &Terrain::SetCastShadows)
        .method("getHeight", &Terrain::GetHeight)
        ;

    embindcefv8::Class<Skybox>("Skybox")
        .constructor<Context*>()
        .method("setModel", static_cast<void (Skybox::*)(Model *)>(&Skybox::SetModel))
        .method("setMaterial", static_cast<void (Skybox::*)(Material *)>(&Skybox::SetMaterial))
        ;
}
