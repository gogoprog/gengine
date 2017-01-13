package gengine.components;

import gengine.math.*;

class TileMap2D extends UrhoComponent
{
    public inline function new()
    {
        super();

        untyped __js__("this.object = new Module.TileMap2D(gengine.getContext())");
        untyped __js__("window.dummyNode.addComponent(this.object, 0, 0);");
    }

    public inline function setTmxFile(tmxFile:Dynamic)
    {
        this.object.setTmxFile(tmxFile);
    }
}
