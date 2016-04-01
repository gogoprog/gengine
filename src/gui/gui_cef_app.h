#pragma once

#ifndef EMSCRIPTEN

#define CEF_ENABLE_SANDBOX 0

#include "include/cef_app.h"
#include "include/cef_request_handler.h"

namespace gengine
{
namespace gui
{

class App : public CefApp, public CefBrowserProcessHandler, public CefRenderProcessHandler
{
public:
    App() = default;

    virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override { return this; }
    virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override { return this; }
    virtual void OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context) override;
    virtual void OnContextInitialized() override;
    virtual void OnRegisterCustomSchemes(CefRefPtr<CefSchemeRegistrar> registrar) override;

private:

    IMPLEMENT_REFCOUNTING(App);
};

}
}
#endif
