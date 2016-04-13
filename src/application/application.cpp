#include "application.h"

#include "gui_system.h"
#include "embindcefv8.h"
#include <fstream>

#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Core/Timer.h>
#include <Urho3D/Core/Thread.h>
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>

#define STRING(src) \
    #src

using namespace Urho3D;

namespace gengine
{
namespace application
{

App::App()
    :
    Application(new Context()),
    windowTitle("gengine application"),
    fullscreen(false),
    mustQuit(false),
    windowSize(640, 480)
{
    instance = this;
    puts("App constructor");
}

void App::Setup()
{
    puts("App::Setup");

    engineParameters_["LogName"] = "gengine.log";
    engineParameters_["LogLevel"] = "Debug";
    engineParameters_["FullScreen"] = fullscreen;
    engineParameters_["Headless"] = false;
    engineParameters_["Sound"] = false;
    engineParameters_["WindowWidth"] = windowSize.x_;
    engineParameters_["WindowHeight"] = windowSize.y_;
    engineParameters_["WindowTitle"] = windowTitle;
    engineParameters_["ResourcePaths"] = "data;coreData;";
    engineParameters_["ResourcePrefixPaths"] = (String(getFileSystem().GetCurrentDir().CString()) + ";" + String(getenv("GENGINE")) + "/res/");
}

void App::Start()
{
    puts("App::Start");

    getInput().SetMouseVisible(true);

    SharedPtr<Scene> scene_(new Scene(context_));
    scene = scene_;
    scene_->CreateComponent<Octree>();

    auto cameraNode_ = scene_->CreateChild("Camera");
    auto camera = cameraNode_->CreateComponent<Camera>();
    camera->SetOrthographic(true);
    camera->SetOrthoSize(Vector2(windowSize.x_, windowSize.y_));

    auto renderer = GetSubsystem<Renderer>();
    auto viewport = new Viewport(context_, scene_, cameraNode_->GetComponent<Camera>());
    renderer->SetViewport(0, viewport);
}

void App::Stop()
{
}

int App::setup()
{
    Setup();

    if (exitCode_)
       return exitCode_;

    if (!engine_->Initialize(engineParameters_))
    {
       ErrorExit();
       return exitCode_;
    }

    return 0;
}

void App::start()
{
    Start();
}

void App::runFrame()
{
    Thread::SetMainThread();
    engine_->RunFrame();
}

void App::stop()
{
    Stop();
}

Node & App::createNode()
{
    return * scene->CreateChild();
}

SharedPtr<App>
    App::instance;

}
}

void loadScriptFile(const char *filename)
{
    std::ifstream in(filename);
    std::string contents((std::istreambuf_iterator<char>(in)),
    std::istreambuf_iterator<char>());

    const char application_js[] =
        #include "application.js"

    contents += application_js;

    embindcefv8::executeJavaScript(contents.c_str());
}

int main(int argc, char *argv[])
{
    gengine::gui::System::getInstance().preinit(argc, argv);

    auto a = new gengine::application::App();
    embindcefv8::addGlobalObject(*a, "gengineApp");

    gengine::gui::System::getInstance().init(argc, argv);

    loadScriptFile("main.js");

    while(true)
    {
        gengine::gui::System::getInstance().update();
    }
}
