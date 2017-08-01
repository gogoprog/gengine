package gengine.resource;

import gengine.graphics.*;
import gengine.audio.*;

extern class ResourceCache
{
    public function getSprite2D(filename:String, ?sendEventOnFailure:Bool):Sprite2D;
    public function getAnimationSet2D(filename:String, ?sendEventOnFailure:Bool):AnimationSet2D;
    public function getModel(filename:String, ?sendEventOnFailure:Bool):Model;
    public function getMaterial(filename:String, ?sendEventOnFailure:Bool):Material;
    public function getAnimation(filename:String, ?sendEventOnFailure:Bool):Animation;
    public function getSound(filename:String, ?sendEventOnFailure:Bool):Sound;
    public function getParticleEffect2D(filename:String, ?sendEventOnFailure:Bool):ParticleEffect2D;
    public function getTmxFile2D(filename:String, ?sendEventOnFailure:Bool):TmxFile2D;
    public function getImage(filename:String, ?sendEventOnFailure:Bool):Image;
}
