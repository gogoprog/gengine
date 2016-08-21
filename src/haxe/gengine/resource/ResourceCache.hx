package gengine.resource;

import gengine.graphics.Sprite2D;

extern class ResourceCache
{
    public function getSprite2D(filename:String, ?sendEventOnFailure:Bool):Sprite2D;
    public function getAnimationSet2D(filename:String, ?sendEventOnFailure:Bool):Dynamic;
    public function getModel(filename:String, ?sendEventOnFailure:Bool):Dynamic;
    public function getMaterial(filename:String, ?sendEventOnFailure:Bool):Dynamic;
    public function getAnimation(filename:String, ?sendEventOnFailure:Bool):Dynamic;
    public function getSound(filename:String, ?sendEventOnFailure:Bool):Dynamic;
    public function getParticleEffect2D(filename:String, ?sendEventOnFailure:Bool):Dynamic;
}
