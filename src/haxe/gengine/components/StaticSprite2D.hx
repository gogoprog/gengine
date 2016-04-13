package gengine.components;

class StaticSprite2D
{
    public var object:Dynamic;

    public function new()
    {
        untyped __js__("this.object = new Module.StaticSprite2D(gengineApp.getContext());");
    }

    public function setSprite(sprite:Dynamic)
    {
        untyped __js__("this.object.setSprite(sprite)");
    }
}
