package gengine.components;

import gengine.math.*;

class Camera
{
    public var object:Dynamic;

    public function new()
    {
        untyped __js__("this.object = new Module.Camera(gengineApp.getContext())");
        untyped __js__("window.dummyNode.addComponent(this.object, 0, 0);");
    }

    public function setOrthoSize(size:Float)
    {
        untyped __js__("this.object.setOrthoSize(size)");
    }

    public function setOrthographic(orthographic:Bool)
    {
        untyped __js__("this.object.setOrthographic(orthographic)");
    }
}
