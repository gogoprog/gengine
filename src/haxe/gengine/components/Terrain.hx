package gengine.components;

import gengine.math.*;
import gengine.graphics.*;

class Terrain extends UrhoComponent
{
    public inline function new()
    {
        super();

        untyped __js__("this.object = new Module.Terrain(gengine.getContext())");
        untyped __js__("window.dummyNode.addComponent(this.object, 0, 0);");
    }

    public inline function setPatchSize(size:Int)
    {
        this.object.setPatchSize(size);
    }

    public inline function setSpacing(spacing:Vector3)
    {
        this.object.setSpacing(spacing);
    }

    public inline function setSmoothing(smoothing:Bool)
    {
        this.object.setSmoothing(smoothing);
    }

    public inline function setHeightMap(heightMap:Dynamic)
    {
        this.object.setHeightMap(heightMap);
    }

    public inline function setMaterial(material:Dynamic)
    {
        this.object.setMaterial(material);
    }

    public inline function setOccluder(occluder:Bool)
    {
        this.object.setOccluder(occluder);
    }

    public inline function setCastShadows(castShadows:Bool)
    {
        this.object.setCastShadows(castShadows);
    }

    public inline function getHeight(worldPosition:Vector3):Float
    {
        return this.object.getHeight(worldPosition);
    }
}
