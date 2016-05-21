package gengine.components;

import gengine.math.*;

class PhysicsWorld2D extends UrhoComponent
{
    public inline function new()
    {
        super();

        untyped __js__("this.object = new Module.PhysicsWorld2D(gengine.getContext())");
        untyped __js__("window.dummyNode.addComponent(this.object, 0, 0);");
    }

    public inline function setGravity(gravity:Vector2)
    {
        this.object.setGravity(gravity);
    }
}
