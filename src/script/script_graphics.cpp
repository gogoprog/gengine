#include "embindcefv8.h"

#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Viewport.h>
#include <Urho3D/Graphics/Renderer.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_CLASS(Context);

EMBINDCEFV8_BINDINGS(graphics)
{
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
        ;

    embindcefv8::Class<Renderer>("Renderer")
        .method("setViewport", &Renderer::SetViewport)
        ;
}
