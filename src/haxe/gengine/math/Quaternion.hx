package gengine.math;

@:native('Module.Quaternion')
extern class QuaternionBase
{
    public var w:Float;
    public var x:Float;
    public var y:Float;
    public var z:Float;

    @:selfCall
    public function new(w:Float, x:Float, y:Float, z:Float);
}

@:forward
abstract Quaternion(QuaternionBase) to QuaternionBase from QuaternionBase
{
    @:selfCall
    inline public function new(w:Float, x:Float, y:Float, z:Float)
    {
        this = new QuaternionBase(w, x, y, z);
    }

    public static var IDENTITY = new Quaternion(1.0, 0.0, 0.0, 0.0);
}
