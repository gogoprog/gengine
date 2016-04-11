
var application = {};

application.init = function()
{
    console.log('application.init');
    gengine.setWindowSize(Module.IntVector2(320, 240));
    gengine.setWindowTitle("Test application");
};

var node;
var total = 0;
application.start = function()
{
    console.log('application.start');

    node = gengine.getScene().createChild(0, 0);

    var sprite = gengine.getResourceCache().getSprite2D("Textures/Spot.png", true);
    var static_sprite_2d = node.createComponentStaticSprite2D(0, 0);

    static_sprite_2d.setSprite(sprite);
};

application.update = function(dt)
{
    total += dt;
    if(gengine.getInput().getMouseButtonDown(1))
    {
        var mousePosition = gengine.getInput().getMousePosition();

        console.log(mousePosition.x);
        console.log(mousePosition.y);

        console.log("timeStep " + dt);
    }

    node.setPosition(Module.Vector3(100 * Math.sin(total),0 ,0));
};
