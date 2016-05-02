package gengine;

import gengine.components.UrhoComponent;
import gengine.math.*;

class Entity extends ash.core.Entity
{
    private var node:Dynamic;
    private var internalParent:Entity;

    public var position(get, set):Vector3;
    public var scale(get, set):Vector3;
    public var parent(get, set):Entity;

    public function new(?node:Dynamic)
    {
        super();

        if(node == null)
        {
            untyped __js__("this.node = new Module.Node(gengine.getContext());");
        }
        else
        {
            untyped __js__("this.node = node;");
        }
    }

    override public function add<T>(component:T, componentClass:Class<Dynamic> = null):ash.core.Entity
    {
        if(Std.is(component, UrhoComponent))
        {
            untyped __js__("this.node.addComponent(component.object, 0, 0)");
        }

        return super.add(component, componentClass);
    }

    override public function remove<T>(componentClass:Class<Dynamic>):T
    {
        var component = super.remove(componentClass);

        if(component != null && Std.is(component, UrhoComponent))
        {
            untyped __js__("this.node.removeComponent(component.object)");
        }

        return component;
    }

    private function set_position(position:Vector3):Vector3
    {
        untyped __js__("this.node.setPosition(position)");

        return position;
    }

    private function get_position():Vector3
    {
        return untyped __js__("this.node.getPosition()");
    }

    private inline function set_scale(scale:Vector3):Vector3
    {
        untyped __js__("this.node.setScale(scale)");

        return scale;
    }

    private inline function get_scale():Vector3
    {
        return untyped __js__("this.node.getScale()");
    }

    public function setPosition(position:Vector3):Vector3
    {
        untyped __js__("this.node.setPosition(position)");

        return position;
    }

    public inline function getPosition():Vector3
    {
        return untyped __js__("this.node.getPosition()");
    }

    public inline function setScale(scale:Vector3):Vector3
    {
        untyped __js__("this.node.setScale(scale)");

        return scale;
    }

    public inline function getScale():Vector3
    {
        return untyped __js__("this.node.getScale()");
    }

    public inline function setRotation2D(angle:Float)
    {
        untyped __js__("this.node.setRotation2D(angle)");
    }

    public inline function getRotation2D():Float
    {
        return untyped __js__("this.node.getRotation2D()");
    }

    public inline function setDirection(direction:Vector3)
    {
        untyped __js__("this.node.setDirection(direction)");
    }

    public inline function getDirection():Vector3
    {
        return untyped __js__("this.node.getDirection()");
    }

    public inline function getUp():Vector3
    {
        return untyped __js__("this.node.getUp()");
    }

    public inline function getRight():Vector3
    {
        return untyped __js__("this.node.getRight()");
    }

    public inline function setWorldPosition(position:Vector3)
    {
        untyped __js__("this.node.setWorldPosition(position)");
    }

    public inline function getWorldPosition():Vector3
    {
        return untyped __js__("this.node.getWorldPosition()");
    }

    public inline function setWorldScale(scale:Vector3)
    {
        untyped __js__("this.node.setWorldScale(scale)");
    }

    public inline function getWorldScale():Vector3
    {
        return untyped __js__("this.node.getWorldScale()");
    }

    public inline function setParent(parent:Entity)
    {
        untyped __js__("this.node.setParent(parent.node)");
        internalParent = parent;
    }

    public inline function getParent():Entity
    {
        return internalParent;
    }

    public inline function set_parent(parent:Entity):Entity
    {
        setParent(parent);
        return parent;
    }

    public inline function get_parent():Entity
    {
        return internalParent;
    }

    public function roll(angle:Float, ?transformSpace:Int = 0)
    {
        untyped __js__("this.node.roll(angle, transformSpace)");
    }

    public function yaw(angle:Float, ?transformSpace:Int = 0)
    {
        untyped __js__("this.node.yaw(angle, transformSpace)");
    }

    public function pitch(angle:Float, ?transformSpace:Int = 0)
    {
        untyped __js__("this.node.pitch(angle, transformSpace)");
    }

    public function lookAt(position:Vector3, ?upVector = null, ?transformSpace:Int = 2)
    {
        untyped __js__("this.node.lookAt(position, upVector || Module.Vector3(0, 1, 0), transformSpace)");
    }
}
