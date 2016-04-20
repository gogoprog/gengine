package gengine.math;

@:native('Module.Vector2')
extern class Vector2
{
    public var x:Float;
    public var y:Float;

    @:selfCall
    public function new(x:Float, y:Float);
}
