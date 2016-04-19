import gengine.*;
import gengine.components.*;
import gengine.math.*;

class GameSystem extends System
{
    public function new()
    {
        super();
    }

    override public function update(dt:Float):Void
    {
        if(Gengine.getInput().getScancodePress(41))
        {
            trace('Escaped just pressed.');
            Gengine.exit();
        }

        if(Gengine.getInput().getMouseButtonDown(1))
        {
            var p = Gengine.getInput().getMousePosition();
            trace('Mouse position : ' + p.x + ', ' + p.y);
        }
    }
}

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

        engine.addSystem(new GameSystem(), 2);

        var p = new Vector3(0, 0, 0);

        var gameEntity:Entity = new Entity();
        gameEntity.add(new Transform(p));

        var staticSprite2D = new StaticSprite2D(Gengine.getResourceCache().getSprite2D('Textures/Spot.png', true));
        staticSprite2D.setDrawRect(new Rect(new Vector2(-32, -32), new Vector2(32, 32)));
        gameEntity.add(staticSprite2D);

        var transform:Transform = gameEntity.get(Transform);
        transform.scale = new Vector3(0.5, 0.5, 0.5);
        transform.position.x = 100;
        engine.addEntity(gameEntity);
    }
}
