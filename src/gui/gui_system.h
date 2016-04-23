#pragma once

#include "gui_cef_handler.h"
#include "singleton.h"

namespace gengine
{
namespace gui
{

class System
{
    friend class App;

public:
    SINGLETON(System);

    void preinit(int argc, char *argv[]);
    void init(int argc, char *argv[]);
    void finalize();
    void update();
    void loadFile(const char *file_path);
    void executeScript(const char *code);
    void showPage(const char *name, const char *effect, const int duration);

#ifndef EMSCRIPTEN
    Handler & getHandler() { return * handler; }
    CefBrowser & getBrowser() { return * browser; }

private:
    CefRefPtr<Handler>
        handler;
    CefRefPtr<CefBrowser>
        browser;
#endif
};

}
}
