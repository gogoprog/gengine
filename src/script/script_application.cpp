#include "embindcefv8.h"

#include "application.h"

using namespace gengine::application;
using namespace Urho3D;

DECLARE_STRING(String, CString)

EMBINDCEFV8_BINDINGS(application)
{
    embindcefv8::Class<App>("App")
        .constructor()
        .method("runFrame", &App::runFrame)
        .method("setup", &App::setup)
        .method("start", &App::start)
        .method("exit", &App::exit)
        .method("getResourceCache", &App::getResourceCache)
        .method("getInput", &App::getInput)
        .method("getTimeStep", &App::getTimeStep)
        .method("getScene", &App::getScene)
        .method("getContext", &App::getContext)
        .method("isRunning", &App::isRunning)
        .method("setWindowTitle", &App::setWindowTitle)
        .method("setWindowSize", &App::setWindowSize)
        ;
}
