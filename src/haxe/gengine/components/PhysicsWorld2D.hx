package gengine.components;

import gengine.math.*;

class PhysicsWorld2D extends UrhoComponent
{
    public inline function new()
    {
        super();

        untyped __js__("this.object = new Module.PhysicsWorld2D(gengine.getContext())");
    }

    public inline function setGravity(gravity:Vector2)
    {
        this.object.setGravity(gravity);
    }

    public inline function setContinuousPhysics(continuousPhysics:Bool)
    {
        this.object.setContinuousPhysics(continuousPhysics);
    }

    public inline function setSubStepping(subStepping:Bool)
    {
        this.object.setSubStepping(subStepping);
    }

    public inline function drawDebugGeometry()
    {
        this.object.drawDebugGeometry();
    }
}
