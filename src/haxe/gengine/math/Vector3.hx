package gengine.math;

@:native('Module.Vector3')
extern class Vector3Base
{
    public var x:Float;
    public var y:Float;
    public var z:Float;

    @:selfCall
    public function new(x:Float, y:Float, z:Float);
}


@:forward
abstract Vector3(Vector3Base) to Vector3Base from Vector3Base
{
    @:selfCall
    inline public function new(x:Float, y:Float, z:Float)
    {
        this = new Vector3Base(x, y, z);
    }

    @:op(A * B)
    inline static public function mul(a:Vector3, b:Float)
    {
        return new Vector3(a.x * b, a.y * b, a.z * b);
    }

    @:op(A / B)
    inline static public function div(a:Vector3, b:Float)
    {
        return new Vector3(a.x / b, a.y / b, a.z / b);
    }

    @:op(A + B)
    inline static public function add(a:Vector3, b:Vector3)
    {
        return new Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    @:op(A - B)
    inline static public function min(a:Vector3, b:Vector3)
    {
        return new Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
    }
}
