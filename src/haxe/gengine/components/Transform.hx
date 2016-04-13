package gengine.components;

import gengine.math.*;

class Transform
{
    public var node:Dynamic;

    public function new(?position:Vector3)
    {
        untyped __js__("this.node = new Module.Node(gengine.getContext());");

        if(position != null)
        {
            node.setPosition(position);
        }
    }

}
