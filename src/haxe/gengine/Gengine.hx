package gengine;

import ash.core.Engine;
import ash.core.*;
import gengine.systems.*;
import gengine.math.*;
import gengine.input.*;

@:native('gengineApp')
extern class Gengine
{
    @:native('getScene')
    static public function getScene():Dynamic;

    @:native('getInput')
    static public function getInput():Input;

    @:native('getResourceCache')
    static public function getResourceCache():Dynamic;

    @:native('setWindowSize')
    static public function setWindowSize(size:IntVector2):Void;

    @:native('setWindowTitle')
    static public function setWindowTitle(title:String):Void;
}
