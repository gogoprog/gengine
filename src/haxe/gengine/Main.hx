package gengine;

import gengine.systems.*;
import gengine.*;

@:dox(hide)
class Main
{
    private static var engine:Engine;

    static public function main()
    {
        untyped __js__("window.Main = gengine_Main;");
    }

    static public function init()
    {
        Application.init();
    }

    static public function start()
    {
        engine = new Engine();

        engine.entityAdded.add(onEntityAdded);
        engine.entityRemoved.add(onEntityRemoved);

        untyped __js__("window.dummyNode = gengine.getScene().createChild(0, 0);");
        untyped __js__("window.dummyNode.setEnabled(false)");

        Application.start(engine);
    }

    static public function update(dt:Float)
    {
        engine.update(dt);
    }

    static public function onEntityAdded(entity:ash.core.Entity):Void
    {
        var scene = Gengine.getScene();

        untyped __js__("scene.addChild(entity.node, 1000)");
    }

    static public function onEntityRemoved(entity:ash.core.Entity):Void
    {
        var scene = Gengine.getScene();

        untyped __js__("scene.removeChild(entity.node)");
    }
}
