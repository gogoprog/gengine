package gengine.components;

import gengine.math.*;

class Transform
{
    public var node:Dynamic;

    public function new(?position:Vector3)
    {
        untyped __js__("this.node = new Module.Node(gengineApp.getContext());");

        if(position != null)
        {
            node.setPosition(position);
        }
    }

    public var position(default, default):Vector3;

    public function set_position(position:Vector3):Vector3
    {
        untyped __js__("this.node.setPosition(position)");

        return position;
    }

    public function get_position():Vector3
    {
        untyped __js__("return this.node.getPosition()");

        return new Vector3(0, 0, 0);
    }

}
