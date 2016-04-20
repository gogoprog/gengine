package gengine.math;

@:native('Module.Vector3')
extern class Vector3
{
    public var x:Float;
    public var y:Float;
    public var z:Float;

    @:selfCall
    public function new(x:Float, y:Float, z:Float);
}
