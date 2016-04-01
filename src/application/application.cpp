#include "application.h"

#include <string>

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

namespace gengine
{
namespace application
{

Application::Application(Urho3D::Context* context)
    :
    Urho3D::Application(context),
    name("Unnamed"),
    fullscreen(false),
    mustQuit(false),
    width(640),
    height(480)
{
}

void Application::Setup()
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

    engineParameters_["ResourcePrefixPaths"] = (Urho3D::String(GetSubsystem<Urho3D::FileSystem>()->GetCurrentDir().CString()) + ";" + Urho3D::String(getenv("GENGINE")) + "/res/");
}

void Application::Start()
{
    //gui::System::getInstance().init(core::getArgc(), core::getArgv());

    SubscribeToEvent(Urho3D::E_UPDATE, URHO3D_HANDLER(Application, update));

    Urho3D::SharedPtr<Urho3D::Scene> scene_(new Urho3D::Scene(context_));
    scene_->CreateComponent<Urho3D::Octree>();

    auto cameraNode_ = scene_->CreateChild("Camera");
    auto camera = cameraNode_->CreateComponent<Urho3D::Camera>();
    camera->SetOrthographic(true);
    camera->SetOrthoSize(Urho3D::Vector2(float(width), float(height)));

    auto renderer = GetSubsystem<Urho3D::Renderer>();
    auto viewport = new Urho3D::Viewport(context_, scene_, cameraNode_->GetComponent<Urho3D::Camera>());
    renderer->SetViewport(0, viewport);
}

void Application::Stop()
{
}

void Application::update(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData)
{
    if(mustQuit)
    {
        engine_->Exit();
    }
}

}
}
