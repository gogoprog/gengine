#pragma once

#ifndef EMSCRIPTEN

#include "include/cef_app.h"
#include "include/cef_client.h"
#include "include/cef_request_handler.h"
#include "include/cef_load_handler.h"
#include <Urho3D/Graphics/Texture2D.h>

namespace gengine
{
namespace gui
{

class Handler : public CefRenderHandler, public CefClient, public CefRequestHandler, public CefLoadHandler, public CefDisplayHandler
{
public:
    Handler();

    void init();
    void finalize();
    void updateTexture();

    virtual bool GetViewRect(CefRefPtr<CefBrowser> browser, CefRect &rect) override;
    virtual void OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList &dirtyRects, const void *buffer, int width, int height) override;

    virtual CefRefPtr<CefRenderHandler> GetRenderHandler() override { return this; }
    virtual CefRefPtr<CefRequestHandler> GetRequestHandler() override { return this; }
    virtual CefRefPtr<CefLoadHandler> GetLoadHandler() override { return this; }
    virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() override { return this; }

    virtual bool OnBeforeResourceLoad(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefRequest> request) override;
    virtual void OnLoadEnd(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, int httpStatusCode) override;
    virtual bool OnConsoleMessage(CefRefPtr<CefBrowser> browser, const CefString& message, const CefString& source, int line) override;

    IMPLEMENT_REFCOUNTING(Handler)

private:
    uint
        pboId;
    Urho3D::SharedPtr<Urho3D::Texture2D>
        texture;
    std::string
        textToExecute;
    char
        *textureBuffer;

    IMPLEMENT_LOCKING(Handler)
};

}
}
#endif
