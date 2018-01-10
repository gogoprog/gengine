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

struct LocalKey
{
    int scanCode;
    int nativeCode;
    int windowsCode;
    char character;
};

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
        CefDoMessageLoopWork();
    #endif
}

void System::updateInput()
{
    #ifndef EMSCRIPTEN
    {
        {
            static bool mouseWasDown = false;

            static std::vector<std::string> chars {
                "qwertyuiopasdfghjklzxcvbnm1234567890_+[]/<> '",
                "QWERTYUIOPASDFGHJKLZXCVBNM!@#$%^&*()-={}?,. \""
            };

            static int charsCount = chars[0].length();

            static std::vector<LocalKey> keys{
                {SDL_SCANCODE_RETURN, 65293, 13, '\r'},
                {SDL_SCANCODE_BACKSPACE, 65288, 8, 0},
                {SDL_SCANCODE_UP, 65362, 273, 0},
                {SDL_SCANCODE_DOWN, 65364, 274, 0},
                {SDL_SCANCODE_LEFT, 65361, 276, 0},
                {SDL_SCANCODE_RIGHT, 65363, 275, 0},
                {SDL_SCANCODE_INSERT, 65379, 277, 0},
                {SDL_SCANCODE_DELETE, 65535, 127, 0},
                {SDL_SCANCODE_HOME, 65360, 278, 0},
                {SDL_SCANCODE_END, 65367, 279, 0},
                {SDL_SCANCODE_PAGEUP, 65365, 280, 0},
                {SDL_SCANCODE_PAGEDOWN, 65366, 281, 0},
            };

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

            CefKeyEvent key_event;

            bool shift = input.GetKeyDown(SDLK_RSHIFT) || input.GetKeyDown(SDLK_LSHIFT);
            key_event.modifiers = shift ? EVENTFLAG_SHIFT_DOWN : 0;

            for(int i=0; i<charsCount;++i)
            {
                for(int s = 0; s < 2; ++s)
                {
                    char key = chars[s][i];

                    if(input.GetKeyPress(key))
                    {
                        key = shift ? chars[1-s][i] : key;
                        key_event.type = KEYEVENT_CHAR;
                        key_event.native_key_code = key;
                        key_event.character = key;

                        browser->GetHost()->SendKeyEvent(key_event);

                        break;
                    }
                }
            }

            for(auto & key : keys)
            {
                if(input.GetScancodePress(key.scanCode))
                {
                    key_event.type = KEYEVENT_RAWKEYDOWN;
                    key_event.native_key_code = key.nativeCode;
                    key_event.windows_key_code = key.windowsCode;
                    browser->GetHost()->SendKeyEvent(key_event);

                    if(key.character)
                    {
                        key_event.type = KEYEVENT_CHAR;
                        key_event.character = key.character;
                        key_event.unmodified_character = key.character;
                        browser->GetHost()->SendKeyEvent(key_event);
                    }
                }
            }
        }
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

}
}
