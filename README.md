# gengine

A game framework that combines Haxe, Ash, HTML5 and Urho3D.

## Features

  * Gameplay code in Haxe (JavaScript support through v8 or embind)
  * Ash framework integrated
  * UI in HTML5 (Chromium Embedded Framework on native platforms)
  * Most Urho3D features
  * HTML5 WebGL target support

## Documentation

[Generated doc pages](http://gogoprog.github.io/gengine/doc/pages/)

## Usage

### Distribution release

#### Requirements

 * [python3](https://www.python.org/downloads/)
 * [haxe](https://haxe.org/download/)

#### Commands

Go to the directory containing the extracted files and start the environment :
    
    cd path/to/extracted/files/
    ./start.sh
    
This will activate the environment and enable the gengine-run command :

    gengine-run [path-to-your-application-code]
    
This will start a local server running your application.

### Development

Activate the gengine environment :

    source path/to/gengine/scripts/activate
  
First time build including Urho3D :

    gengine-build --urho3d [-d] [--html5] [path-to-your-application-code]

Next times build :

    gengine-build [-d] [--html5] [path-to-your-application-code]
    
Build and run on native platforms :
  
    gengine-run [-d] [path-to-your-application-code]

