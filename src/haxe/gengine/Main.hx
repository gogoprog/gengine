package gengine;

import ash.core.Engine;

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
        Application.start();
    }

    static public function update(dt:Float)
    {
        engine.update(dt);
        Application.update(dt);
    }
}
