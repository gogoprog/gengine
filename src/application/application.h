#pragma once

#include <Urho3D/Engine/Application.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Audio/Audio.h>

namespace gengine
{
namespace gui { class System; }
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
    void exit();

    inline Urho3D::Context& getContext() { return *context_; }
    inline Urho3D::Engine * getEngine() { return engine_; }
    inline Urho3D::UI & getUI() { return *GetSubsystem<Urho3D::UI>(); }
    inline Urho3D::FileSystem & getFileSystem() { return *GetSubsystem<Urho3D::FileSystem>(); }
    inline Urho3D::ResourceCache & getResourceCache() { return *GetSubsystem<Urho3D::ResourceCache>(); }
    inline Urho3D::Input & getInput() { return *GetSubsystem<Urho3D::Input>(); }
    inline Urho3D::Graphics & getGraphics() { return *GetSubsystem<Urho3D::Graphics>(); }
    inline Urho3D::Renderer & getRenderer() { return *GetSubsystem<Urho3D::Renderer>(); }
    inline Urho3D::Audio & getAudio() { return *GetSubsystem<Urho3D::Audio>(); }

    inline float getTimeStep() { return engine_->GetNextTimeStep(); };
    inline bool isRunning() { return engine_ && !engine_->IsExiting(); }

    Urho3D::Scene & getScene() { return *scene; }
    Urho3D::Node & createNode();

    gui::System & getGui();

    const Urho3D::IntVector2 & getWindowSize() const { return windowSize; }
    void setWindowSize(const Urho3D::IntVector2 & size) { windowSize = size; }
    void setWindowTitle(const Urho3D::String & title) { windowTitle = title; }
    const Urho3D::String & getGuiFilename() { return guiFilename; }
    void setGuiFilename(const Urho3D::String & filename) { guiFilename = filename; }

    void update(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);
    void onPhysicsBeginContact2D(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);

    static App & getInstance() { return * instance; }

private:

    Urho3D::String
        windowTitle,
        guiFilename;
    bool
        fullscreen;
    Urho3D::IntVector2
        windowSize;
    Urho3D::SharedPtr<Urho3D::Scene>
        scene;
    static Urho3D::SharedPtr<App>
        instance;
};

inline App & get()
{
    return App::getInstance();
}

void loadScriptFile(const char *filename, const char *additional_code = "");

#if CEF
    void preInit();
    void init();
#endif

}
}
