package gengine;

import gengine.systems.*;
import gengine.components.RigidBody2D;
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

        engine.addSystem(new Physics2DSystem(), 1);
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

        var r = entity.get(RigidBody2D);
        if(r != null)
        {
            Physics2DSystem.addEntity(r.object, cast entity);
        }
    }

    static public function onEntityRemoved(entity:ash.core.Entity):Void
    {
        var scene = Gengine.getScene();

        untyped __js__("scene.removeChild(entity.node)");
    }

    static public function onGuiLoaded():Void
    {
        var app = Application;

        untyped __js__('if(typeof app.onGuiLoaded === "function") { app.onGuiLoaded(); }');
    }
}
