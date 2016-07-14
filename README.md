# gengine

A game framework that combines Haxe, Ash, HTML5 and Urho3D.

## Features

  * Gameplay code in Haxe (JavaScript support through v8 or embind)
  * Ash framework integrated
  * UI in HTML5 (Chromium Embedded Framework on native platforms)
  * Most Urho3D features
  * HTML5 WebGL target support

## Commands

Activate the gengine environment :

    source path/to/gengine/scripts/activate
  
First time build including Urho3D :

    gengine-build --urho3d [--html5] [path-to-your-application-code]

Next times build :

    gengine-build [--html5] [path-to-your-application-code]
    
Build and run on native platforms :
  
    gengine-run [path-to-your-application-code]

