package gengine;

import gengine.systems.*;
import gengine.math.*;
import gengine.input.*;
import gengine.resource.*;
import gengine.core.*;
import gengine.scene.*;
import gengine.graphics.*;
import gengine.audio.*;
import gengine.*;

@:native('gengine')
extern class Gengine
{
    static public function getContext():Context;
    static public function getScene():Scene;
    static public function getInput():Input;
    static public function getResourceCache():ResourceCache;
    static public function getRenderer():Renderer;
    static public function getAudio():Audio;

    static public function getStartupString():String;

    static public function setWindowSize(size:IntVector2):Void;
    static public function setWindowTitle(title:String):Void;

    static public function takeScreenshot(filename:String):Void;
    static public function setGuiFilename(filename:String):Void;

    static public function exit():Void;
}
