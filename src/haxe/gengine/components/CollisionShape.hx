package gengine.components;

import gengine.math.*;

class CollisionShape extends UrhoComponent
{
    public inline function new()
    {
        super();

        untyped __js__("this.object = new Module.CollisionShape(gengine.getContext())");
    }

    public inline function setBox(size:Vector3, ?position:Vector3, ?rotation:Quaternion)
    {
        this.object.setBox(size, untyped position || Vector3.ZERO, untyped rotation || Quaternion.IDENTITY);
    }

    public inline function setSphere(diameter:Float, ?position:Vector3, ?rotation:Quaternion)
    {
        this.object.setSphere(diameter, untyped position || Vector3.ZERO, untyped rotation || Quaternion.IDENTITY);
    }

    public inline function setStaticPlane(position:Vector3, ?rotation:Quaternion)
    {
        this.object.setStaticPlane( untyped position || Vector3.ZERO, untyped rotation || Quaternion.IDENTITY);
    }

    public inline function setCylinder(diameter:Float, height:Float, ?position:Vector3, ?rotation:Quaternion)
    {
        this.object.setCylinder(diameter, height, untyped position || Vector3.ZERO, untyped rotation || Quaternion.IDENTITY);
    }

    public inline function setCapsule(diameter:Float, height:Float, ?position:Vector3, ?rotation:Quaternion)
    {
        this.object.setCapsule(diameter, height, untyped position || Vector3.ZERO, untyped rotation || Quaternion.IDENTITY);
    }

    public inline function setCone(diameter:Float, height:Float, ?position:Vector3, ?rotation:Quaternion)
    {
        this.object.setCone(diameter, height, untyped position || Vector3.ZERO, untyped rotation || Quaternion.IDENTITY);
    }

    public inline function setTriangleMesh(model:Dynamic, lodLevel:Int = 0, ?scale:Vector3, ?position:Vector3, ?rotation:Quaternion)
    {
        this.object.setTriangleMesh(model, lodLevel, untyped scale || Vector3.ONE, untyped position || Vector3.ZERO, untyped rotation || Quaternion.IDENTITY);
    }

    public inline function setConvexHull(model:Dynamic, lodLevel:Int = 0, ?scale:Vector3, ?position:Vector3, ?rotation:Quaternion)
    {
        this.object.setConvexHull(model, lodLevel, untyped scale || Vector3.ONE, untyped position || Vector3.ZERO, untyped rotation || Quaternion.IDENTITY);
    }

    public inline function setTerrain(lodLevel:Int = 0)
    {
        this.object.setTerrain(lodLevel);
    }
}
