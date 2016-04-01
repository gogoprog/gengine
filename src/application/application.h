#pragma once

#include <Urho3D/Engine/Application.h>
#include <Urho3D/Scene/Scene.h>

namespace gengine
{
namespace application
{

class Application : public Urho3D::Application
{
    URHO3D_OBJECT(Application, Application);

public:
    Application(Urho3D::Context* context);

    virtual void Setup() override;
    virtual void Start() override;
    virtual void Stop() override;

    inline void run() { Run(); }

    void update(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);

private:
    Urho3D::String
        name;
    bool
        fullscreen,
        mustQuit;
    uint
        width = 640,
        height = 480;
};

}
}
