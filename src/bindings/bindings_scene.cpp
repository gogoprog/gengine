#include "bindings.h"

#include <Urho3D/Scene/Node.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/Component.h>
#include <Urho3D/Core/Context.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Urho2D/StaticSprite2D.h>

using namespace Urho3D;

EMBINDCEFV8_DECLARE_STRING(String, CString);
EMBINDCEFV8_DECLARE_ENUM(CreateMode);
EMBINDCEFV8_DECLARE_ENUM(TransformSpace);
EMBINDCEFV8_DECLARE_CLASS(Scene, void);
EMBINDCEFV8_DECLARE_CLASS(Node, void);
EMBINDCEFV8_DECLARE_CLASS(Context, void);
EMBINDCEFV8_DECLARE_CLASS(Component, void);

EMBINDCEFV8_BINDINGS(scene)
{
    embindcefv8::Class<Context>("Context");

    embindcefv8::Class<Node>("Node")
        .constructor<Context*>()
        .method("setName", &Node::SetName)
        .method("setPosition", &Node::SetPosition)
        .method("setWorldPosition", &Node::SetWorldPosition)
        .method("setRotation", &Node::SetRotation)
        .method("setRotation2D", &Node::SetRotation2D)
        .method("setWorldRotation2D", &Node::SetWorldRotation2D)
        .method("setDirection", &Node::SetDirection)
        .method("setScale", static_cast<void (Node::*)(const Vector3 &)>(&Node::SetScale))
        .method("setWorldScale", static_cast<void (Node::*)(const Vector3 &)>(&Node::SetWorldScale))
        .method("setEnabled", static_cast<void (Node::*)(bool)>(&Node::SetEnabled))
        .method("setDeepEnabled", &Node::SetDeepEnabled)
        .method("setParent", &Node::SetParent)
        .method("getPosition", &Node::GetPosition)
        .method("getWorldPosition", &Node::GetWorldPosition)
        .method("getDirection", &Node::GetDirection)
        .method("getRight", &Node::GetRight)
        .method("getUp", &Node::GetUp)
        .method("getScale", &Node::GetScale)
        .method("getRotation2D", &Node::GetRotation2D)
        .method("getWorldRotation2D", &Node::GetWorldRotation2D)
        .method("getParent", &Node::GetParent)
        .method("createChild", static_cast<Node* (Node::*)(unsigned, CreateMode, bool)>(&Node::CreateChild))
        .method("addChild", &Node::AddChild)
        .method("removeChild", static_cast<void (Node::*)(Node*)>(&Node::RemoveChild))
        .method("removeAllChildren", &Node::RemoveAllChildren)
        .method("addComponent", &Node::AddComponent)
        .method("removeComponent", static_cast<void (Node::*)(Component*)>(&Node::RemoveComponent))
        .method("roll", &Node::Roll)
        .method("yaw", &Node::Yaw)
        .method("pitch", &Node::Pitch)
        .method("lookAt", &Node::LookAt)
        .method("translate", &Node::Translate)
        .method("translate2D", &Node::Translate2D)
        .method("addRef", static_cast<void(Node::*)()>(&Node::AddRef))
        ;

    embindcefv8::Class<Scene>("Scene")
        .method("createChild", static_cast<Node* (Scene::*)(unsigned, CreateMode, bool)>(&Scene::CreateChild))
        .method("addChild", static_cast<void (Scene::*)(Node*, unsigned)>(&Scene::AddChild))
        .method("removeChild", static_cast<void (Scene::*)(Node*)>(&Scene::RemoveChild))
        .method("addComponent", static_cast<void (Scene::*)(Component*, unsigned, CreateMode)>(&Scene::AddComponent))
        ;

    embindcefv8::Class<Component>("Component")
        .method("getID", &Component::GetID)
        ;
}
