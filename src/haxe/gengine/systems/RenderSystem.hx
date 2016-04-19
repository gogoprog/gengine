package gengine.systems;

import ash.core.Engine;
import ash.core.NodeList;
import ash.core.System;

import gengine.nodes.*;

class RenderSystem extends System
{
    public function new()
    {
        super();
    }

    override public function addToEngine(engine:Engine):Void
    {
        engine.getNodeList(StaticSprite2DNode).nodeAdded.add(onNodeAdded);
        engine.getNodeList(StaticSprite2DNode).nodeRemoved.add(onNodeRemoved);
        engine.getNodeList(AnimatedSprite2DNode).nodeAdded.add(onNodeAdded);
        engine.getNodeList(AnimatedSprite2DNode).nodeRemoved.add(onNodeRemoved);
    }

    override public function removeFromEngine(engine:Engine):Void
    {
    }

    private function onNodeAdded(node:Dynamic):Void
    {
        var urhoNode = node.transform.node;
        var object = node.component.object;

        urhoNode.addComponent(object, 0, 0);
    }

    private function onNodeRemoved(node:Dynamic):Void
    {
        var object = node.component.object;

        object.remove();
    }
}
