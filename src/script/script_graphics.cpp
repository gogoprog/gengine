#include "embindcefv8.h"

#include <Urho3D/Core/Context.h>
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

using namespace Urho3D;

EMBINDCEFV8_DECLARE_CLASS(Context);
EMBINDCEFV8_DECLARE_CLASS(Renderer);
EMBINDCEFV8_DECLARE_CLASS(Scene);
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

    embindcefv8::Class<Camera, Component>("Camera")
        .constructor<Context*>()
        .method("setOrthoSize", static_cast<void (Camera::*)(const Vector2 &)>(&Camera::SetOrthoSize))
        .method("setOrthographic", &Camera::SetOrthographic)
        .method("setEnabled", static_cast<void (Camera::*)(bool)>(&Camera::SetEnabled))
        .method("setNearClip", &Camera::SetNearClip)
        .method("setFarClip", &Camera::SetFarClip)
        .method("setFov", &Camera::SetFov)
        .method("setAspectRatio", &Camera::SetAspectRatio)
        .method("setAutoAspectRatio", &Camera::SetAutoAspectRatio)
        ;

    embindcefv8::Class<Zone>("Zone")
        .method("setFogColor", &Zone::SetFogColor)
        ;

    embindcefv8::Class<Renderer>("Renderer")
        .method("getDefaultZone", &Renderer::GetDefaultZone)
        .method("setViewport", &Renderer::SetViewport)
        ;

    embindcefv8::Class<StaticModel, Component>("StaticModel")
        .constructor<Context*>()
        .method("setModel", &StaticModel::SetModel)
        .method("setMaterial", &StaticModel::SetMaterial)
        .method("setCastShadows", static_cast<void (StaticModel::*)(bool)>(&StaticModel::SetCastShadows))
        ;

    embindcefv8::Class<AnimatedModel, Component>("AnimatedModel")
        .constructor<Context*>()
        .method("setModel", static_cast<void (AnimatedModel::*)(Model *, bool)>(&AnimatedModel::SetModel))
        .method("setMaterial", static_cast<void (AnimatedModel::*)(Material *)>(&AnimatedModel::SetMaterial))
        .method("setCastShadows", static_cast<void (AnimatedModel::*)(bool)>(&AnimatedModel::SetCastShadows))
        .method("getAnimationState", static_cast<AnimationState* (AnimatedModel::*)(Animation *) const>(&AnimatedModel::GetAnimationState))
        .method("getAnimationStateByIndex", static_cast<AnimationState* (AnimatedModel::*)(unsigned) const>(&AnimatedModel::GetAnimationState))
        .method("addAnimationState", &AnimatedModel::AddAnimationState)
        ;

    embindcefv8::Class<Light, Component>("Light")
        .constructor<Context*>()
        .method("setLightType", &Light::SetLightType)
        .method("setColor", &Light::SetColor)
        .method("setCastShadows", static_cast<void (Light::*)(bool)>(&Light::SetCastShadows))
        ;
}
