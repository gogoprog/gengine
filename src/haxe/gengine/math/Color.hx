package gengine.math;

@:native('Module.Color')
extern class Color
{
    public var r:Float;
    public var g:Float;
    public var b:Float;
    public var a:Float;

    @:selfCall
    public function new(r:Float, g:Float, b:Float, a:Float);
}
