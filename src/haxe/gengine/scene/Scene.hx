package gengine.scene;

import gengine.Entity;

extern class Scene
{
    public inline function getAsEntity():Entity
    {
        return new Entity(this);
    }
}
