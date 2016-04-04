#include "embindcefv8.h"

#include <Urho3D/Scene/Node.h>
#include <Urho3D/Graphics/Camera.h>

using namespace Urho3D;

EMBINDCEFV8_BINDINGS(scene)
{
    embindcefv8::Class<Node>("Node")
        .method("setPosition", &Node::SetPosition)
        .method("getPosition", &Node::GetPosition)
        //.method("createComponentCamera", &Node::CreateComponent<Camera>)
        ;
}
