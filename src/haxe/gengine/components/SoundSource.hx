package gengine.components;

import gengine.math.*;

class SoundSource extends UrhoComponent
{
    public inline function new()
    {
        super();

        untyped __js__("this.object = new Module.SoundSource(gengine.getContext())");
        untyped __js__("window.dummyNode.addComponent(this.object, 0, 0);");
    }

    public inline function play(sound:Dynamic)
    {
        this.object.play(sound);
    }

    public inline function play2(sound:Dynamic, frequency:Float, gain:Float, panning:Float)
    {
        this.object.play2(sound, frequency, gain, panning);
    }

    public inline function stop()
    {
        this.object.stop();
    }

    public inline function setSoundType(type:String)
    {
        this.object.setSoundType(type);
    }

    public inline function setFrequency(frequency:Float)
    {
        this.object.setFrequency(frequency);
    }

    public inline function setGain(gain:Float)
    {
        this.object.setGain(gain);
    }

    public inline function setAttenuation(attenuation:Float)
    {
        this.object.setAttenuation(attenuation);
    }

    public inline function setPanning(pannning:Float)
    {
        this.object.setPanning(pannning);
    }

    public inline function isPlaying()
    {
        return this.object.isPlaying();
    }
}
