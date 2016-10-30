#ifndef EMSCRIPTEN

#include "gui_cef_handler.h"
#include "gui_system.h"
#include "application.h"

#include "include/cef_client.h"
#include <Urho3D/UI/Sprite.h>
#include <Urho3D/Graphics/Graphics.h>

#ifdef _WINDOWS
    #include <direct.h>
#else
    #include "unistd.h"
#endif

namespace gengine
{
namespace gui
{

Handler::Handler()
    :
    textureBuffer(nullptr)
{
}

void Handler::init()
{
    const auto & size = application::get().getWindowSize();
    uint width = size.x_;
    uint height = size.y_;

    texture = new Urho3D::Texture2D(&application::get().getContext());
    texture->SetMipsToSkip(Urho3D::QUALITY_LOW, 0);
    texture->SetNumLevels(1);
    texture->SetSize(width, height, Urho3D::Graphics::GetBGRAFormat());

    auto sprite = new Urho3D::Sprite(&application::get().getContext());
    sprite->SetTexture(texture);
    sprite->SetSize(Urho3D::IntVector2(width, height));
    sprite->SetHotSpot(Urho3D::IntVector2(0, 0));
    sprite->SetColor(Urho3D::Color(1.0f, 1.0f, 1.0f, 1.0f));
    sprite->SetBlendMode(Urho3D::BLEND_ALPHA);
    application::get().getUI().GetRoot()->AddChild(sprite);

    textureBuffer = new char[width * height * 4];
    memset(textureBuffer, 0, width * height * 4);
    texture->SetData(0, 0, 0, width, height, textureBuffer);

    gui::System::getInstance().getBrowser().GetHost()->WasResized();
}

void Handler::finalize()
{
    delete []textureBuffer;
}

void Handler::updateTexture()
{
    static const auto & size = application::get().getWindowSize();

    texture->SetData(0, 0, 0, size.x_, size.y_, textureBuffer);
}

bool Handler::GetViewRect(CefRefPtr<CefBrowser> browser, CefRect &rect)
{
    if(textureBuffer)
    {
        static const auto & size = application::get().getWindowSize();
        rect = CefRect(0, 0, size.x_, size.y_);
        return true;
    }

    return false;
}

void Handler::OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList &dirtyRects, const void *buffer, int width, int height)
{
    if(textureBuffer)
    {
        memcpy(textureBuffer, buffer, width * height * 4);
    }
}

bool Handler::OnBeforeResourceLoad(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefRequest> request)
{
    std::string str = request->GetURL().ToString().c_str();
    std::string::size_type pos = 0u;
    std::string stringToReplace = "/gui/gui/";

    if((pos = str.find(stringToReplace, pos)) != std::string::npos)
    {
         str.replace(pos, stringToReplace.length(), "/gui/");

         request->SetURL(str);
    }

    return false;
}

void Handler::OnLoadEnd(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, int httpStatusCode)
{
    static bool firstTime = true;
    if(firstTime)
    {
        gengine::application::preInit();
        firstTime = false;
    }
    else
    {
        gengine::application::init();
    }
}

bool Handler::OnConsoleMessage(CefRefPtr<CefBrowser> browser, const CefString& message, const CefString& source, int line)
{
    printf("\033[36m(%s:%i) ", source.ToString().c_str(), line);
    printf("\033[33m");
    printf(message.ToString().c_str());
    puts("\033[0m");

    return true;
}

}
}
#endif
