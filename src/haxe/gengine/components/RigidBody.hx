package gengine.components;

import gengine.math.*;

class RigidBody extends UrhoComponent
{
    public inline function new()
    {
        super();

        untyped __js__("this.object = new Module.RigidBody(gengine.getContext())");
    }

    public inline function setMass(mass:Float)
    {
        this.object.setMass(mass);
    }

    public inline function setFriction(friction:Float)
    {
        this.object.setFriction(friction);
    }

    public inline function setCollisionEventMode(mode:Int)
    {
        this.object.setCollisionEventMode(mode);
    }
}
