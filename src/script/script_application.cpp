#include "embindcefv8.h"

#include "application.h"

using namespace gengine::application;
using namespace Urho3D;

EMBINDCEFV8_BINDINGS(application)
{
    embindcefv8::Class<App>("App")
        .constructor()
        .method("getResourceCache", &App::getResourceCache)
        .method("getInput", &App::getInput)
        .method("createNode", &App::createNode)
        .method("runFrame", &App::runFrame)
        .method("setup", &App::setup)
        .method("start", &App::start)
        ;
}
