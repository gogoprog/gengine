package gengine.components;

import gengine.math.*;

class Light extends UrhoComponent
{
    public inline function new()
    {
        super();

        untyped __js__("this.object = new Module.Light(gengine.getContext())");
        untyped __js__("window.dummyNode.addComponent(this.object, 0, 0);");
    }

    public inline function setLightType(type:Int)
    {
        this.object.setLightType(type);
    }

    public inline function setColor(color:Color)
    {
        this.object.setColor(color);
    }

    public inline function setCastShadows(castShadows:Bool)
    {
        this.object.setCastShadows(castShadows);
    }
}
