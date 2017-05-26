package gengine.components;

import gengine.math.*;

@:native('Module.BiasParameters')
extern class BiasParameters
{
    public var constantBias:Float;
    public var slopeScaledBias:Float;
    public var normalOffset:Float;

    @:selfCall
    public function new(constantBias:Float, slopeScaledBias:Float, normalOffset:Float);
}

class Light extends UrhoComponent
{
    public function new()
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

    public inline function setShadowBias(biasParameters:BiasParameters)
    {
        this.object.setShadowBias(biasParameters);
    }
}
