package gengine.physics;

import gengine.math.*;

@:native('Module.PhysicsRaycastResult2D')
extern class PhysicsRaycastResult2D
{
    public function new();

    public var position:Vector2;
    public var normal:Vector2;
    public var distance:Float;
}
