#include "embindcefv8.h"

#include "application.h"
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Core/Context.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Audio/Audio.h>

using namespace gengine::application;
using namespace Urho3D;

EMBINDCEFV8_DECLARE_STRING(String, CString);
EMBINDCEFV8_IMPLEMENT_STRING(String);
EMBINDCEFV8_DECLARE_CLASS(Scene);
EMBINDCEFV8_DECLARE_CLASS(ResourceCache);
EMBINDCEFV8_DECLARE_CLASS(Input);
EMBINDCEFV8_DECLARE_CLASS(Context);
EMBINDCEFV8_DECLARE_CLASS(Renderer);
EMBINDCEFV8_DECLARE_CLASS(Audio);

EMBINDCEFV8_BINDINGS(application)
{
    embindcefv8::Class<App>("App")
        .constructor()
        .method("runFrame", &App::runFrame)
        .method("setup", &App::setup)
        .method("start", &App::start)
        .method("exit", &App::exit)
        .method("getResourceCache", &App::getResourceCache)
        .method("getRenderer", &App::getRenderer)
        .method("getInput", &App::getInput)
        .method("getTimeStep", &App::getTimeStep)
        .method("getScene", &App::getScene)
        .method("getContext", &App::getContext)
        .method("getAudio", &App::getAudio)
        .method("isRunning", &App::isRunning)
        .method("setWindowTitle", &App::setWindowTitle)
        .method("setGuiFilename", &App::setGuiFilename)
        .method("setWindowSize", &App::setWindowSize)
        ;
}
