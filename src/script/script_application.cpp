#include "embindcefv8.h"

#include "application.h"
#include <Urho3D/Urho2D/Sprite2D.h>

using namespace gengine::application;
using namespace Urho3D;

DECLARE_STRING(String, CString)

EMBINDCEFV8_BINDINGS(application)
{
    embindcefv8::Class<App>("App")
        .method("getResourceCache", &App::getResourceCache)
        .method("getInput", &App::getInput)
        .method("createNode", &App::createNode)
        .method("getSprite2D", &App::getResource<Sprite2D>)
        ;

    embindcefv8::addGlobalObject(get(), "Application");
}
