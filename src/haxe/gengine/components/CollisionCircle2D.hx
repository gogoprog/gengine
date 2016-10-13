package gengine.components;

import gengine.math.*;

class CollisionCircle2D extends UrhoComponent
{
    public inline function new()
    {
        super();

        untyped __js__("this.object = new Module.CollisionCircle2D(gengine.getContext())");
    }

    public inline function setRadius(radius:Float)
    {
        this.object.setRadius(radius);
    }

    public inline function setCenter(center:Vector2)
    {
        this.object.setCenter(center);
    }

    public inline function setDensity(density:Float)
    {
        this.object.setDensity(density);
    }

    public inline function setFriction(friction:Float)
    {
        this.object.setFriction(friction);
    }

    public inline function setRestitution(restitution:Float)
    {
        this.object.setRestitution(restitution);
    }

    public inline function setTrigger(trigger:Bool)
    {
        this.object.setTrigger(trigger);
    }
}
