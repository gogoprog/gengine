package gengine.math;

@:native('Module.Color')
extern class ColorBase
{
    public var r:Float;
    public var g:Float;
    public var b:Float;
    public var a:Float;

    @:selfCall
    public function new(r:Float, g:Float, b:Float, a:Float);
}

@:forward
abstract Color(ColorBase) to ColorBase from ColorBase
{
    @:selfCall
    inline public function new(r:Float, g:Float, b:Float, a:Float = 1.0)
    {
        this = new ColorBase(r, g, b, a);
    }

    @:op(A * B)
    inline static public function mul(a:Color, b:Float)
    {
        return new Color(a.r * b, a.g * b, a.b * b, a.a * b);
    }

    @:op(A / B)
    inline static public function div(a:Color, b:Float)
    {
        return new Color(a.r / b, a.g / b, a.b / b, a.a / b);
    }

    @:op(A + B)
    inline static public function add(a:Color, b:Color)
    {
        return new Color(a.r + b.r, a.g + b.g, a.b + b.b, a.a + b.a);
    }

    @:op(A - B)
    inline static public function min(a:Color, b:Color)
    {
        return new Color(a.r - b.r, a.g - b.g, a.b - b.b, a.a - b.a);
    }

    public static var BLACK = new Color(0, 0, 0, 1);
    public static var WHITE = new Color(1, 1, 1, 1);
}
