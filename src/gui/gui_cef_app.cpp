#ifndef EMSCRIPTEN
#include "gui_cef_app.h"

#include "gui_system.h"
#include "include/cef_client.h"
#include "embindcefv8.h"
#include "application.h"

namespace gengine
{
namespace gui
{

void App::OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context)
{
    embindcefv8::onContextCreated(context);
}

void App::OnContextInitialized()
{
    CefWindowInfo window_info;

    window_info.SetAsOffScreen(nullptr);
    window_info.SetTransparentPainting(true);

    CefBrowserSettings browser_settings;

    System::getInstance().browser = CefBrowserHost::CreateBrowserSync(window_info, & System::getInstance().getHandler(), "about:blank", browser_settings, nullptr);
    embindcefv8::setBrowser(System::getInstance().browser);
}

bool App::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefProcessId source_process, CefRefPtr<CefProcessMessage> message)
{
    if(message->GetName() == "gengineUpdate")
    {
        application::get().runFrame();
        return true;
    }
    else if(message->GetName() == "gengineInit")
    {
        application::App::init();
        //embindcefv8::addGlobalObject(application::get(), "Application");
        application::get().setup();
        application::get().start();
        return true;
    }

    return false;
}

}
}
#endif
