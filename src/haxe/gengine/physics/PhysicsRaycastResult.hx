package gengine.physics;

import gengine.math.*;

@:native('Module.PhysicsRaycastResult')
extern class PhysicsRaycastResult
{
    public function new();

    public var position:Vector3;
    public var normal:Vector3;
    public var distance:Float;
    public var hitFraction:Float;
}
