package gengine;

import gengine.components.UrhoComponent;
import gengine.math.*;

class Entity extends ash.core.Entity
{
    private var node:Dynamic;
    private var _parent:Entity;
    private var _children = new Array<Entity>();

    public var position(get, set):Vector3;
    public var scale(get, set):Vector3;
    public var parent(get, set):Entity;

    public function new(?node:Dynamic)
    {
        super();

        if(node == null)
        {
            untyped __js__("this.node = new Module.Node(gengine.getContext()); this.node.addRef();");
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
            this.node.addComponent(cast(component, UrhoComponent).object, 0, 0);
        }

        return super.add(component, componentClass);
    }

    override public function remove<T>(componentClass:Class<Dynamic>):T
    {
        var component = super.remove(componentClass);

        if(component != null && Std.is(component, UrhoComponent))
        {
            this.node.removeComponent(cast(component, UrhoComponent).object);
        }

        return component;
    }

    private function set_position(position:Vector3):Vector3
    {
        this.node.setPosition(position);

        return position;
    }

    private function get_position():Vector3
    {
        return this.node.getPosition();
    }

    private inline function set_scale(scale:Vector3):Vector3
    {
        this.node.setScale(scale);

        return scale;
    }

    private inline function get_scale():Vector3
    {
        return this.node.getScale();
    }

    public function setPosition(position:Vector3):Vector3
    {
        this.node.setPosition(position);

        return position;
    }

    public inline function getPosition():Vector3
    {
        return this.node.getPosition();
    }

    public inline function setScale(scale:Vector3):Vector3
    {
        this.node.setScale(scale);

        return scale;
    }

    public inline function getScale():Vector3
    {
        return this.node.getScale();
    }

    public inline function setRotation2D(angle:Float)
    {
        this.node.setRotation2D(angle);
    }

    public inline function getRotation2D():Float
    {
        return this.node.getRotation2D();
    }

    public inline function setDirection(direction:Vector3)
    {
        this.node.setDirection(direction);
    }

    public inline function getDirection():Vector3
    {
        return this.node.getDirection();
    }

    public inline function getUp():Vector3
    {
        return this.node.getUp();
    }

    public inline function getRight():Vector3
    {
        return this.node.getRight();
    }

    public inline function setWorldPosition(position:Vector3)
    {
        this.node.setWorldPosition(position);
    }

    public inline function getWorldPosition():Vector3
    {
        return this.node.getWorldPosition();
    }

    public inline function setWorldRotation2D(angle:Float)
    {
        this.node.setWorldRotation2D(angle);
    }

    public inline function getWorldRotation2D():Float
    {
        return this.node.getWorldRotation2D();
    }

    public inline function setWorldScale(scale:Vector3)
    {
        this.node.setWorldScale(scale);
    }

    public inline function getWorldScale():Vector3
    {
        return this.node.getWorldScale();
    }

    public inline function setParent(parent:Entity)
    {
        if(_parent != null)
        {
            _parent._children.remove(this);
        }

        if(parent != null)
        {
            parent._children.push(this);
            this.node.setParent(parent.node);
            _parent = parent;
        }
        else
        {
            this.node.setParent(null);
            _parent = null;
        }
    }

    public inline function getParent():Entity
    {
        return _parent;
    }

    public inline function set_parent(parent:Entity):Entity
    {
        setParent(parent);
        return parent;
    }

    public inline function get_parent():Entity
    {
        return _parent;
    }

    public inline function roll(angle:Float, ?transformSpace:Int = 0)
    {
        this.node.roll(angle, transformSpace);
    }

    public inline function yaw(angle:Float, ?transformSpace:Int = 0)
    {
        this.node.yaw(angle, transformSpace);
    }

    public inline function pitch(angle:Float, ?transformSpace:Int = 0)
    {
        this.node.pitch(angle, transformSpace);
    }

    public inline function lookAt(position:Vector3, ?upVector = null, ?transformSpace:Int = 2)
    {
        if(upVector == null)
        {
            upVector = new Vector3(0, 1, 0);
        }

        this.node.lookAt(position, upVector, transformSpace);
    }
}
