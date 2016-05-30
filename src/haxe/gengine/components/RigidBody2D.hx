package gengine.components;

import gengine.math.*;

class RigidBody2D extends UrhoComponent
{
    public inline function new()
    {
        super();

        untyped __js__("this.object = new Module.RigidBody2D(gengine.getContext())");
        untyped __js__("window.dummyNode.addComponent(this.object, 0, 0);");
    }

    public inline function setBodyType(bodyType:Int)
    {
        this.object.setBodyType(bodyType);
    }
}
