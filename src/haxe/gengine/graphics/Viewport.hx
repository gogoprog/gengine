package gengine.graphics;

@:native('Module.Viewport')
extern class Color
{
    public function new(context:Dynamic);
    public function setScene(scene:Dynamic):Void;
    public function setCamera(camera:Dynamic):Void
}
