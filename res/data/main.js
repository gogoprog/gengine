var node = application.createNode();

var sprite = application.getSprite2D("Textures/Spot.png");
var static_sprite_2d = node.createComponentStaticSprite2D(0, 0);

static_sprite_2d.setSprite(sprite);

function update(dt)
{
    if(application.getInput().getMouseButtonDown(1))
    {
        var mousePosition = application.getInput().getMousePosition();

        console.log(mousePosition.x);
        console.log(mousePosition.y);

        console.log("timeStep " + dt);
    }
}
