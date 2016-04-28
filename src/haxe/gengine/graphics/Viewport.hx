package gengine.graphics;

import gengine.core.Context;
import gengine.scene.Scene;
import gengine.components.Camera;

@:native('Module.Viewport')
extern class Viewport
{
    public function new(context:Context);
    public function setScene(scene:Scene):Void;

    public inline function setCamera(camera:Camera):Void
    {
        this.setCamera(camera.object);
    }
}
