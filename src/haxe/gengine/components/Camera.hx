package gengine.components;

import gengine.math.*;

class Camera extends UrhoComponent
{
    public inline function new()
    {
        super();
        untyped __js__("this.object = new Module.Camera(gengine.getContext())");
        untyped __js__("window.dummyNode.addComponent(this.object, 0, 0);");
    }

    public inline function getCamera():Dynamic
    {
        return object;
    }

    public inline function setOrthoSize(size:Vector2)
    {
        untyped __js__("this.object.setOrthoSize(size)");
    }

    public inline function setOrthographic(orthographic:Bool)
    {
        untyped __js__("this.object.setOrthographic(orthographic)");
    }
}
