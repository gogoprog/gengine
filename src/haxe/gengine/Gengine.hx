package gengine;

import ash.core.Engine;
import ash.core.*;
import gengine.systems.*;
import gengine.math.*;


@:native('gengineApp')
extern class Gengine
{
    @:native('getScene')
    static public function getScene():Dynamic;

    @:native('setWindowSize')
    static public function setWindowSize(size:IntVector2):Void;
}
