package gengine.components;

import gengine.math.*;

class RigidBody2D extends UrhoComponent
{
    public inline function new()
    {
        super();

        untyped __js__("this.object = new Module.RigidBody2D(gengine.getContext())");
    }

    public inline function setBodyType(bodyType:Int)
    {
        this.object.setBodyType(bodyType);
    }

    public inline function setMass(mass:Float)
    {
        this.object.setMass(mass);
    }

    public inline function setInertia(inertia:Float)
    {
        this.object.setInertia(inertia);
    }

    public inline function setMassCenter(center:Vector2)
    {
        this.object.setMassCenter(center);
    }

    public inline function setLinearDamping(linearDamping:Float)
    {
        this.object.setLinearDamping(linearDamping);
    }

    public inline function setAngularDamping(angularDamping:Float)
    {
        this.object.setAngularDamping(angularDamping);
    }

    public inline function setFixedRotation(fixedRotation:Bool)
    {
        this.object.setFixedRotation(fixedRotation);
    }

    public inline function setBullet(bullet:Bool)
    {
        this.object.setBullet(bullet);
    }

    public inline function setGravityScale(gravityScale:Vector2)
    {
        this.object.setGravityScale(gravityScale);
    }

    public inline function setLinearVelocity(linearVelocity:Vector2)
    {
        this.object.setLinearVelocity(linearVelocity);
    }

    public inline function setAngularVelocity(angularVelocity:Float)
    {
        this.object.setAngularVelocity(angularVelocity);
    }

    public inline function applyForce(force:Vector2, point:Vector2, wake:Bool)
    {
        this.object.applyForce(force, point, wake);
    }

    public inline function applyForceToCenter(force:Vector2, wake:Bool)
    {
        this.object.applyForceToCenter(force, wake);
    }

    public inline function applyTorque(torque:Float, wake:Bool)
    {
        this.object.applyTorque(torque, wake);
    }

    public inline function applyLinearImpulse(impulse:Vector2, point:Vector2, wake:Bool)
    {
        this.object.applyLinearImpulse(impulse, point, wake);
    }

    public inline function applyAngularImpulse(impulse:Float, wake:Bool)
    {
        this.object.applyAngularImpulse(impulse, wake);
    }
}
