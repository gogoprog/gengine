#include "embindcefv8.h"

#include <Urho3D/Scene/Node.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/Component.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Urho2D/StaticSprite2D.h>

using namespace Urho3D;

DECLARE_ENUM(CreateMode)

EMBINDCEFV8_BINDINGS(scene)
{
    embindcefv8::Class<Node>("Node")
        .constructor<Context*>()
        .method("setPosition", &Node::SetPosition)
        .method("setRotation", &Node::SetRotation)
        .method("setRotation2D", &Node::SetRotation2D)
        .method("setDirection", &Node::SetDirection)
        .method("setScale", static_cast<void (Node::*)(const Vector3 &)>(&Node::SetScale))
        .method("setEnabled", static_cast<void (Node::*)(bool)>(&Node::SetEnabled))
        .method("setDeepEnabled", &Node::SetDeepEnabled)
        .method("getPosition", &Node::GetPosition)
        .method("createComponentCamera", &Node::CreateComponent<Camera>)
        .method("createComponentStaticSprite2D", &Node::CreateComponent<StaticSprite2D>)
        .method("createChild", static_cast<Node* (Node::*)(unsigned, CreateMode)>(&Node::CreateChild))
        .method("addChild", &Node::AddChild)
        .method("removeChild", static_cast<void (Node::*)(Node*)>(&Node::RemoveChild))
        .method("removeAllChildren", &Node::RemoveAllChildren)
        .method("addComponent", &Node::AddComponent)
        ;

    embindcefv8::Class<Scene>("Scene")
        .method("createChild", static_cast<Node* (Scene::*)(unsigned, CreateMode)>(&Scene::CreateChild))
        .method("addChild", static_cast<void (Scene::*)(Node*, unsigned)>(&Scene::AddChild))
        .method("removeChild", static_cast<void (Scene::*)(Node*)>(&Scene::RemoveChild))
        ;

    embindcefv8::Class<Component>("Component")
        ;
}
