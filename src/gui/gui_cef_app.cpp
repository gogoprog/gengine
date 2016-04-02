#ifndef EMSCRIPTEN
#include "gui_cef_app.h"

#include "gui_system.h"
#include "include/cef_client.h"
#include "embindcefv8.h"

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

void App::OnRegisterCustomSchemes(CefRefPtr<CefSchemeRegistrar> registrar)
{
}

}
}
#endif
