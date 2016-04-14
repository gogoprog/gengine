import ash.core.*;
import gengine.*;
import gengine.components.*;
import gengine.math.*;

class Application
{
    public static function init()
    {
        trace("Application.init()");

        Gengine.setWindowSize(new IntVector2(320, 200));
        Gengine.setWindowTitle("gengine test application");
    }

    public static function start(engine:Engine)
    {
        trace("Application.start()");

        var p = new Vector3(0, 0, 0);

        var gameEntity:Entity = new Entity();
        gameEntity.add(new Transform(p));

        var staticSprite2D = new StaticSprite2D(Gengine.getResourceCache().getSprite2D('Textures/Spot.png', true));
        staticSprite2D.setDrawRect(new Rect(new Vector2(-32, -32), new Vector2(32, 32)));
        gameEntity.add(staticSprite2D);

        engine.addEntity(gameEntity);
    }
}
