#include "application.h"

#include "gui_system.h"
#include "embindcefv8.h"
#include <fstream>

#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Core/Timer.h>
#include <Urho3D/Core/Thread.h>
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Engine/Console.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/Texture2D.h>
#include <Urho3D/Urho2D/Sprite2D.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>

using namespace Urho3D;

SharedPtr<gengine::application::App>
    mainApp;
int
    _argc;
char
    ** _argv;

namespace gengine
{
namespace application
{

App::App()
    :
    Application(new Context()),
    name("Unnamed"),
    fullscreen(false),
    mustQuit(false),
    width(640),
    height(480)
{
}

void App::Setup()
{
    engineParameters_["LogName"] = "gengine.log";
    engineParameters_["LogLevel"] = "Debug";
    engineParameters_["FullScreen"] = fullscreen;
    engineParameters_["Headless"] = false;
    engineParameters_["Sound"] = false;
    engineParameters_["WindowWidth"] = width;
    engineParameters_["WindowHeight"] = height;
    engineParameters_["WindowTitle"] = name;
    engineParameters_["ResourcePaths"] = "data;coreData;";
    engineParameters_["ResourcePrefixPaths"] = (String(getFileSystem().GetCurrentDir().CString()) + ";" + String(getenv("GENGINE")) + "/res/");
}

void App::Start()
{
    gengine::gui::System::getInstance().init(_argc, _argv);

    getInput().SetMouseVisible(true);

    SubscribeToEvent(E_UPDATE, URHO3D_HANDLER(App, update));

    SharedPtr<Scene> scene_(new Scene(context_));
    scene = scene_;
    scene_->CreateComponent<Octree>();

    auto cameraNode_ = scene_->CreateChild("Camera");
    auto camera = cameraNode_->CreateComponent<Camera>();
    camera->SetOrthographic(true);
    camera->SetOrthoSize(Vector2(float(width), float(height)));

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

void App::update(StringHash eventType, VariantMap& eventData)
{
    using namespace Update;
    float timeStep = eventData[P_TIMESTEP].GetFloat();
    String code;

    code = "update(";
    code += timeStep;
    code += ");";

    if(mustQuit)
    {
        engine_->Exit();
    }
}

Node & App::createNode()
{
    return * scene->CreateChild();
}

App & get()
{
    return *mainApp;
}

}
}

void loadScriptFile(const char *filename)
{
    std::ifstream in(filename);
    std::string contents((std::istreambuf_iterator<char>(in)),
    std::istreambuf_iterator<char>());

    contents = "application = new Module.App(); application.setup(); application.start();" + contents;
    contents += R"(
        while(1)
        {
            application.runFrame();
            if(typeof update !== 'undefined')
            {
                update(0);
            }
        }
        )";


    embindcefv8::executeJavaScript(contents.c_str());
}

int main(int argc, char *argv[])
{
    gengine::gui::System::getInstance().preinit(argc, argv);
    gengine::gui::System::getInstance().init(_argc, _argv);

    loadScriptFile("data/main.js");

    while(true)
    {
        gengine::gui::System::getInstance().update();
    }
}
