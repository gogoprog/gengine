#include "embindcefv8.h"

#include "application.h"

using namespace gengine::application;

EMBINDCEFV8_BINDINGS(application)
{
    embindcefv8::Class<App>("App")
        .method("getInput", &App::getInput)
        .method("createNode", &App::createNode)
        ;

    embindcefv8::addGlobalObject(get(), "Application");
}
