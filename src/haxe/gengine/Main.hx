package gengine;

import ash.core.Engine;
import ash.core.*;
import gengine.systems.*;

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

        engine.addSystem(new TransformSystem(), 0);
        engine.addSystem(new RenderSystem(), 1);

        untyped __js__("window.dummyNode = gengineApp.getScene().createChild(0, 0);");
        untyped __js__("window.dummyNode.setEnabled(false)");

        Application.start(engine);
    }

    static public function update(dt:Float)
    {
        engine.update(dt);
    }
}
