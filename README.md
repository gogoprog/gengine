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

The distributed release provides an emscripten build of the gengine.
A local http server is used to run the applications.

#### Requirements

 * python3
 * haxe

#### Commands

Go to the directory containing the extracted files and activate the gengine environment :

    cd path/to/extracted/files/
    ./gengine.sh

This enables the gengine-run and gengine-compile commands :

    gengine-compile [path-to-your-application-code] # To compile your Haxe code
    gengine-run [path-to-your-application-code] # To compile and run the local server

### Development

Activate the gengine environment :

    source path/to/gengine/scripts/activate

First time build including Urho3D :

    gengine-build --urho3d [-d] [--html5] [path-to-your-application-code]

Next times build :

    gengine-build [-d] [--html5] [path-to-your-application-code]

Build and run on native platforms :

    gengine-run [-d] [path-to-your-application-code]
