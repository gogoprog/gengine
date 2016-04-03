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
