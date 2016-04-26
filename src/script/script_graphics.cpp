#include "embindcefv8.h"

#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Viewport.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Graphics/Light.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_CLASS(Context);
EMBINDCEFV8_DECLARE_ENUM(LightType);

EMBINDCEFV8_BINDINGS(graphics)
{
    embindcefv8::Class<Material>("Material")
        ;

    embindcefv8::Class<Model>("Model")
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
        ;

    embindcefv8::Class<Renderer>("Renderer")
        .method("setViewport", &Renderer::SetViewport)
        ;

    embindcefv8::Class<StaticModel>("StaticModel")
        .constructor<Context*>()
        .method("setModel", &StaticModel::SetModel)
        .method("setMaterial", &StaticModel::SetMaterial)
        ;

    embindcefv8::Class<Light>("Light")
        .constructor<Context*>()
        .method("setLightType", &Light::SetLightType)
        ;
}
