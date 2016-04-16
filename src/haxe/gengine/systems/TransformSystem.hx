package gengine.systems;

import ash.core.Engine;
import ash.core.NodeList;
import ash.core.System;

import gengine.nodes.*;

class TransformSystem extends System
{
    private var transformNodes:NodeList<TransformNode>;

    public function new()
    {
        super();
    }

    override public function addToEngine(engine:Engine):Void
    {
        transformNodes = engine.getNodeList(TransformNode);
        transformNodes.nodeAdded.add(onTransformNodeAdded);
        transformNodes.nodeRemoved.add(onTransformNodeRemoved);
    }

    override public function removeFromEngine(engine:Engine):Void
    {
        transformNodes = null;
    }

    private function onTransformNodeAdded(node:TransformNode):Void
    {
        var scene = Gengine.getScene();

        untyped __js__("scene.addChild(node.transform.node, 1000)");
    }

    private function onTransformNodeRemoved(node:TransformNode):Void
    {

    }

}
