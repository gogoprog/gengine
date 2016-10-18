package gengine.components;

import gengine.math.*;

class CollisionCircle2D extends CollisionShape2D
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
}
