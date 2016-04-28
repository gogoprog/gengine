package gengine;

import gengine.systems.*;
import gengine.math.*;
import gengine.input.*;
import gengine.resource.*;
import gengine.*;

@:native('gengine')
extern class Gengine
{
    static public function getContext():Dynamic;
    static public function getScene():Dynamic;
    static public function getInput():Input;
    static public function getResourceCache():ResourceCache;
    static public function getRenderer():Dynamic;

    static public function setWindowSize(size:IntVector2):Void;
    static public function setWindowTitle(title:String):Void;

    static public function setGuiFilename(title:String):Void;

    static public function exit():Void;
}
