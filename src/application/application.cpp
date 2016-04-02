#include "application.h"

#include "gui_system.h"
#include "embindcefv8.h"

#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Core/Timer.h>
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Engine/Console.h>
#include <Urho3D/Engine/DebugHud.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/Texture2D.h>
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

App::App(Context* context)
    :
    Application(context),
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
    gui::System::getInstance().init(_argc, _argv);

    SubscribeToEvent(E_UPDATE, URHO3D_HANDLER(App, update));

    SharedPtr<Scene> scene_(new Scene(context_));
    scene_->CreateComponent<Octree>();

    auto cameraNode_ = scene_->CreateChild("Camera");
    auto camera = cameraNode_->CreateComponent<Camera>();
    camera->SetOrthographic(true);
    camera->SetOrthoSize(Vector2(float(width), float(height)));

    auto renderer = GetSubsystem<Renderer>();
    auto viewport = new Viewport(context_, scene_, cameraNode_->GetComponent<Camera>());
    renderer->SetViewport(0, viewport);

    loadScriptFile("data/main.js");
}

void App::Stop()
{
}

void App::update(StringHash eventType, VariantMap& eventData)
{
    gui::System::getInstance().update();

    if(mustQuit)
    {
        engine_->Exit();
    }
}

void App::loadScriptFile(const Urho3D::String & str)
{
    char
        buffer[10240+1];

    auto file = getResourceCache().GetFile(str);
    auto bytes_read = file->Read(buffer, 10240);
    buffer[bytes_read] = 0;

    embindcefv8::executeJavaScript(buffer);
}


App & get()
{
    return *mainApp;
}

}
}

int main(int argc, char *argv[])
{
    gengine::gui::System::getInstance().preinit(argc, argv);
    mainApp = new gengine::application::App(new Context());

    return mainApp->Run();
}
