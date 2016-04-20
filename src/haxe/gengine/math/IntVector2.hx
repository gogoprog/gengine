package gengine.math;

@:native('Module.IntVector2')
extern class IntVector2
{
    public var x:Int;
    public var y:Int;

    @:selfCall
    public function new(x:Int, y:Int);
}
