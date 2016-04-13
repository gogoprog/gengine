import ash.core.*;
import gengine.*;
import gengine.components.*;
import gengine.math.*;

class Application
{
    public static function init()
    {
        trace("Application.init()");
    }

    public static function start()
    {
        trace("Application.start()");

        var p = new Vector3(0, 0, 0);
        p.x = 128;

        var gameEntity:Entity = new Entity();
        gameEntity.add(new Transform(p));
        gameEntity.add(new StaticSprite2D());
        Main.getEngine().addEntity(gameEntity);
    }
}
