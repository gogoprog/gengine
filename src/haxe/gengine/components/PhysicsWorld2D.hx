package gengine.components;

import gengine.math.*;
import gengine.physics.*;
import gengine.systems.Physics2DSystem;

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

    public inline function raycastSingle(result:PhysicsRaycastResult2D, startPoint:Vector2, endPoint:Vector2, ?collisionMask = 0xffffffff)
    {
        this.object.raycastSingle(result, startPoint, endPoint, collisionMask);
    }

    public inline function getEntity(point:Vector2, ?collisionMask = 0xffffffff):Entity
    {
        var urhoBody = this.object.getRigidBody(point, collisionMask);
        return Physics2DSystem.getEntity(urhoBody);
    }
}
