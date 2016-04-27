package gengine.graphics;

@:native('Module.AnimationState')
extern class AnimationState
{
    public function setLooped(looped:Bool):Void;
    public function setWeight(weight:Float):Void;
    public function setTime(time:Float):Void;
}
