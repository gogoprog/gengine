import gengine.*;
import gengine.components.*;
import gengine.math.*;
import gengine.graphics.*;

class SoundNode extends Node<SoundNode>
{
    public var source:SoundSource;
}

class GameSystem extends System
{
    private var soundNode:SoundNode;

    public function new()
    {
        super();
    }

    override public function addToEngine(engine:Engine)
    {
        engine.getNodeList(SoundNode).nodeAdded.add(onSoundNodeAdded);
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

        if(Gengine.getInput().getMouseButtonPress(1))
        {
            soundNode.source.play(Gengine.getResourceCache().getSound("sound.ogg", true));
        }
    }

    public function onSoundNodeAdded(node:SoundNode)
    {
        soundNode = node;
        soundNode.source.setGain(0.3);
    }
}

class Application
{
    public static function init()
    {
        trace("Application.init()");

        Gengine.setWindowSize(new IntVector2(800, 600));
        Gengine.setWindowTitle("gengine test application");
        Gengine.setGuiFilename("gui/gui.html");
    }

    public static function start(engine:Engine)
    {
        trace("Application.start()");

        engine.addSystem(new GameSystem(), 2);

        var e:Entity = new Entity();

        var staticSprite2D = new StaticSprite2D(Gengine.getResourceCache().getSprite2D('Textures/Spot.png', true));
        staticSprite2D.setDrawRect(new Rect(new Vector2(-32, -32), new Vector2(32, 32)));

        e.add(staticSprite2D);

        engine.addEntity(e);

        e = new Entity();
        e.add(new Camera());
        e.get(Camera).setOrthoSize(new Vector2(64, 64));
        e.get(Camera).setOrthographic(true);
        engine.addEntity(e);

        var viewport:Viewport = new Viewport(Gengine.getContext());
        viewport.setScene(Gengine.getScene());
        viewport.setCamera(e.get(Camera));
        Gengine.getRenderer().setViewport(0, viewport);

        e = new Entity();
        e.add(new SoundSource());
        engine.addEntity(e);
    }
}
