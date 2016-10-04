package gengine.math;

@:native('Module.Maths')
extern class Maths
{
    static public function getVector2Length(v:Vector2):Float;
    static public function getVector3Length(v:Vector3):Float;
    static public function getVector2LengthSquared(v:Vector2):Float;
    static public function getVector3LengthSquared(v:Vector3):Float;
    static public function getNormalizedVector2(v:Vector2):Vector2;
    static public function getNormalizedVector3(v:Vector3):Vector3;
    static public function getVector2Angle(v:Vector2, v2:Vector2):Float;
    static public function getVector3Angle(v:Vector3, v2:Vector3):Float;
    static public function getVector2Distance(v:Vector2, v2:Vector2):Float;
    static public function getVector3Distance(v:Vector3, v2:Vector3):Float;
    static public function getVector2DistanceSquared(v:Vector2, v2:Vector2):Float;
    static public function getVector3DistanceSquared(v:Vector3, v2:Vector3):Float;
}
