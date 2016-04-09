#include "embindcefv8.h"

#include <Urho3D/Scene/Node.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Urho2D/StaticSprite2D.h>

using namespace Urho3D;

DECLARE_ENUM(CreateMode)

EMBINDCEFV8_BINDINGS(scene)
{
    embindcefv8::Class<Node>("Node")
        .method("setPosition", &Node::SetPosition)
        .method("getPosition", &Node::GetPosition)
        .method("createComponentCamera", &Node::CreateComponent<Camera>)
        .method("createComponentStaticSprite2D", &Node::CreateComponent<StaticSprite2D>)
        .method("createChild", static_cast<Node* (Node::*)(unsigned, CreateMode)>(&Node::CreateChild))
        .method("addChild", &Node::AddChild)
        .method("removeChild", static_cast<void (Node::*)(Node*)>(&Node::RemoveChild))
        ;

    embindcefv8::Class<Scene>("Scene")
        .method("createChild", static_cast<Node* (Scene::*)(unsigned, CreateMode)>(&Scene::CreateChild))
        ;

}
