package gengine.input;

import gengine.math.*;

extern class Input
{
    public function getKeyPress(button:Int):Bool;
    public function getKeyDown(button:Int):Bool;
    public function getScancodePress(button:Int):Bool;
    public function getScancodeDown(button:Int):Bool;
    public function getMouseButtonPress(button:Int):Bool;
    public function getMouseButtonDown(button:Int):Bool;
    public function getMousePosition():IntVector2;
    public function getMouseMove():IntVector2;
    public function getMouseMoveWheel():Int;
}
