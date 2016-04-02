#pragma once

#include <Urho3D/Engine/Application.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/Resource/ResourceCache.h>

namespace gengine
{
namespace application
{

class App : public Urho3D::Application
{
    URHO3D_OBJECT(App, Application);

public:
    App(Urho3D::Context* context);

    virtual void Setup() override;
    virtual void Start() override;
    virtual void Stop() override;

    inline void run() { Run(); }

    inline uint getWidth() const { return width; }
    inline uint getHeight() const { return height; }

    inline Urho3D::Context * getContext() { return context_; }
    inline Urho3D::UI & getUI() { return *GetSubsystem<Urho3D::UI>(); }
    inline Urho3D::FileSystem & getFileSystem() { return *GetSubsystem<Urho3D::FileSystem>(); }
    inline Urho3D::ResourceCache & getResourceCache() { return *GetSubsystem<Urho3D::ResourceCache>(); }

    void update(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);

private:

    void loadScriptFile(const Urho3D::String & str);

    Urho3D::String
        name;
    bool
        fullscreen,
        mustQuit;
    uint
        width,
        height;
};

App & get();

}
}
