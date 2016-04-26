#include "gui_system.h"
#include "gui_cef_app.h"
#include "embindcefv8.h"
#include "application.h"

#include <sstream>

#ifdef _WINDOWS
    #include <direct.h>
#else
    #include "unistd.h"
#endif

#define JAVASCRIPT(src) \
    #src

#ifdef EMSCRIPTEN
    #include <emscripten.h>
    #include <emscripten/bind.h>

    using namespace emscripten;
#else
    using namespace Urho3D;
#endif

namespace gengine
{
namespace gui
{

void System::preinit(int argc, char *argv[])
{
    #ifndef EMSCRIPTEN
    {
        #ifdef _LINUX
            CefMainArgs args(argc, argv);
        #elif defined(_WINDOWS)
            CefMainArgs args(GetModuleHandle(NULL));
        #endif

        CefRefPtr<App> app(new App);

        int exit_code = CefExecuteProcess(args, app.get(), nullptr);

        if (exit_code >= 0)
        {
            exit(exit_code);
            return;
        }
    }
    #endif
}

void System::init(int argc, char *argv[])
{
    #ifndef EMSCRIPTEN
    {
        #ifdef _LINUX
            CefMainArgs args(argc, argv);
        #elif defined(_WINDOWS)
            CefMainArgs args(GetModuleHandle(NULL));
        #endif

        CefRefPtr<App> app(new App);

        handler = new Handler();

        CefSettings settings;
        memset(&settings, 0, sizeof(CefSettings));
        settings.single_process = true;
        settings.no_sandbox = true;
        settings.multi_threaded_message_loop = false;
        settings.size = sizeof(CefSettings);

        CefInitialize(args, settings, app.get(), nullptr);
    }
    #endif
}

void System::finalize()
{
    #ifndef EMSCRIPTEN
    {
        CefQuitMessageLoop();

        handler->finalize();
        handler = nullptr;
        browser = nullptr;

        CefShutdown();
    }
    #endif
}

void System::update()
{
    #ifndef EMSCRIPTEN
    {
        {
            static bool mouseWasDown = false;

            CefMouseEvent mouse_event;
            const auto & input = gengine::application::get().getInput();
            int wheelY;

            mouse_event.x = input.GetMousePosition().x_;
            mouse_event.y = input.GetMousePosition().y_;

            if(input.GetMouseButtonDown(1) && !mouseWasDown)
            {
                browser->GetHost()->SendMouseClickEvent(mouse_event, MBT_LEFT, false, 1);
                mouseWasDown = true;
            }

            if(!input.GetMouseButtonDown(1) && mouseWasDown)
            {
                browser->GetHost()->SendMouseClickEvent(mouse_event, MBT_LEFT, true, 1);
                mouseWasDown = false;
            }

            wheelY = input.GetMouseMoveWheel();

            if(wheelY != 0)
            {
                browser->GetHost()->SendMouseWheelEvent(mouse_event, 0, wheelY * 32);
            }

            browser->GetHost()->SendMouseMoveEvent(mouse_event, false);
        }

        CefDoMessageLoopWork();
    }
    #endif
}

void System::loadFile(const char *file_path)
{
    #ifndef EMSCRIPTEN
    {
        char cwd[1024];
        std::string url;
        url = "file://";

        if(file_path[0] != '/')
        {
            #ifdef _WINDOWS
                url += _getcwd(cwd, 1024);
            #else
                url += getcwd(cwd, 1024);
            #endif

            url += "/";
        }

        url += file_path;

        browser->GetMainFrame()->LoadURL(url);
        browser->GetHost()->SetFocus(true);
        browser->GetHost()->SendFocusEvent(true);
    }
    #else
    {
        std::string js_code;

        js_code = "loadFile('";
        js_code += file_path;
        js_code += "');";

        emscripten_run_script(js_code.c_str());
    }
    #endif
}

void System::executeScript(const char *code)
{
    #ifndef EMSCRIPTEN
    {
        CefRefPtr<CefFrame> frame = browser->GetMainFrame();
        frame->ExecuteJavaScript(code, frame->GetURL(), 0);
    }
    #else
    {
        emscripten_run_script(code);
    }
    #endif
}

void System::showPage(const char *name, const char *effect, const int duration)
{
    std::string js_code;

    js_code += "var nextPageName = '" + std::string(name) + "';";
    js_code += "var nextPage = $('#' + nextPageName);";
    js_code += "var halfDuration = " + std::to_string(duration) +" / 2;";
    js_code += "var effectName = '" + std::string(effect) + "';";

    js_code += JAVASCRIPT(
        $(".gengine-page").hide(
            effectName,
            halfDuration
            );

        $(".gengine-page").promise().done(
            function(index) {
                gengine.execute("gengine.gui:changeState('" + nextPageName + "')");
                nextPage.show(effectName, halfDuration);
            }
            );
        );

    executeScript(js_code.c_str());
}

}
}
