package gengine.components;

import gengine.math.*;

class Transform
{
    public var node:Dynamic;
    public var position(get, set):Vector3;
    public var scale(get, set):Vector3;

    public function new(?position:Vector3)
    {
        untyped __js__("this.node = new Module.Node(gengineApp.getContext());");

        if(position != null)
        {
            node.setPosition(position);
        }
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

    private function set_scale(scale:Vector3):Vector3
    {
        untyped __js__("this.node.setScale(scale)");

        return scale;
    }

    private function get_scale():Vector3
    {
        return untyped __js__("this.node.getScale()");
    }

    public function setPosition(position:Vector3):Vector3
    {
        untyped __js__("this.node.setPosition(position)");

        return position;
    }

    public function getPosition():Vector3
    {
        return untyped __js__("this.node.getPosition()");
    }

    public function setScale(scale:Vector3):Vector3
    {
        untyped __js__("this.node.setScale(scale)");

        return scale;
    }

    public function getScale():Vector3
    {
        return untyped __js__("this.node.getScale()");
    }

    public function setRotation2D(angle:Float)
    {
        untyped __js__("this.object.setRotation2D(angle)");
    }
}
