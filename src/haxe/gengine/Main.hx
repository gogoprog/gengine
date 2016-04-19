package gengine;

import ash.core.*;
import gengine.systems.*;
import gengine.*;

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

        untyped __js__("window.dummyNode = gengineApp.getScene().createChild(0, 0);");
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
}
