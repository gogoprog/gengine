package gengine.systems;

import ash.core.Engine;
import ash.core.NodeList;
import ash.core.System;

import gengine.nodes.*;

class RenderSystem extends System
{
    private var staticSprite2DNodes:NodeList<StaticSprite2DNode>;
    private var animatedSprite2DNodes:NodeList<AnimatedSprite2DNode>;

    public function new()
    {
        super();
    }

    override public function addToEngine(engine:Engine):Void
    {
        staticSprite2DNodes = engine.getNodeList(StaticSprite2DNode);
        staticSprite2DNodes.nodeAdded.add(onNodeAdded);
        staticSprite2DNodes.nodeRemoved.add(onNodeRemoved);
        animatedSprite2DNodes = engine.getNodeList(AnimatedSprite2DNode);
        animatedSprite2DNodes.nodeAdded.add(onNodeAdded);
        animatedSprite2DNodes.nodeRemoved.add(onNodeRemoved);
    }

    override public function removeFromEngine(engine:Engine):Void
    {
        staticSprite2DNodes = null;
        animatedSprite2DNodes = null;
    }

    private function onNodeAdded(node:Dynamic):Void
    {
        trace('Render on node added!');
        var urhoNode = node.transform.node;
        var object = node.component.object;

        urhoNode.addComponent(object, 0, 0);
    }

    private function onNodeRemoved(node:Dynamic):Void
    {

    }
}
