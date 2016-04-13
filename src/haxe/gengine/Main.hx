package gengine;

import ash.core.Engine;
import ash.core.*;
import gengine.systems.*;

@:expose
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

        Application.start();
    }

    static public function update(dt:Float)
    {
        engine.update(dt);
    }

    static public function getEngine():Engine
    {
        return engine;
    }

    static public function getContext():Dynamic
    {
        untyped __js__("return gengine.getContext()");
        return 0;
    }
}
