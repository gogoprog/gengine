#include "application.h"

#include "gui_system.h"
#include "embindcefv8.h"
#include <fstream>
#include <sstream>

#define STRING(src) \
    #src

using namespace Urho3D;

namespace gengine
{
namespace application
{

#ifdef CEF
void loadScriptFile(const char *filename, const char *additional_code)
{
    std::ifstream in(filename);
    std::string contents((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

    contents += additional_code;

    embindcefv8::executeJavaScript(contents.c_str());
}

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
