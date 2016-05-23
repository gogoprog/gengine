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

    public inline function setOrthoSize(size:Vector2)
    {
        this.object.setOrthoSize(size);
    }

    public inline function setOrthographic(orthographic:Bool)
    {
        this.object.setOrthographic(orthographic);
    }

    public function setNearClip(distance:Float)
    {
        this.object.setNearClip(distance);
    }

    public function setFarClip(distance:Float)
    {
        this.object.setFarClip(distance);
    }

    public function setFov(fov:Float)
    {
        this.object.setFov(fov);
    }

    public function setAspectRatio(ratio:Float)
    {
        this.object.setAspectRatio(ratio);
    }

    public function setAutoAspectRatio(autoAspectRatio:Bool)
    {
        this.object.setAutoAspectRatio(autoAspectRatio);
    }

    public function setZoom(zoom:Float)
    {
        this.object.setZoom(zoom);
    }

    public function worldToScreenPoint(worldPoint:Vector3):Vector2
    {
        return this.object.worldToScreenPoint(worldPoint);
    }

    public function screenToWorldPoint(screenPoint:Vector3):Vector3
    {
        return this.object.screenToWorldPoint(screenPoint);
    }
}
