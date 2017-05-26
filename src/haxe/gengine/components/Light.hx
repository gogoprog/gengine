package gengine.components;

import gengine.math.*;

@:native('Module.BiasParameters')
extern class BiasParameters
{
    @:selfCall
    public function new(constantBias:Float, slopeScaledBias:Float, normalOffset:Float);
}

@:native('Module.CascadeParameters')
extern class CascadeParameters
{
    @:selfCall
    public function new(split1:Float, split2:Float, split3:Float, split4:Float, fadeStart:Float, biasAutoAdjust:Float);
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

    public inline function setShadowCascade(cascadeParameters:CascadeParameters)
    {
        this.object.setShadowCascade(cascadeParameters);
    }

    public inline function setSpecularIntensity(intensity:Float)
    {
        this.object.setSpecularIntensity(intensity);
    }
}
