#include "application_app.h"

#include "gui_system.h"
#include "embindcefv8.h"
#include "application.h"
#include <fstream>
#include <sstream>

#define URHO3D_LOGGING

#include <Urho3D/IO/Log.h>
#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Core/Timer.h>
#include <Urho3D/Core/Thread.h>
#include <Urho3D/Engine/Application.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/Graphics/GraphicsImpl.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/SceneEvents.h>
#include <Urho3D/Urho2D/PhysicsEvents2D.h>
#include <Urho3D/Urho2D/RigidBody2D.h>
#include <Urho3D/Urho2D/StaticSprite2D.h>
#include <SDL/SDL.h>

#define STRING(src) \
    #src

using namespace Urho3D;

namespace gengine
{
namespace application
{

static std::stringstream
    ss;

App::App()
    :
    Application(new Context()),
    windowTitle("gengine application"),
    guiFilename("about:blank"),
    fullscreen(false),
    windowSize(640, 480)
{
    instance = this;
}

void App::Setup()
{
    engineParameters_["LogName"] = "gengine.log";
    engineParameters_["LogLevel"] = "Debug";
    engineParameters_["FullScreen"] = fullscreen;
    engineParameters_["Headless"] = false;
    engineParameters_["Sound"] = true;
    engineParameters_["WindowWidth"] = windowSize.x_;
    engineParameters_["WindowHeight"] = windowSize.y_;
    engineParameters_["WindowTitle"] = windowTitle;
    engineParameters_["WindowResizable"] = false;
    engineParameters_["ResourcePaths"] = "data;coreData;";
    engineParameters_["ResourcePrefixPaths"] = (String(getFileSystem().GetCurrentDir().CString()) + ";" + String(getenv("GENGINE")) + "/res/");
}

void App::Start()
{
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

#ifdef EMSCRIPTEN
    SubscribeToEvent(Urho3D::E_UPDATE, URHO3D_HANDLER(App, update));
    embindcefv8::executeJavaScript("Main.start(); Main.$startCalled = true;");
#endif

    SubscribeToEvent(Urho3D::E_PHYSICSBEGINCONTACT2D, URHO3D_HANDLER(App, onPhysicsBeginContact2D));
}

void App::Stop()
{
}

int App::setup()
{
    Thread::SetMainThread();

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
    Thread::SetMainThread();

    Start();

#ifdef CEF
    gui::System::getInstance().getHandler().init();
#endif

    gui::System::getInstance().loadFile(gengine::application::get().getGuiFilename().CString());
}

void App::runFrame()
{
    Thread::SetMainThread();
    engine_->RunFrame();

#ifdef CEF
    gengine::gui::System::getInstance().getHandler().updateTexture();
    gengine::gui::System::getInstance().updateInput();
#endif
}

void App::stop()
{
    Stop();
}

void App::exit()
{
    engine_->Exit();
}

void App::takeScreenshot(const Urho3D::String & filename)
{
    URHO3D_LOGDEBUG("Saving screenshot " + filename);
    Image screenshot(context_);
    GetSubsystem<Graphics>()->TakeScreenShot(screenshot);
    screenshot.SavePNG(filename);
}

void App::setGuiFilename(const Urho3D::String & filename)
{
    guiFilename = filename;
#ifdef EMSCRIPTEN
    gui::System::getInstance().loadFile(guiFilename.CString());
#endif
}

void App::setStartupString(const Urho3D::String & str)
{
    startupString = str;
}

gui::System & App::getGui()
{
    return gui::System::getInstance();
}

Node & App::createNode()
{
    return * scene->CreateChild();
}

void App::setKeyboardElement(const Urho3D::String & str)
{
    SDL_SetHint(SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT, str.CString());
}

void App::update(StringHash eventType, VariantMap& eventData)
{
    ss.str("");
    ss << "Main.update(" << getTimeStep() << ");";
    embindcefv8::executeJavaScript(ss.str().c_str());
}

// Events :

void App::onPhysicsBeginContact2D(StringHash eventType, VariantMap& eventData)
{
    unsigned aId = dynamic_cast<RigidBody2D*>(eventData[PhysicsBeginContact2D::P_BODYA].GetPtr())->GetID();
    unsigned bId = dynamic_cast<RigidBody2D*>(eventData[PhysicsBeginContact2D::P_BODYB].GetPtr())->GetID();

    ss.str("");
    ss << "Main.onPhysicsBeginContact2D(" << aId << ", " << bId << ");";

    embindcefv8::executeJavaScript(ss.str().c_str());
}

SharedPtr<App>
    App::instance;

}
}
