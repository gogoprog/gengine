package gengine.components;

import gengine.math.*;

class CollisionShape2D extends UrhoComponent
{
    public inline function new()
    {
        super();
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

    public inline function setCategoryBits(bits:Int)
    {
        this.object.setCategoryBits(bits);
    }

    public inline function setMaskBits(bits:Int)
    {
        this.object.setMaskBits(bits);
    }

    public inline function setGroupIndex(index:Int)
    {
        this.object.setGroupIndex(index);
    }
}
