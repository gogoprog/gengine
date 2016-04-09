#pragma once

#include <Urho3D/Engine/Application.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Input/Input.h>

namespace gengine
{
namespace application
{

class App : public Urho3D::Application
{
    URHO3D_OBJECT(App, Application);

public:
    App();

    virtual void Setup() override;
    virtual void Start() override;
    virtual void Stop() override;

    inline void run() { Run(); }
    int setup();
    void start();
    void runFrame();
    void stop();

    inline uint getWidth() const { return width; }
    inline uint getHeight() const { return height; }

    inline Urho3D::Context * getContext() { return context_; }
    inline Urho3D::UI & getUI() { return *GetSubsystem<Urho3D::UI>(); }
    inline Urho3D::FileSystem & getFileSystem() { return *GetSubsystem<Urho3D::FileSystem>(); }
    inline Urho3D::ResourceCache & getResourceCache() { return *GetSubsystem<Urho3D::ResourceCache>(); }
    inline Urho3D::Input & getInput() { return *GetSubsystem<Urho3D::Input>(); }

    inline float getTimeStep() { return engine_->GetNextTimeStep(); };

    Urho3D::Node & createNode();

    static App & getInstance() { return * instance; }

private:

    Urho3D::String
        name;
    bool
        fullscreen,
        mustQuit;
    uint
        width,
        height;
    Urho3D::SharedPtr<Urho3D::Scene>
        scene;
    static Urho3D::SharedPtr<App>
        instance;
};

inline App & get()
{
    return App::getInstance();
}

}
}
