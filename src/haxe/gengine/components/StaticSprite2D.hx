package gengine.components;

import gengine.math.*;

class StaticSprite2D
{
    public var object:Dynamic;

    public function new(?sprite)
    {
        untyped __js__("this.object = new Module.StaticSprite2D(gengineApp.getContext())");
        untyped __js__("window.dummyNode.addComponent(this.object, 0, 0);");

        if(sprite != null)
        {
            setSprite(sprite);
        }
    }

    public function setSprite(sprite:Dynamic)
    {
        untyped __js__("this.object.setSprite(sprite)");
    }

    public function setDrawRect(rect:Rect)
    {
        untyped __js__("this.object.setDrawRect(rect)");
    }

    public function setTextureRect(rect:Rect)
    {
        untyped __js__("this.object.setTextureRect(rect)");
    }

    public function setLayer(layer:Int)
    {
        untyped __js__("this.object.setLayer(layer)");
    }

    public function getLayer():Int
    {
        return untyped __js__("this.object.getLayer()");
    }
}
