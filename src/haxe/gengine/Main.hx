package gengine;

import ash.core.Engine;
import ash.core.*;
import gengine.systems.RenderSystem;

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

        engine.addSystem(new RenderSystem(), 0);

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
}
