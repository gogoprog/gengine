package gengine.graphics;

@:native('Module.BiasParameters')
extern class BiasParameters
{
    public function new(constantBias:Float, slopeScaledBias:Float, normalOffset:Float);
}