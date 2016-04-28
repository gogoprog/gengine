package gengine.resource;

extern class ResourceCache
{
    public function getSprite2D(filename:String, ?sendEventOnFailure:Bool):Dynamic;
    public function getAnimationSet2D(filename:String, ?sendEventOnFailure:Bool):Dynamic;
    public function getModel(filename:String, ?sendEventOnFailure:Bool):Dynamic;
    public function getMaterial(filename:String, ?sendEventOnFailure:Bool):Dynamic;
    public function getAnimation(filename:String, ?sendEventOnFailure:Bool):Dynamic;
}
