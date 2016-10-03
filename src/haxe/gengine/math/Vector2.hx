package gengine.math;

@:native('Module.Vector2')
extern class Vector2Base
{
    public var x:Float;
    public var y:Float;

    @:selfCall
    public function new(x:Float, y:Float);
}

@:forward
abstract Vector2(Vector2Base) to Vector2Base from Vector2Base
{
    @:selfCall
    inline public function new(x:Float, y:Float)
    {
        this = new Vector2Base(x, y);
    }

    @:op(A * B)
    inline static public function mul(a:Vector2, b:Float)
    {
        return new Vector2(a.x * b, a.y * b);
    }

    @:op(A / B)
    inline static public function div(a:Vector2, b:Float)
    {
        return new Vector2(a.x / b, a.y / b);
    }

    @:op(A + B)
    inline static public function add(a:Vector2, b:Vector2)
    {
        return new Vector2(a.x + b.x, a.y + b.y);
    }

    @:op(A - B)
    inline static public function min(a:Vector2, b:Vector2)
    {
        return new Vector2(a.x - b.x, a.y - b.y);
    }
}
