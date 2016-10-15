package gengine.systems;

import ash.tools.ListIteratingSystem;
import gengine.nodes.*;
import haxe.ds.ObjectMap;

class Physics2DSystem extends ListIteratingSystem<Physics2DNode>
{
    static public var urhoBodyToEntity = new Map<Int, Entity>();

    public function new()
    {
        super(Physics2DNode, null, null, onNodeRemoved);
    }

    private function onNodeRemoved(node:Physics2DNode)
    {
        urhoBodyToEntity.remove(node.body.object.getID());
    }

    static public function addEntity(urhoBody:Dynamic, entity:Entity)
    {
        urhoBodyToEntity.set(urhoBody.getID(), entity);
    }

    static public inline function getEntity(urhoBody:Dynamic):Entity
    {
        return urhoBody == null ? null : urhoBodyToEntity.get(urhoBody.getID());
    }
}
