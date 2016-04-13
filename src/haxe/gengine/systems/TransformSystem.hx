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
        trace('Transform node added!');
    }

    private function onTransformNodeRemoved(node:TransformNode):Void
    {

    }

}
