package gengine;

import ash.core.Engine;

class Main
{
    private static var engine:Engine;

    static public function main()
    {
    }

    static public function init()
    {
        engine = new Engine();
    }

    static public function update(dt:Float)
    {
        engine.update(dt);
    }

}
