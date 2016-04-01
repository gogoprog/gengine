#include "application.h"

using namespace gengine;

int main(int argc, char *argv[])
{
    auto mainApp = new gengine::application::Application(new Urho3D::Context());

    return mainApp->Run();
}
