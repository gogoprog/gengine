package gengine.components;

import gengine.math.*;

class ParticleEmitter2D extends UrhoComponent
{
    public function new()
    {
        super();

        untyped __js__("this.object = new Module.ParticleEmitter2D(gengine.getContext())");
        untyped __js__("window.dummyNode.addComponent(this.object, 0, 0);");
    }

    public inline function setEffect(effect:Dynamic)
    {
        this.object.setEffect(effect);
    }

    public inline function setSprite(sprite:Dynamic)
    {
        this.object.setSprite(sprite);
    }

    public inline function setBlendMode(blendMode:Int)
    {
        this.object.setBlendMode(blendMode);
    }

    public inline function setMaxParticles(max:Int)
    {
        this.object.setMaxParticles(max);
    }

    public inline function setLayer(layer:Int)
    {
        this.object.setLayer(layer);
    }

    public inline function getLayer():Int
    {
        return this.object.getLayer();
    }

    public inline function setOrderInLayer(order:Int)
    {
        this.object.setOrderInLayer(order);
    }

    public inline function getOrderInLayer():Int
    {
        return this.object.getOrderInLayer();
    }
}
