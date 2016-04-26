package gengine.components;

import gengine.math.*;

class Light extends UrhoComponent
{
    public inline function new()
    {
        super();

        untyped __js__("this.object = new Module.Light(gengineApp.getContext())");
        untyped __js__("window.dummyNode.addComponent(this.object, 0, 0);");
    }

    public inline function setLightType(type:Int)
    {
        untyped __js__("this.object.setLightType(type)");
    }
}
