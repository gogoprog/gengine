package gengine.components;

class Transform
{
    public var node:Dynamic;

    public function new()
    {
        untyped __js__("this.node = new Module.Node(gengine.getContext());");
    }
}
