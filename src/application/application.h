#pragma once

#include "application_app.h"

namespace gengine
{
namespace gui { class System; }
namespace application
{

inline App & get()
{
    return App::getInstance();
}

void loadScriptFile(const char *filename, const char *additional_code = "");

#if CEF
void preInit();
void init();
#endif

}
}
