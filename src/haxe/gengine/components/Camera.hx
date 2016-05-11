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

    public function setOrthoSize(size:Vector2)
    {
        untyped __js__("this.object.setOrthoSize(size)");
    }

    public function setOrthographic(orthographic:Bool)
    {
        untyped __js__("this.object.setOrthographic(orthographic)");
    }

    public function setNearClip(distance:Float)
    {
        untyped __js__("this.object.setNearClip(distance)");
    }

    public function setFarClip(distance:Float)
    {
        untyped __js__("this.object.setFarClip(distance)");
    }

    public function setFov(fov:Float)
    {
        untyped __js__("this.object.setFov(fov)");
    }

    public function setAspectRatio(ratio:Float)
    {
        untyped __js__("this.object.setAspectRatio(ratio)");
    }

    public function setAutoAspectRatio(autoAspectRatio:Bool)
    {
        untyped __js__("this.object.setAutoAspectRatio(autoAspectRatio)");
    }

    public function setZoom(zoom:Float)
    {
        untyped __js__("this.object.setZoom(zoom)");
    }

    public function worldToScreenPoint(worldPoint:Vector3):Vector2
    {
        return untyped __js__("this.object.worldToScreenPoint(worldPoint)");
    }

    public function screenToWorldPoint(screenPoint:Vector3):Vector3
    {
        return untyped __js__("this.object.screenToWorldPoint(screenPoint)");
    }
}
