package gengine.systems;

import ash.core.Engine;
import ash.core.NodeList;
import ash.core.System;

import gengine.nodes.*;

class RenderSystem extends System
{
    private var staticSprite2DNodes:NodeList<StaticSprite2DNode>;

    public function new()
    {
        super();
    }

    override public function addToEngine(engine:Engine):Void
    {
        staticSprite2DNodes = engine.getNodeList(StaticSprite2DNode);
        staticSprite2DNodes.nodeAdded.add(onNodeAdded);
        staticSprite2DNodes.nodeRemoved.add(onNodeRemoved);
    }

    override public function removeFromEngine(engine:Engine):Void
    {
        staticSprite2DNodes = null;
    }

    private function onNodeAdded(node:StaticSprite2DNode):Void
    {
        trace('Render on node added!');
        var urhoNode = node.transform.node;
        var object = node.staticSprite2D.object;

        urhoNode.addComponent(object, 0, 0);

        untyped __js__("object.setSprite(gengineApp.getResourceCache().getSprite2D('Textures/Spot.png', true))");
    }

    private function onNodeRemoved(node:StaticSprite2DNode):Void
    {

    }
}
