#include "application.h"

#include "gui_system.h"
#include "embindcefv8.h"
#include <fstream>
#include <sstream>

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
        embindcefv8::executeJavaScript("Main.start();");
    #endif
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

gui::System & App::getGui()
{
    return gui::System::getInstance();
}

Node & App::createNode()
{
    return * scene->CreateChild();
}

void App::update(StringHash eventType, VariantMap& eventData)
{
    static std::stringstream ss;
    ss.str("");
    ss << "Main.update(" << getTimeStep() << ");";
    embindcefv8::executeJavaScript(ss.str().c_str());
}

SharedPtr<App>
    App::instance;

void loadScriptFile(const char *filename, const char *additional_code)
{
    std::ifstream in(filename);
    std::string contents((std::istreambuf_iterator<char>(in)),
    std::istreambuf_iterator<char>());

    contents += additional_code;

    embindcefv8::executeJavaScript(contents.c_str());
}

#if CEF
    void preInit()
    {
        const char js_code[] =
            #include "application_preinit.js"

        loadScriptFile("generated/main.js", js_code);
    }

    void init()
    {
        const char js_code[] =
            #include "application_init.js"

        loadScriptFile("generated/main.js", js_code);
    }
#endif

}
}

gengine::application::App
    *mainApp;

EMBINDCEFV8_DECLARE_STRING(String, CString)
EMBINDCEFV8_DECLARE_CLASS(gengine::application::App)

int main(int argc, char *argv[])
{
    gengine::gui::System::getInstance().preinit(argc, argv);

    mainApp = new gengine::application::App();

    embindcefv8::addGlobalObject(*mainApp, "gengine");

    gengine::gui::System::getInstance().init(argc, argv);

    #ifdef EMSCRIPTEN
        gengine::application::loadScriptFile("generated/main.js", " gengine = Module.gengine;");
        embindcefv8::executeJavaScript("Main.init();");
        gengine::gui::System::getInstance().loadFile(gengine::application::get().getGuiFilename().CString());
        mainApp->run();
    #else
        auto engine = mainApp->getEngine();
        while(!engine->IsExiting())
        {
            gengine::gui::System::getInstance().update();
        }
    #endif
}
