package gengine.components;

import gengine.math.*;

class CollisionBox2D extends UrhoComponent
{
    public inline function new()
    {
        super();

        untyped __js__("this.object = new Module.CollisionBox2D(gengine.getContext())");
    }

    public inline function setSize(size:Vector2)
    {
        this.object.setSize(size);
    }

    public inline function setCenter(center:Vector2)
    {
        this.object.setCenter(center);
    }

    public inline function setAngle(angle:Float)
    {
        this.object.setAngle(angle);
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
}
