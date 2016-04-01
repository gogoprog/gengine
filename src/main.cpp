#include "app.h"

int main(int argc, char *argv[])
{
    auto mainApp = new gengine::application::App(new Urho3D::Context());

    return mainApp->Run();
}
