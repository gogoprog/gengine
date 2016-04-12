package gengine.systems;

import ash.core.Engine;
import ash.core.NodeList;
import ash.core.System;

import gengine.nodes.*;

class RenderSystem extends System
{
    private var nodes:NodeList<StaticSprite2DNode>;

    public function new()
    {
        super();
    }

    override public function addToEngine(engine:Engine):Void
    {
        nodes = engine.getNodeList(StaticSprite2DNode);
        nodes.nodeAdded.add(onNodeAdded);
        nodes.nodeRemoved.add(onNodeRemoved);
    }

    override public function removeFromEngine(engine:Engine):Void
    {
        nodes = null;
    }

    private function onNodeAdded(node:StaticSprite2DNode):Void
    {
        trace('Render on node added!');
    }

    private function onNodeRemoved(node:StaticSprite2DNode):Void
    {

    }
}
