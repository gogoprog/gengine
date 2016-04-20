package gengine.math;

@:native('Module.Rect')
extern class Rect
{
    public var min:Vector2;
    public var max:Vector2;

    @:selfCall
    public function new(x:Vector2, y:Vector2);
}
