
console.log('Hello World');

var v = new Module.Vector3(16, 0, 0);
console.log(v.x);

var node = Module.Application.createNode();
v = node.getPosition();
console.log(v.x);
console.log(v.y);
console.log(v.z);

node.setPosition(Module.Vector3(4, 5, 6));

v = node.getPosition();
console.log(v.x);
console.log(v.y);
console.log(v.z);

var sprite = Module.Application.getSprite2D("Textures/Spot.png");
var static_sprite_2d = node.createComponentStaticSprite2D(0, 0);

static_sprite_2d.setSprite(sprite);

function update(dt)
{
    if(Module.Application.getInput().getMouseButtonPress(1))
    {
        var mousePosition = Module.Application.getInput().getMousePosition();

        console.log(mousePosition.x);
        console.log(mousePosition.y);

        console.log("timeStep " + dt);
    }
}
