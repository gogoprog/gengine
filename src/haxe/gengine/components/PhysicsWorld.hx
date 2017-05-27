package gengine.components;

import gengine.math.*;
import gengine.physics.*;

class PhysicsWorld extends UrhoComponent
{
    public inline function new()
    {
        super();

        untyped __js__("this.object = new Module.PhysicsWorld(gengine.getContext())");
    }

    public inline function setGravity(gravity:Vector3)
    {
        this.object.setGravity(gravity);
    }
}
